#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct Info
{
  unsigned long num;
  unsigned long x;
  unsigned long offset;
  unsigned long step;
};

int running = 0;
unsigned long failed = 0;
unsigned long* lookup = 0;
bool waiting = true;

void* isPrime( void* info )
{
  Info* params = (Info*)info;

  unsigned long num = params->num;
  unsigned long x = params->x;
  unsigned long offset = params->offset;
  unsigned long step = params->step;

  unsigned long i = offset;
  if ( i <= 0 )
  {
    lookup = &i;
    i += step;
  }

  while( waiting)
    usleep(1000);

  for ( ; running && i < x; i += step )
    if ( (num % (6 * i - 1)) == 0 || (num % (6 * i + 1)) == 0 )
    {
      failed = i;
      running = 0;

      printf("Failed on: %d\n", i );
      if ( (num % (6 * i + 1)) == 0 )
        printf("%llu / %llu\n", num, (6 * i + 1));
      if ( (num % (6 * i - 1)) == 0 )
        printf("%llu / %llu\n", num, (6 * i - 1));
      return 0;
    }

  if ( failed == 0 )
    running--;
  return 0;
}

int main()
{
  const int NUM_THREADS = 8;
  pthread_t threads[NUM_THREADS];
  Info data[NUM_THREADS];
  int r;

    //Setup my info!
  unsigned long i = 1;
  for ( r = 0; r < 10; r++ )
    i <<= 1;
  for( int t = 0;  t < NUM_THREADS; t++ )
  {
    data[t].num = (6 * i) + 1;
    data[t].x = (i + 1) / 2;
    data[t].offset = t;
    data[t].step = NUM_THREADS;
    running++;

    int rc = pthread_create( &threads[t], NULL, isPrime, (void *)&data[t]);
    if (rc)
    {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      return -1;
    }
  }

  waiting = false;

  while ( running )
  {
    double a = *lookup;
    double b = i;
    printf( "%d  %f%%\n", running, a / b);
    usleep( 1000000 );
  }

  if ( failed != 0 )
    printf("Failed on (0 is success)  %llu\n\n", failed );
  else
    printf("Prime found: %llu -- %llu\n", i, 6 * i + 1 );

  pthread_exit(NULL);
    
  return 0;
}
