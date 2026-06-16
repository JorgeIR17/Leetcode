#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r)
        {
            while (l < r && !isalnum(s[l]))
                l++;
            while (r > l && !isalnum(s[r]))
                r--;
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)


class Solution2 {
public:
    bool isPalindrome(string s) {
        string n = "";
        for (char c : s)
        {
            if(isalnum(c))
            n += tolower(c);
        }

        return n == string(n.rbegin(), n.rend());
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)