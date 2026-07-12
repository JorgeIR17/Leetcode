#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> closed = 
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s)
        {
            if(closed.count(c)) // comprueba si el parentesis es de cierre
            {
                if(!stack.empty() && stack.top() == closed[c])
                    stack.pop(); // si es de cierre y en el tope de la pila esta el de apertura se elimina
                else
                    return false;
            }
            else
                stack.push(c); // si es de apertura se anade
        }
        return stack.empty();
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)