#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for(int i = 0; i < s1.length(); i++) // cuenta las frecuencias
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++) // cuenta las coincidencias
        {
            if(s1Count[i] == s2Count[i])
                matches++;
        }

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++) // recorre s2
        {
            if(matches == 26)
                return true;

            // Anadimos el nuevo caracter que entra en la ventana
            int index = s2[r] - 'a';
            s2Count[index]++;

            // Si ahora las frecuencias coinciden, hemos ganado una coincidencia.
            // Si antes coincidian y al incrementar dejan de coincidir, la perdemos.
            if (s1Count[index] == s2Count[index])
                matches++;
            else if (s1Count[index] + 1 == s2Count[index])
                matches--;


            // Eliminamos el caracter que sale de la ventana
            index = s2[l] - 'a';
            s2Count[index]--;

            // Si tras eliminarlo las frecuencias vuelven a coincidir, recuperamos una coincidencia.
            // Si antes coincidian y al decrementar dejan de coincidir, la perdemos.
            if (s1Count[index] == s2Count[index])
                matches++;
            else if (s1Count[index] - 1 == s2Count[index])
                matches--;

            l++;

        }

        return matches == 26;
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)