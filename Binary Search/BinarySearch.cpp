#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (r + l) / 2;
        while(l <= r)
        {
            m = l + (r - l) / 2;
            if(nums[m] < target)
                l = m + 1;
            else if (nums[m] > target)
                r = m - 1;
            else
                return m;
        }
        return -1;
    }
};

// Eficiencia temporal: O(log n)
// Eficiencia espacial: O(1)