#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;
        int l = 0, res = 0;
        for(int r = 0; r < s.size(); r++)
        {
            while(letters.find(s[r]) != letters.end())
            {
                letters.erase(s[l]);
                l++;
            }

            letters.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(m) donde m es la cantidad de caracteres distintos del string