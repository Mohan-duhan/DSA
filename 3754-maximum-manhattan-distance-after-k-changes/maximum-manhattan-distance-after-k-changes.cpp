class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int south = 0, north = 0, west = 0, east = 0;
        int Mah_Dis = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'N')
                north++;
            if (ch == 'W')
                west++;
            if (ch == 'S')
                south++;
            if (ch == 'E')
                east++;

            int x = abs(north - south);
            int y = abs(east - west);
            Mah_Dis = x + y;

            int wasted = i + 1 - Mah_Dis;

            int dis = Mah_Dis + min(2 * k, wasted);

            ans = max(dis, ans);
        }
        return ans;
    }
};