#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

// Eficiencia temporal: O(n log n)
// Eficiencia espacial: O(1)


class Solution2 {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> insertados;
        for(int n : nums)
        {
            if(insertados.count(n))
                return true;
            
            insertados.insert(n);
        }
        return false;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)

class Solution3 {
public:
    bool hasDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)