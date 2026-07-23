#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l_row = 0, r_row = m - 1;
        
        
        
        while(l_row <= r_row)
        {
            int avg_row = l_row + (r_row - l_row)/2;
            
            
            if(matrix[avg_row][n-1] < target)
                l_row = avg_row + 1;
            else if(matrix[avg_row][0] > target)
                r_row = avg_row - 1;
            else
            {
                int l = 0, r = n - 1;
                while(l <= r)
                {
                    int avg = l + (r - l)/2;
                    if(matrix[avg_row][avg] < target)
                        l = avg + 1;
                    else if (matrix[avg_row][avg] > target)
                        r = avg - 1;
                    else
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};

// Eficiencia temporal: O(log m + log n) => O(log m*n)
// Eficiencia espacial: O(1)