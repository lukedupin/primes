#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_pretty( char* buf, long len, long step=6, long offset=0) {
    for ( long i = 0; i < len; i++ )
    {
        if ( i > 0 && i % step == 0 ) {
            printf("|");
        }
        long idx = (i + offset) % len;
        if ( idx < 0 ) idx += len;
        printf("%c", buf[idx]);
    }
    printf("\n");
}

int main( int argc, char** argv)
{
    if ( argc < 2 ) {
        printf("Usage: %s <x>\n", argv[0]);
        return 1;
    }

    long i;
    long hit;
    char c[] = {'.', '+', '-', '*'};

    const long x = atoi(argv[1]);
    const long x_min = 6 * x - 1;
    const long x_max = 6 * x + 1;
    const long len = (x_max * x_min);

    //Setup my buffer
    char* buf[] = {
        new char[len + 1],
        new char[len + 1],
        new char[len + 1],
    };
    memset( buf[0], '0', len+1 );
    memset( buf[1], '0', len+1 );
    memset( buf[2], '0', len+1 );

    printf("X = %d\n", x);
    printf("Len %d\n", len); // Awlays equal to 6^2 * x^2 - 1

    //Check my map
    long o = 0;
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

        /*
        if ( i > 0 && i % 6 == 0 ) {
            o++;
            buf[0][i+o] = buf[1][i+o] = '|';
        }
         */

        buf[0][i+o+1] = buf[1][i+o+1] = 0;
    }

    //Prlong out my info
    printf("X+1 0 -- ");
    print_pretty(buf[0], len, 6, 0);
    printf("X+1 2 -- ");
    print_pretty(buf[0], len, 6, 6*x*x*2);
    printf("X+1 4 -- ");
    print_pretty(buf[0], len, 6, 6*x*x*4);
    printf("Negative ");
    print_pretty(buf[1], len, 6, 0);//-6*x*x*2);
    printf("\n");

    /* Rather complext alogrithm
    //Calculate the pattern
    memset( buf[2], '.', len );
    for ( long i = 0; i < x*2; i++ ) {
        //Left side
        buf[2][6*x*i + 3*x-i-1] = '+';
        buf[2][6*x*i + 3*x+i] = '-';

        //Right side
        buf[2][len - 6*x*i - 3*x-i-1] = '-';
        buf[2][len - 6*x*i - 3*x+i] = '+';
    }

    //From the start, there exists a special pattern
    const long star = 18*x*x - 1;
    buf[2][star] = '*';
    buf[2][star + (6*x - 1)] = '+';
    buf[2][star - (6*x - 1)] = '+';

    //This is the reversed -+ pattern that is optional
    for ( long i = 1; i <= x; i++ ) {
        //Left side
        buf[2][star - 6*x*i+i] = '+';
        buf[2][star - 6*x*i-i] = '-';

        buf[2][star + 6*x*i+i] = '-';
        buf[2][star + 6*x*i-i] = '+';
    }
     */

    //Simple algorithm
    //From the start, there exists a special pattern
    memset( buf[2], '.', len );
    const long star = 18*x*x - 1;
    buf[2][star] = '*'; //This is the center of everything

    //Since everythign flows from the * we just calculate teh sin/cos
    hit = 1;
    for ( long i = 1; hit != 0; i++ ) {
        hit = 0;
        hit |= (star >= x_max*i)? 1: 0;
        hit |= (star >= x_min*i)? 2: 0;

        //Waves out...
        if ( (hit | 1) != 0 ) {
            buf[2][star - x_max*i] = '-';
            buf[2][star + x_max*i] = '-';
        }
        if ( (hit | 2) != 0 ) {
            buf[2][star - x_min*i] = '+';
            buf[2][star + x_min*i] = '+';
        }
    }

    print_pretty(buf[0], len, 6, 6*x*x*4);
    print_pretty(buf[2], len, 6, 0);//-6*x*x*2);

    const long offset = 6*x*x*4;
    for ( long i = 0; i < len; i++ ) {
        if ( i > 0 && i % 6 == 0 ) printf("|");
        const auto check = (buf[0][(i+offset) % len] == buf[2][i])? ' ': 'X';
        printf("%c", check);
        /*
        while ( check == 'X' ) {
            printf("\n%c != %c\n", buf[0][(i+offset) % len], buf[2][i]);
            while(1);
        }
         */
    }
    printf("\n");

    return 0;
    //PRint!
    const long start = 6 * x * x;
    for ( i = 0; i < 6 * x - 1; i++ )
    {
        const long i2 = i * x;
        for ( long j = 3; j >= 1; j--) {
            printf("%c", buf[0][i2*6 + start - j]);
        }
        printf("%c", buf[0][i2*6 + start]);
        for ( long j = 1; j <= 2; j++) {
            printf("%c", buf[0][(i2 * 6 + start + j) % len]);
        }
        printf("\n");
    }


    return 0;
}
