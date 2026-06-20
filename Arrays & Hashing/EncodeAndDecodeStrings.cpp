#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& s : strs)
        {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
    vector<string> res;
    int i = 0;

    while(i < s.size())
    {
        int j = i;

        while(s[j] != '#')
            j++;

        int length = stoi(s.substr(i, j - i));

        i = j + 1;

        res.push_back(s.substr(i, length));

        i += length;
    }

    return res;
}
};

// Eficiencia temporal: O(m+n) donde m es la suma de las longitudes de los strings y n es el numero de strings
// Eficiencia espacial: O(m+n) donde m es la suma de las longitudes de los strings y n es el numero de strings