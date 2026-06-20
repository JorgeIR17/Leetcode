#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(const auto& s : strs) // selecciona cada string
        {
            vector<int> count(26, 0);
            for(char c : s)
            {
                count[c - 'a']++; // cuenta cada letra
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++)
                key += ',' + to_string(count[i]); // Se usa ',' para separar los numeros y evitar colisiones de claves
            res[key].push_back(s); //anade el string al vector que tiene esa frecuencia
        }

        vector<vector<string>> result;

        for(const auto& pair : res)
            result.push_back(pair.second); // anade los vectores con los strings que forman el anagrama
        
        return result;
    }
};

// Eficiencia temporal: O(n * m) donde n es el numero de strings y m es la longitud del string mas largo
// Eficiencia espacial: O(n * m)