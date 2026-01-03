# Two Sum

## Problem Link
[LeetCode #1 - Two Sum](https://leetcode.com/problems/two-sum/)

## Difficulty
🟢 Easy

## Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Approach

### Intuition
The brute force approach would be to check every pair of numbers, which takes O(n²) time. We can optimize this by using a hash map to store numbers we've seen and their indices. For each number, we check if its complement (target - current number) exists in the hash map.

### Algorithm
1. Create an empty hash map to store number → index mappings
2. Iterate through the array:
   - Calculate complement = target - current number
   - Check if complement exists in hash map
   - If yes, return [complement_index, current_index]
   - If no, add current number and its index to hash map
3. Return empty array if no solution found (though problem guarantees one solution)

### Complexity Analysis
- **Time Complexity**: O(n)
  - Single pass through the array
  - Hash map lookup and insertion are O(1) on average
  
- **Space Complexity**: O(n)
  - Hash map can store up to n elements in worst case

## Code Walkthrough

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if complement exists
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            
            // Store current number and index
            hash[nums[i]] = i;
        }
        
        return {};
    }
};
```

### Example Trace
**Input**: nums = [2, 7, 11, 15], target = 9

| i | nums[i] | complement | hash | Action |
|---|---------|------------|------|--------|
| 0 | 2 | 7 | {} | Add 2→0 |
| 1 | 7 | 2 | {2→0} | Found! Return [0,1] |

## Alternative Approaches

### Approach 2: Brute Force
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}
```
- **Time**: O(n²) - nested loops
- **Space**: O(1) - no extra space
- **Trade-offs**: Simple but slow for large inputs

### Approach 3: Two Pointers (Only if array can be sorted)
⚠️ **Note**: This doesn't work for this problem because we need to return original indices, and sorting would change them.

## Key Takeaways

### Pattern
- **Hash Map for O(1) Lookup**: When you need to find if a complement/pair exists
- **Single Pass Optimization**: Build the hash map while searching

### Similar Problems
- [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) - Use two pointers
- [3Sum](https://leetcode.com/problems/3sum/) - Extension with three numbers
- [4Sum](https://leetcode.com/problems/4sum/) - Extension with four numbers
- [Two Sum IV - BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) - Tree variation

### Edge Cases to Consider
1. **Minimum size**: Array with exactly 2 elements
2. **Negative numbers**: Works fine with hash map
3. **Duplicates**: Hash map handles by overwriting (but we find answer before that)
4. **Zero**: target = 0, nums = [-1, 1] → works correctly

### Common Mistakes
1. ❌ Using the same element twice: `if (i != j)` check needed in brute force
2. ❌ Returning values instead of indices
3. ❌ Not handling the case where complement equals current number

## Interview Tips

### What to Discuss
1. **Clarify requirements**: 
   - Can we use same element twice? (No)
   - Is array sorted? (No)
   - Multiple solutions? (No, exactly one)

2. **Mention trade-offs**:
   - Hash map: O(n) time, O(n) space
   - Brute force: O(n²) time, O(1) space

3. **Follow-up questions**:
   - What if array is sorted? → Two pointers
   - What if we need all pairs? → Modify to store all solutions
   - What if we can't use extra space? → Brute force only option

### Time to Solve
- **Understanding**: 2 minutes
- **Optimal approach**: 3 minutes
- **Coding**: 5 minutes
- **Testing**: 2 minutes
- **Total**: ~12 minutes

---

**Last Updated**: January 2026
**Solved By**: [@Mohan_0407](https://leetcode.com/u/Mohan_0407/)
