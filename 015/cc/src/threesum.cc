#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    // sort the vector first
    // iterate through every item in the nums vector (not sorted)
    // for each item denoted as nums[i], find two numbers nums[lo] and nums[hi]
    //    such that nums[i] + nums[lo] + nums[high] == 0
    //    if equal, push the triplet to result, note, since nums[i] is smallest, i < lo < hi
    //    this triplet is always unique, plus the triplet is sorted lexicographically in ascending order
    //    if not equal, either nums[lo] is too small or nums[high] is too big, depending on the sum being negative or positive
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 2; i++) {
      if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
          int sum = nums[i] + nums[lo] + nums[hi];
          if (0 == sum) {
            result.push_back(std::vector<int>({nums[i], nums[lo], nums[hi]}));
            while (lo < hi && nums[lo+1] == nums[lo]) lo++;
            while (hi > lo && nums[hi-1] == nums[hi]) hi--;
            lo++;
            hi--;
          }
          else if (sum < 0)
            lo++;
          else // sum > 0
            hi--;
        }
      }
    }

    return result;
  }
};