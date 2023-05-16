#include <stdio.h>

bool isPrime( int x )
{
  for ( int i = 6; i < x; i += 6 )
  {
    if ( (x % (i - 1)) == 0 )
    {
      printf("%d / %d\n", x, i - 1 );
      return false;
    }
    if ( (x % (i + 1)) == 0 )
    {
      printf("%d / %d\n", x, i + 1 );
      return false;
    }
  }

  return true;
}

int main()
{
  printf("%d %d\n", 143, isPrime( 143 ));

  int i = 5;
  while ( true )
  {
    if ( (6 * i - 1) % 23 == 0 &&
         (6 * i + 1) % 25 == 0 )
    {
      printf("%d\n", i );
      return 0;
    }
    i++;
  }
  return 0;
}
