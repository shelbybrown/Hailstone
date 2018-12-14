// CSCI 2530
// Assignment: 3
// Author:     Shelby Brown
// File:       hailstone.cpp
// Tab stops:  ***

// The purpose of this program is to return the
// hailstone sequence from a number that is 
// read from the user. Also return the largest number,
// the length of the sequence, and the number it began with.


#include <cstdio>
#include <algorithm>
using namespace std;

// The function next(n)takes an integer value n and 
// returns the number that follows n in a hailstone sequence. 
// For example: next(7) = 22 and next(22) = 11
// Since there is no number that follows 1 in a hailstone 
// sequence, 'next' requires its parameter n to be greater than 1.

int next(int n)
{
  if(n!= 1)
  {            
    if ((n % 2) == 0 )
    {
      n = n / 2;
    }
    else
    {
      n = 3 * n + 1;
    }
  }

  return n;
}

// The function hailstone takes an integer n and writes 
// the entire hailstone sequence starting at n.
// It takes exactly one parameter of type int and it must have
// a void return-type. It must write the entire sequence on one line,
// with the numbers separated by spaces.

void hailstone(int n)
{
  if(n == 1)
  {
    printf("1");
  } 
  else
  {
    printf("%i ",n);
    hailstone(next(n));
  }
}

// The length function takes an integer n and returns 
// the length of the hailstone sequence starting at n.
// This function does not read or write anything.

int length(int n)
{
  if(n == 1)
  {
    return 1;
  }
  else
  {
    return 1 + length(next(n));
  }

} 

// The largest function takes an integer n and returns
// the largest value in the hailstone sequence starting at n.
// This function does not read or write anything.

int largest(int n)
{
  int s = n;
  if(s == 1)
  {
    return 1;
  }
  else
  {
    return max(largest(next(s)), s);
  }
}

// The longestLength function takes an integer n and
// returns the length of the longest hailstone sequence
// starting at a number from 1 to n.
// This funtion does not read or write anything.

int longestLength(int n)
{

 if (n == 1)
 {
   return 1;
 }
 else 
 {
   return max(length(n), longestLength(n - 1));
 }
}

// The longest funtion takes an integer n and returns
// the start value of the longest hailstone sequence 
// that starts on a value from 1 to n.
// This funtion does not read or write anything.

int longest(int n)
{
  if(length(n) == longestLength(n))
  {
    return n;
  }
  else
  {
    return longest(n-1);
  }
}

int main()
{
  int n;
  printf("What number shall I start with? ");
  scanf("%i",&n);

  printf("The hailstone sequence starting at %i is:\n", n);
  hailstone(n);

  printf("\nThe length of the sequence is: %i\n", length(n));
  
  printf("The largest number in the sequence is %i. \n", largest(n));

  printf("The longest hailstone sequence starting with a number up to %i has length %i. \n",   n, longestLength(n));

  printf("The longest hailstone sequence starting with a number up to %i begins with %i.\n", n, longest(n));

  return 0;
}
