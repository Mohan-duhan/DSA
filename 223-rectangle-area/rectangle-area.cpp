class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        // case 1 : if not overlapping toh return kar do dono rectangles ke area
        // ka sum.
        /* case 2 : if overlapping toh sum me se subtract kardo overlapping
           rectangle ka area so that wo double na ho jaye.*/

        int orgArea_rec1 = (ax2 - ax1) * (ay2 - ay1);
        int orgArea_rec2 = (bx2 - bx1) * (by2 - by1);

        int res_Area1 = orgArea_rec1 + orgArea_rec2;

        int overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));

        int overlap_Area = overlapWidth * overlapHeight;

        return res_Area1 - overlap_Area;
    }
};