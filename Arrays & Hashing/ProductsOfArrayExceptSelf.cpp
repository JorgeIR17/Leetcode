#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocount = 0;
        int prod = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zerocount++;
            else
                prod *= nums[i]; // Hay que descartar los ceros para que no afecten el producto
            if(zerocount > 1)
                return vector<int>(nums.size(), 0);
        }

        vector<int> res;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                res.push_back(prod);
            else
                if(zerocount > 0) // Si existe un cero en el array, todos los elementos excepto el correspondiente a ese cero deben ser cero
                    res.push_back(0);
                else
                    res.push_back(prod / nums[i]);
        }

        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)