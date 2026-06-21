#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int beg = 0;
        int end = numbers.size() - 1;
        while(numbers[beg] + numbers[end] != target && beg < end)
        {
            if(numbers[beg] + numbers[end] < target)
                beg++;
            if(numbers[beg] + numbers[end] > target)
                end--;
        }
        return vector <int> {beg+1, end+1}; // Suma 1 para indicar el indice
        
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)