class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        unordered_map<int, int> next_greater;
        stack<int> st;

        //yaha map form hoga for greater values
        for (int num : arr) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        //yaha stack se pop nahi hui values ko -1 assign hoga 
        while (!st.empty()) {
            next_greater[st.top()] = -1;
            st.pop();
        }

        //yaha result update hoga 
        vector<int> ans;
        for (int num : nums) {
            ans.push_back(next_greater[num]);
        }
        return ans;
    }
};