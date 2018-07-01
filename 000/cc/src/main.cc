#include <iostream>
#include <cassert>

#include "twosum.cc"

int main() {

  Solution s;
  std::vector<int> v1 {3, 4, 9, 13};
  int t1 = 7;
  std::vector<int> c1 {0,1};

  std::vector<int> r1 = s.twoSum(v1, 7);

  assert(c1 == r1);
  
  return 0;
}