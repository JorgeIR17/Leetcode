#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int res = 0;
        for(int n : numbers)
        {
            if(numbers.find(n - 1) == numbers.end())
            {
                int length = 1;
                while(numbers.find(n + length) != numbers.end())
                    length++;
                if (length > res)
                    res = length;
            }
        }
        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)