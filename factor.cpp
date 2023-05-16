#include <stdlib.h>
#include <stdio.h>

int main( int argc, char** argv )
{
  int num = atoi( argv[1]);
  int n = num;

  for ( int i = 1; i < num / 6 && n > 1; i++ )
  {
    int x = 6 * i;
    if ( n % (x - 1) == 0 )
    {
      //n /= (x - 1);
      printf("-%d\n", i );
    }
    if ( n % (x + 1) == 0 )
    {
      //n /= (x + 1);
      printf("+%d\n", i );
    }
  }

  return 0;
}
