#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for(int i = 0; i < s.length(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }

        return countS == countT;
    }
};

// Eficiencia temporal: O(n + m)
// Eficiencia espacial: O(1) (son 26 letras)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};


// Eficiencia temporal: O(n log n + m log m)
// Eficiencia espacial: O(n + m)