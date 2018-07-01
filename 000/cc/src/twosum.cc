#include <vector>
#include <unordered_map>


class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        bool found = false;
        for (auto i = 0; i < nums.size() - 1; i++) {
            for (auto j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target) {
                    result.push_back(i);
                    result.push_back(j);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        return result;
    }
};

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::vector<int> result;
    bool found = false;
    std::unordered_map<int, int> targetSet;
    for (auto i = 0; i < nums.size(); i++) {
      if (targetSet.find(nums[i]) == targetSet.end()) { // not found
        targetSet[target - nums[i]] = i;
      }
      else {
        result.push_back(targetSet[nums[i]]);
        result.push_back(i);
      }
    }
    return result;
  }
};