# Contributing to DSA_LC

First off, thank you for considering contributing to this repository! 🎉

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
- [Contribution Guidelines](#contribution-guidelines)
- [Solution Standards](#solution-standards)
- [Commit Message Guidelines](#commit-message-guidelines)

## 🤝 Code of Conduct

This project adheres to a code of conduct. By participating, you are expected to uphold this code:
- Be respectful and inclusive
- Accept constructive criticism gracefully
- Focus on what's best for the community
- Show empathy towards others

## 🎯 How Can I Contribute?

### 1. Adding New Solutions

If you've solved a problem that's not in the repository:

1. **Fork the repository**
2. **Create a new branch**: `git checkout -b add-problem-name`
3. **Follow the folder structure**: `problem-number-problem-name/`
4. **Add your solution** with proper documentation
5. **Submit a Pull Request**

### 2. Improving Existing Solutions

Found a better approach or optimization?

1. **Fork the repository**
2. **Create a branch**: `git checkout -b improve-problem-name`
3. **Add your improved solution** as an alternative approach
4. **Document the improvements** (time/space complexity)
5. **Submit a Pull Request**

### 3. Fixing Bugs

Found an error in a solution?

1. **Open an issue** describing the bug
2. **Fork and fix** the issue
3. **Submit a Pull Request** referencing the issue

### 4. Documentation

Help improve documentation:
- Fix typos or grammatical errors
- Improve explanations
- Add missing complexity analysis
- Enhance code comments

## 📝 Contribution Guidelines

### Folder Structure

Each problem should follow this structure:

```
problem-number-problem-name/
├── README.md           # Problem statement (auto-generated from LeetCode)
├── solution.cpp        # Primary C++ solution
├── solution.js         # JavaScript solution (optional)
├── solution-alt.cpp    # Alternative approach (if applicable)
└── NOTES.md           # Detailed explanation
```

### File Naming Convention

- Use lowercase with hyphens: `two-sum.cpp`
- For alternatives: `two-sum-alt.cpp` or `two-sum-optimized.cpp`
- Problem folders: `1-two-sum/`, `100-same-tree/`

## 🎨 Solution Standards

### Code Quality

1. **Clean and Readable Code**
   ```cpp
   // Good
   int findMax(vector<int>& nums) {
       int maxVal = INT_MIN;
       for (int num : nums) {
           maxVal = max(maxVal, num);
       }
       return maxVal;
   }
   
   // Avoid
   int f(vector<int>&n){int m=INT_MIN;for(int i=0;i<n.size();i++)m=max(m,n[i]);return m;}
   ```

2. **Meaningful Variable Names**
   - Use descriptive names: `maxProfit`, `leftPointer`, `nodeCount`
   - Avoid single letters except for loops: `i`, `j`, `k`

3. **Comments and Documentation**
   ```cpp
   /*
    * Problem: Two Sum
    * Difficulty: Easy
    * 
    * Approach: Hash Map
    * - Store each number and its index in a hash map
    * - For each number, check if complement exists
    * - Return indices when found
    * 
    * Time Complexity: O(n) - single pass through array
    * Space Complexity: O(n) - hash map storage
    */
   ```

### NOTES.md Template

Create a `NOTES.md` file for each solution:

```markdown
# Problem Name

## Problem Link
[LeetCode Problem](https://leetcode.com/problems/problem-name/)

## Difficulty
Easy/Medium/Hard

## Approach

### Intuition
[Explain the key insight that leads to the solution]

### Algorithm
1. Step 1
2. Step 2
3. Step 3

### Complexity Analysis
- **Time Complexity**: O(?) - [Explanation]
- **Space Complexity**: O(?) - [Explanation]

## Alternative Approaches

### Approach 2: [Name]
- **Time**: O(?)
- **Space**: O(?)
- **Trade-offs**: [When to use this approach]

## Key Takeaways
- Pattern: [e.g., Two Pointers, Sliding Window]
- Similar Problems: [List related problems]
- Edge Cases: [Important edge cases to consider]

## Code Walkthrough

[Optional: Step-by-step explanation with examples]
```

### Code Style

#### C++ Standards
```cpp
class Solution {
public:
    // Use meaningful function names
    vector<int> twoSum(vector<int>& nums, int target) {
        // Use unordered_map for O(1) lookup
        unordered_map<int, int> numToIndex;
        
        // Clear loop logic
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if complement exists
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            
            // Store current number
            numToIndex[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};
```

#### JavaScript Standards
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const numToIndex = new Map();
    
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        
        if (numToIndex.has(complement)) {
            return [numToIndex.get(complement), i];
        }
        
        numToIndex.set(nums[i], i);
    }
    
    return [];
};
```

## 📬 Commit Message Guidelines

Follow conventional commits format:

### Format
```
<type>(<scope>): <subject>

<body>

<footer>
```

### Types
- `feat`: New solution or feature
- `fix`: Bug fix in existing solution
- `docs`: Documentation changes
- `style`: Code style changes (formatting)
- `refactor`: Code refactoring
- `perf`: Performance improvements
- `test`: Adding tests
- `chore`: Maintenance tasks

### Examples
```bash
feat(arrays): add two sum solution

- Implemented hash map approach
- Time: O(n), Space: O(n)
- Added detailed explanation in NOTES.md

---

fix(trees): correct binary tree traversal logic

Fixed off-by-one error in level order traversal

Closes #42

---

docs(readme): update progress statistics

Updated problem count and completion percentages
```

## 🔍 Pull Request Process

1. **Update Documentation**
   - Update README.md if adding new topics
   - Ensure NOTES.md is complete
   - Add comments to complex code sections

2. **Test Your Solution**
   - Verify solution passes all LeetCode test cases
   - Test edge cases
   - Check for memory leaks (C++)

3. **PR Description Template**
   ```markdown
   ## Description
   [Brief description of changes]
   
   ## Problem Details
   - Problem Number: #123
   - Difficulty: Medium
   - Topic: Dynamic Programming
   
   ## Approach
   [Explain your approach]
   
   ## Complexity
   - Time: O(?)
   - Space: O(?)
   
   ## Checklist
   - [ ] Code follows style guidelines
   - [ ] Added NOTES.md with explanation
   - [ ] Solution passes all test cases
   - [ ] Updated README if necessary
   ```

4. **Review Process**
   - Maintainers will review within 48 hours
   - Address feedback promptly
   - Be open to suggestions

## 🎓 Learning Resources

If you're new to contributing:
- [First Contributions Guide](https://github.com/firstcontributions/first-contributions)
- [How to Write a Git Commit Message](https://chris.beams.io/posts/git-commit/)
- [GitHub Flow](https://guides.github.com/introduction/flow/)

## 💬 Questions?

Feel free to:
- Open an issue for questions
- Reach out on [LinkedIn](https://linkedin.com/in/duhanmohan)
- Check existing issues and PRs

## 🙏 Recognition

Contributors will be:
- Listed in the README
- Credited in commit history
- Appreciated in release notes

---

Thank you for contributing! Your efforts help make this a valuable resource for the community. 🚀
