#include <string>
#include <vector>   
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op1, op2;
        stack<int> s;
        for(const string& c : tokens)
        {
            if(c == "+")
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                s.push(op1 + op2);
            }
            else if(c == "-")
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                s.push(op1 - op2);
            } 
            else if(c == "*")
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                s.push(op1 * op2);
            } 
            else if(c == "/")
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                s.push(op1 / op2);
            }
            else
            {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(n)