#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int l = 0, r = height.size() - 1;
        int lMax = height[l], rMax = height[r];
        int res = 0;
        while(l < r)
        {
            if(lMax < rMax)
            {
                l++;
                lMax = max(height[l], lMax);
                res += lMax - height[l];
            }
            else
            {
                r--;
                rMax = max(height[r], rMax);
                res += rMax - height[r];
            }
        }
        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)