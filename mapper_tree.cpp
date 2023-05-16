#include <stdio.h>

/*
 
   Everything centers around x * 6. +, - are on either side for first step after a *. * is the center, no hit is the other side.
   The pattern steps are always the same, I'm guessing there is 6^2 step types

   This will print the mapper format, but in a tree structure around the x * 6 steps logic

/*
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
*/

int main()
{
  int i;
  int hit;
  char c[] = {'.', '+', '-', '*'};

  const int x = 1;
  const int x_min = 6 * x - 1;
  const int x_max = 6 * x + 1;

    //Setup my buffer
  char* buf[2];
  buf[0] = new char[(x_max * x_min + x) + 1];
  buf[1] = new char[(x_max * x_min + x) + 1];

    //Check my map
  for ( i = 0; i <= (x_max * x_min + x); i++ )
  {
    hit = 0;
    if ( (6 * i - 1) % x_min == 0 ) hit |= 1;
    if ( (6 * i - 1) % x_max == 0 ) hit |= 2;
    buf[0][i] = c[hit];

    hit = 0;
    if ( (6 * i + 1) % x_min == 0 ) hit |= 1;
    if ( (6 * i + 1) % x_max == 0 ) hit |= 2;
    buf[1][i] = c[hit];
  }

    //Print out my info
  for ( int r = 0; r < 2; r++ )
  {
    for ( i = 0; i <= (x_max * x_min + x); i++ )
      printf("%c", buf[r][i]);
    printf("\n");
  }
    
  return 0;
}
