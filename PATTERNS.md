# 🎯 LeetCode Patterns Guide

A comprehensive guide to common patterns and techniques for solving LeetCode problems efficiently.

## 📚 Table of Contents

1. [Two Pointers](#1-two-pointers)
2. [Sliding Window](#2-sliding-window)
3. [Fast & Slow Pointers](#3-fast--slow-pointers)
4. [Binary Search](#4-binary-search)
5. [Depth-First Search (DFS)](#5-depth-first-search-dfs)
6. [Breadth-First Search (BFS)](#6-breadth-first-search-bfs)
7. [Dynamic Programming](#7-dynamic-programming)
8. [Backtracking](#8-backtracking)
9. [Greedy](#9-greedy)
10. [Hash Maps & Sets](#10-hash-maps--sets)
11. [Heap / Priority Queue](#11-heap--priority-queue)
12. [Union Find](#12-union-find)
13. [Topological Sort](#13-topological-sort)
14. [Bit Manipulation](#14-bit-manipulation)

---

## 1. Two Pointers

### When to Use
- Array/string problems requiring comparison or search
- Finding pairs with specific properties
- Removing duplicates
- Reversing or rearranging elements

### Common Variations
1. **Opposite Direction** (start and end)
2. **Same Direction** (slow and fast)
3. **Multiple Arrays** (merge operations)

### Template
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // Process and move pointers
        left++;
    } else {
        right--;
    }
}
```

### Example Problems
- Two Sum II (sorted array)
- Container With Most Water
- Remove Duplicates from Sorted Array
- Valid Palindrome
- 3Sum

### Time Complexity
- Usually O(n) or O(n²) for nested loops

---

## 2. Sliding Window

### When to Use
- Subarray/substring problems
- Finding max/min in contiguous elements
- Problems with "window" of fixed or variable size

### Types
1. **Fixed Size Window**
2. **Variable Size Window**

### Template - Variable Size
```cpp
int left = 0, maxLen = 0;
for (int right = 0; right < n; right++) {
    // Add element to window
    window.add(arr[right]);
    
    // Shrink window if invalid
    while (!isValid(window)) {
        window.remove(arr[left]);
        left++;
    }
    
    // Update result
    maxLen = max(maxLen, right - left + 1);
}
```

### Example Problems
- Maximum Sum Subarray of Size K
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Longest Repeating Character Replacement

### Time Complexity
- O(n) - each element visited at most twice

---

## 3. Fast & Slow Pointers

### When to Use
- Linked list cycle detection
- Finding middle element
- Detecting patterns in sequences

### Template
```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    
    if (slow == fast) {
        // Cycle detected
        return true;
    }
}
return false;
```

### Example Problems
- Linked List Cycle
- Find Middle of Linked List
- Happy Number
- Palindrome Linked List

### Time Complexity
- O(n) with O(1) space

---

## 4. Binary Search

### When to Use
- Sorted arrays
- Finding target or insertion position
- Optimization problems (minimize/maximize)

### Template
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return -1; // Not found
```

### Variations
1. **Find Exact Match**
2. **Find First/Last Occurrence**
3. **Find Insertion Position**
4. **Search in Rotated Array**

### Example Problems
- Binary Search
- Search in Rotated Sorted Array
- Find First and Last Position
- Koko Eating Bananas

### Time Complexity
- O(log n)

---

## 5. Depth-First Search (DFS)

### When to Use
- Tree/graph traversal
- Path finding
- Connected components
- Exploring all possibilities

### Template - Recursive
```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    
    // Process current node
    process(node);
    
    // Recurse on children
    dfs(node->left);
    dfs(node->right);
}
```

### Template - Iterative
```cpp
stack<TreeNode*> st;
st.push(root);

while (!st.empty()) {
    TreeNode* node = st.top();
    st.pop();
    
    process(node);
    
    if (node->right) st.push(node->right);
    if (node->left) st.push(node->left);
}
```

### Example Problems
- Binary Tree Inorder Traversal
- Number of Islands
- Path Sum
- Clone Graph

### Time Complexity
- O(V + E) for graphs
- O(n) for trees

---

## 6. Breadth-First Search (BFS)

### When to Use
- Level-order traversal
- Shortest path in unweighted graphs
- Finding nearest/closest elements

### Template
```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int levelSize = q.size();
    
    for (int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        
        process(node);
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

### Example Problems
- Binary Tree Level Order Traversal
- Rotting Oranges
- Word Ladder
- Shortest Path in Binary Matrix

### Time Complexity
- O(V + E) for graphs
- O(n) for trees

---

## 7. Dynamic Programming

### When to Use
- Optimization problems (max/min)
- Counting problems
- Problems with overlapping subproblems
- Problems with optimal substructure

### Approach
1. **Define state** (what does dp[i] represent?)
2. **Find recurrence relation**
3. **Initialize base cases**
4. **Determine iteration order**
5. **Return final answer**

### Template - 1D DP
```cpp
vector<int> dp(n + 1);
dp[0] = base_case;

for (int i = 1; i <= n; i++) {
    dp[i] = // recurrence relation
}

return dp[n];
```

### Template - 2D DP
```cpp
vector<vector<int>> dp(m + 1, vector<int>(n + 1));
// Initialize base cases

for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        dp[i][j] = // recurrence relation
    }
}

return dp[m][n];
```

### Common Patterns
1. **Fibonacci-style** (climbing stairs)
2. **Knapsack** (0/1, unbounded)
3. **Subsequence** (LCS, LIS)
4. **Grid paths**
5. **String matching**

### Example Problems
- Climbing Stairs
- House Robber
- Coin Change
- Longest Common Subsequence
- Edit Distance

### Time Complexity
- Usually O(n) to O(n³) depending on dimensions

---

## 8. Backtracking

### When to Use
- Generate all combinations/permutations
- Constraint satisfaction problems
- Exploring all possible solutions

### Template
```cpp
void backtrack(vector<int>& path, /* other params */) {
    // Base case
    if (isComplete(path)) {
        result.push_back(path);
        return;
    }
    
    // Try all choices
    for (int choice : choices) {
        // Make choice
        path.push_back(choice);
        
        // Recurse
        backtrack(path, /* updated params */);
        
        // Undo choice (backtrack)
        path.pop_back();
    }
}
```

### Example Problems
- Permutations
- Combinations
- Subsets
- N-Queens
- Sudoku Solver

### Time Complexity
- Often exponential: O(2ⁿ) or O(n!)

---

## 9. Greedy

### When to Use
- Optimization problems where local optimum leads to global optimum
- Scheduling problems
- Interval problems

### Key Insight
Make the locally optimal choice at each step

### Template
```cpp
sort(items.begin(), items.end(), comparator);

for (auto& item : items) {
    if (canTake(item)) {
        take(item);
    }
}
```

### Example Problems
- Jump Game
- Gas Station
- Meeting Rooms II
- Partition Labels

### Time Complexity
- Usually O(n log n) due to sorting

---

## 10. Hash Maps & Sets

### When to Use
- Fast lookups (O(1))
- Counting frequencies
- Detecting duplicates
- Storing seen elements

### Template
```cpp
unordered_map<int, int> freq;
for (int num : nums) {
    freq[num]++;
}

// Check existence
if (freq.find(key) != freq.end()) {
    // Key exists
}
```

### Example Problems
- Two Sum
- Group Anagrams
- Top K Frequent Elements
- Longest Consecutive Sequence

### Time Complexity
- O(1) average for insert/lookup
- O(n) worst case

---

## 11. Heap / Priority Queue

### When to Use
- Finding kth largest/smallest
- Maintaining sorted order dynamically
- Merge k sorted lists

### Template
```cpp
// Max heap
priority_queue<int> maxHeap;

// Min heap
priority_queue<int, vector<int>, greater<int>> minHeap;

maxHeap.push(val);
int top = maxHeap.top();
maxHeap.pop();
```

### Example Problems
- Kth Largest Element
- Top K Frequent Elements
- Merge K Sorted Lists
- Find Median from Data Stream

### Time Complexity
- Insert: O(log n)
- Extract: O(log n)
- Peek: O(1)

---

## 12. Union Find

### When to Use
- Connected components
- Cycle detection in undirected graphs
- Dynamic connectivity

### Template
```cpp
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        // Union by rank
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};
```

### Example Problems
- Number of Connected Components
- Redundant Connection
- Accounts Merge

### Time Complexity
- Nearly O(1) with path compression and union by rank

---

## 13. Topological Sort

### When to Use
- Directed Acyclic Graphs (DAG)
- Task scheduling with dependencies
- Course prerequisites

### Template - Kahn's Algorithm (BFS)
```cpp
vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);
    
    // Build graph and indegree
    for (auto& e : edges) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : graph[node]) {
            if (--indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result.size() == n ? result : vector<int>{};
}
```

### Example Problems
- Course Schedule
- Course Schedule II
- Alien Dictionary

### Time Complexity
- O(V + E)

---

## 14. Bit Manipulation

### When to Use
- Space optimization
- Fast arithmetic operations
- Set operations

### Common Operations
```cpp
// Check if bit is set
bool isSet = (num & (1 << i)) != 0;

// Set bit
num |= (1 << i);

// Clear bit
num &= ~(1 << i);

// Toggle bit
num ^= (1 << i);

// Count set bits
int count = __builtin_popcount(num);

// Check if power of 2
bool isPowerOf2 = (num & (num - 1)) == 0;
```

### Example Problems
- Single Number
- Number of 1 Bits
- Reverse Bits
- Power of Two

### Time Complexity
- O(1) for most operations

---

## 🎯 Pattern Recognition Tips

### How to Identify Patterns

1. **Read the problem carefully**
   - What is being asked?
   - What are the constraints?

2. **Look for keywords**
   - "Subarray" → Sliding Window
   - "Sorted" → Binary Search
   - "All combinations" → Backtracking
   - "Shortest path" → BFS
   - "Connected" → Union Find

3. **Analyze constraints**
   - Small n (≤20) → Backtracking, Bit Manipulation
   - Medium n (≤10⁵) → O(n) or O(n log n)
   - Large n (≤10⁶) → O(n) only

4. **Consider data structure**
   - Array → Two Pointers, Sliding Window
   - Tree → DFS, BFS
   - Graph → DFS, BFS, Union Find
   - String → DP, Sliding Window

---

## 📊 Complexity Cheat Sheet

| Pattern | Time | Space | When to Use |
|---------|------|-------|-------------|
| Two Pointers | O(n) | O(1) | Sorted arrays, pairs |
| Sliding Window | O(n) | O(k) | Subarrays, substrings |
| Binary Search | O(log n) | O(1) | Sorted data |
| DFS | O(V+E) | O(h) | Tree/graph traversal |
| BFS | O(V+E) | O(w) | Shortest path |
| DP | O(n²) | O(n) | Optimization |
| Backtracking | O(2ⁿ) | O(n) | All solutions |
| Heap | O(n log k) | O(k) | Top K elements |

---

## 🚀 Practice Strategy

1. **Master one pattern at a time**
2. **Solve 5-10 problems per pattern**
3. **Identify pattern before coding**
4. **Time yourself**
5. **Review and optimize**

---

Happy Pattern Hunting! 🎯
