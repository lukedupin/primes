# primes

Interesting findings.

Everything repeats at an interval of either

```math
Length = 
6^2 * x^2 or
(6*x - 1) * (6*x + 1) + 1
```

```Math
+-1 will always overlap on the 6x-1 line at: 6*x^2
+-1 will always overlap on the 6x+1 line at: Length - 6*x^2
In this way, interactions of 6x+1 are analogous SIN and COS.
SIN can become COS by shifting it by 90degrees or 6*x^2*2, but this works by 120 degrees
  From X-1 to X+1, Subtract 6*x^2*2
  From X+1 to X-1, Add 6*x^2*2
```

From the +-1 overlap, the center of expanding +- interactions is always 6*x interval

The expansion of overlap increases by 1 step in both positive and negative directions: +.- then +...- then +.....-
There is a point where The +.X.- will be touching another plus. The feature is always +.x.-+....+- and then reverses.

The gap between -+ and then next +- is always 6*(x-1)+4 or 6x-2

The 6x+1 and -1 always have an interaction of .+ and .- as the start and the opposite at the end - and +. The gap between these is x.

### There exists 6 rotations

```
Rotations are only at the value of: 
6*x^2 *1
6*x^2 *2 # shift form 6x-1 to 6x+1
6*x^2 *3
6*x^2 *4 # Centers the alignment, always starts with +- and ends with -+. * in the middle
6*x^2 *5
6*x^2 *6

```

### Centered observations
```
Always starts with +- then ends with -+
Everything works in pairs, so its not centered.

# Correctness on this works for 2*x cycles. X=2 iter is valid from 0 to 3
The value to the first + is (6*x*iter + 3*x - iter - 1)
The value to the first - is (6*x*iter + 3*x + iter + 0)

The * will always exist at 6^2*x^2/2 or 18*x^2
The * beings its own pattern. It's always surround by +'s
the +'s are 6*x-1 and -(6*x-1)
After the first set of +'s, a pattern of -+ exists at the rate of...
```