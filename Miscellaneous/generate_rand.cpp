#include <bits/stdc++.h>
#include <random>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // if you want to generate a number between a and b with uniform distribution
  int a = 1e3, b = 2e5;
  uniform_int_distribution<int> number(a, b);

  int N = number(rng); // this generates a number between a and b;

  // why use this? because if you use rand() function it generates a number
  // between 0 and RAND_MAX RAND_MAX = 31000 something like that, if you a have
  // an interval bigger than RAND_MAX your solution will break USE
  // uniform_int_distribution with rng

  return 0;
}
