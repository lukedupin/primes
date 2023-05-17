#include <stdio.h>

/*
 
   Everything centers around x * 6. +, - are on either side for first step after a *. * is the center, no hit is the other side.
   The pattern steps are always the same, I'm guessing there is 6^2 step types

   This will print the mapper format, but in a tree structure around the x * 6 steps logic
*/

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

    const int x = 3;
    const int x_min = 6 * x - 1;
    const int x_max = 6 * x + 1;
    const int len = x_max * x_min;

    //Setup my buffer
    char* buf[] = {
        new char[len + 1+100],
        new char[len + 1+100],
    };
    buf[0][len] = buf[1][len] = 0;

    printf("Len %d\n", len); // Awlays equal to 6^2 * x^2 - 1

    //Check my map
    int o = 0;
    for ( i = 0; i < len; i++ )
    {
        hit = 0;
        if ( (6 * i - 1) % x_min == 0 ) hit |= 1;
        if ( (6 * i - 1) % x_max == 0 ) hit |= 2;
        buf[0][i+o] = c[hit];
        if ( hit == 3 ) {
            //Always hits at i^2 * 6
            printf("X-1 double => %d\n", i);
        }

        hit = 0;
        if ( (6 * i + 1) % x_min == 0 ) hit |= 1;
        if ( (6 * i + 1) % x_max == 0 ) hit |= 2;
        buf[1][i+o] = c[hit];
        if ( hit == 3 ) {
            //Always = len - i^2 * 6
            printf("X+1 double => %d\n", i);
        }

        if ( false && i > 0 && i % 6 == 0 ) {
            o++;
            buf[0][i+o] = buf[1][i+o] = '|';
        }

        buf[0][i+o+1] = buf[1][i+o+1] = 0;
    }

    //Print out my info
    printf("%s\n", buf[0]);
    printf("%s\n", buf[1]);

    //PRint!
    const int start = 6 * x * x;
    for ( i = 0; i < 6 * x - 1; i++ )
    {
        const int i2 = i * x;
        for ( int j = 3; j >= 1; j--) {
            printf("%c", buf[0][i2*6 + start - j]);
        }
        printf("%c", buf[0][i2*6 + start]);
        for ( int j = 1; j <= 2; j++) {
            printf("%c", buf[0][(i2 * 6 + start + j) % len]);
        }
        printf("\n");
    }


    return 0;
}
