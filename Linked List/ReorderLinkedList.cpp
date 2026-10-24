struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Al final del bucle, fast se encuentra al final y slow a la mitad

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = slow->next;
        while(second != nullptr)
        {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // prev guarda la cabeza de la lista invertida, y second, el resto de elementos

        /*
        Ejemplo con 4, 5, 6:
        
        - el nodo de 4 avanza hacia nullptr (prev), guarda 4 en prev y guarda 5 en second.

        - el nodo de 5 avanza hacia 4, guarda 5 en prev y guarda 6 en second.

        - el nodo de 6 avanza hacia 5, guarda 6 en prev y guarda nullptr en second (fin del bucle).

        */

        ListNode* first = head;
        second = prev;
        while(second != nullptr)
        {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

        /*
        Ejemplo con 1, 2, 3, 4, 5, 6:

        - guarda 2 en tmp1 y 5 en tmp2, 1 avanza hacia 6, 6 avanza hacia 2 y pone 2 y 5 para la siguiente iteracion.

        - guarda 3 en tmp1 y 4 en tmp2, 2 avanza hacia 5, 5 avanza hacia 3 y pone 3 y 4 para la siguiente iteracion.

        - tmp1 y tmp2 son nullptr, 3 avanza hacia 4 y 4 avanza hacia nullptr (fin del bucle).
       */
    }
};

// Eficiencia temporal: O(n), donde n es la longitud de la lista enlazada
// Eficiencia espacial: O(1)