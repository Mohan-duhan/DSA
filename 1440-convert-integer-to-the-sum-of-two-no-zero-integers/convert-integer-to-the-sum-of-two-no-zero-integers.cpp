class Solution {
public:

    bool checkZero(int num){
        string str = to_string(num);

        for(int i = 0;i<str.length(); i++){
            char ch = str[i];
            if(ch == '0')return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 0;i<n;i++){
            int A = i;
            int B = n-i;

            if(checkZero(A) && checkZero(B)){
                return {A,B};
            }
        }
        return {};
    }
};