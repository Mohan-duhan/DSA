class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> grid;
        vector<int> ans;
        for(int i =0 ;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                grid[i+j].push_back(mat[i][j]);
            }
        }   

        bool flip = true;
        for(auto& it: grid){
            vector<int> res = it.second;
            
            if(flip){
                reverse(res.begin() , res.end());
            }

            for(int &num : res){
                ans.push_back(num);
            }
            flip = !flip;
        }
        return ans;
    }
};