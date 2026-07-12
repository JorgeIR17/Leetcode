#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet(s.begin(), s.end());
        int res = 0;
        for(char c : charSet)
        {
            int l = 0, count = 0;
            for(int r = 0; r < s.size(); r++)
            {
                if(s[r] == c)
                    count++;

                while(r - l + 1 - count > k)
                {
                    if(s[l] == c)
                        count--;
                    l++;
                }

                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};

// Eficiencia temporal: O(n * m), donde n es el tamaño de la cadena y m es el número de caracteres distintos en la cadena
// Eficiencia espacial: O(m), donde m es el número de caracteres distintos en la cadena