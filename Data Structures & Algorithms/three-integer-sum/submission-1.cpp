#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;
        
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Fix the first number
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the smallest number is > 0, no triplet can sum to 0
            if (nums[i] > 0) break;
            
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Two pointers for the remaining two elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                if (current_sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (current_sum < 0) {
                    left++; // Need a larger number
                } else {
                    right--; // Need a smaller number
                }
            }
        }
        
        return result;
    }
};