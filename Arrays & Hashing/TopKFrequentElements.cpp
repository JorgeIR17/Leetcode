#include <vector>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int c : nums)
        count[c]++; // cuenta las repeticiones de cada numero

        priority_queue<pair<int, int>> heap;

        for(auto& p : count)
            heap.push({p.second, p.first}); // Ordena por repeticiones del numero
            if(heap.size() > k)
                heap.pop(); // elimina los numeros menos repetidos

        vector<int> res;

        while(k--)
        {
            res.push_back(heap.top().second); // inserta el numero mas repetido en el vector
            heap.pop();
        }

        return res;
    }
};

// Eficiencia temporal: O(n log k)
// Eficiencia espacial: O(n + k)

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int c : nums)
        count[c]++; // cuenta las repeticiones de cada numero
        vector<vector<int>> freq(nums.size() + 1);
        
        for(const auto& entry : count)
            freq[entry.second].push_back(entry.first);

        vector<int> res;
        for(int i = freq.size() - 1; i > 0; i--)
        {
            for(int m : freq[i])
            {
                res.push_back(m);
                if(res.size() == k)
                    return res;
            }
        }

        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n + k)