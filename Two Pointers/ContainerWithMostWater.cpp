#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int beg = 0, end = heights.size() - 1, res = 0, area;
        while(beg < end)
        {
            area = (end - beg) * min(heights[beg], heights[end]);
            if(area > res)
                res = area;
            if(heights[beg] <= heights[end])
                beg++;
            else
                end--;
        }
        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)
