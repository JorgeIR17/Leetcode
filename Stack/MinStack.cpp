#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        mainstack.push(val);
        if(!minstack.empty())
            val = min(val, minstack.top()); // si ya existe un minimo, se comparan para mantener el minimo en el tope de la pila
            // El minimo se repetira tantas veces como valores superiores se anadan posteriomente, por lo que siempre estara en vlor minimo en minstack
        
        minstack.push(val);
    }
    
    void pop() {
        mainstack.pop();
        minstack.pop();
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
private:
    stack<int> mainstack;
    stack<int> minstack;
};

// Eficiencia temporal: O(1) para todas las operaciones
// Eficiencia espacial: O(n)