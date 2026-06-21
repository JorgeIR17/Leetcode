#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // Evitar duplicados
                continue;
            int j = i + 1; // Al ordenar el vector solo miramos a la derecha
            int k = size - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else  //if(sum == 0)
                {
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return res;
    }
};


// Eficiencia temporal: O(n^2)
// Eficiencia espacial: O(1)