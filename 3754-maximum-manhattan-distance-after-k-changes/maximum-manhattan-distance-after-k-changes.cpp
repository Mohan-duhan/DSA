class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int south = 0, north = 0, west = 0, east = 0;
        int MD = 0;
        int ans = 0;

        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(ch == 'N') north++;
            if(ch == 'W') west++;
            if(ch == 'S') south++;
            if(ch == 'E') east++;

        int x = abs(north - south);
        int y = abs(east - west);
        MD = x + y;

        int dis = MD + min(2 * k, i + 1 - MD);

        ans = max(dis,ans);
        }
        return ans;
    }
};