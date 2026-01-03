/*
 * Problem: Two Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Approach: Hash Map (One Pass)
 * - Use hash map to store numbers we've seen and their indices
 * - For each number, check if its complement (target - num) exists
 * - If complement found, return both indices
 * - Otherwise, add current number to hash map
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(n) - hash map storage
 * 
 * Pattern: Hash Map for O(1) lookup
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Hash map to store: number -> index
        unordered_map<int, int> hash;
        
        // Iterate through array
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate what number we need to reach target
            int complement = target - nums[i];
            
            // Check if complement exists in hash map
            if (hash.find(complement) != hash.end()) {
                // Found the pair! Return indices
                return {hash[complement], i};
            }
            
            // Store current number and its index for future lookups
            hash[nums[i]] = i;
        }
        
        // No solution found (problem guarantees one exists)
        return {};
    }
};
