#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> res(temperatures.size(), 0);
        stack<pair<int ,int>> s; // temp, index
        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!s.empty() && temperatures[i] > s.top().first)
            {
                auto pair = s.top(); 
                s.pop();
                res[pair.second] = i - pair.second;
            }
            s.push({temperatures[i], i});
        }
        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)