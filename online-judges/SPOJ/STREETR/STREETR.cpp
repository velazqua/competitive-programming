/* Start: October 28, 2011 @ 10:55PM
   End  : October 28, 2011 @ 11:43PM (Wrong Answer)
*/
#include <iostream>
#include <deque>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

LL GCD( LL a, LL b )
{
  LL t;
  while( b != 0 )
  {
    t = b;
    b = a%b;
    a = t;
  }
  return a;
} 

int main ()
{
  int N;
  LL x;
  scanf( "%d\n", &N );
  deque<LL> diffs, nums;
  LL lastNum = 0LL, lastGCD = 0LL;
  for( int i=0; i<N; ++i )
  {
     scanf( "%lld\n", &x );
     nums.push_back( x );
  } 
  sort( nums.begin(), nums.end() );
  for( int i=0; i<N; ++i )
  {
     diffs.push_back( nums[i]-lastNum );
     //cout << x << " " << lastNum << " " << x-lastNum << endl;
     if( nums[i] == 1LL || lastGCD == 1LL)
     {
       lastNum = nums[i];
       continue;
     }
     lastGCD = GCD( lastGCD, nums[i]-lastNum );
     lastNum = nums[i];
  } 
  
  int total = 0;
  diffs.pop_front();
  for( int i=0; i<N-1; ++i )
  {
    total += diffs[i]/lastGCD - 1LL;
  }
  cout << total << endl;
}

