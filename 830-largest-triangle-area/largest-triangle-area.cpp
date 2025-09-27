class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];

                    double a = hypot(x2 - x3, y2 - y3);
                    double b = hypot(x1 - x3, y1 - y3);
                    double c = hypot(x1 - x2, y1 - y2);

                    double s = (a + b + c) / 2.0;

                    double area = sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));

                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
