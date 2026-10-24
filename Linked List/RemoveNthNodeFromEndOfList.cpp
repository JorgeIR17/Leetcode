struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* left = &dummy;
        ListNode* right = head;

        while(n > 0)
        {
            right = right->next;
            n--;
        }

        while(right != nullptr)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy.next;

        /*
        
        Ejemplo con 1, 2, 3, 4, 5, y n = 2 (eliminar 4):

        - right avanza hasta 3 (primer bucle).

        - right acaba en nullptr y left en 3.

        - left->next (4) pasará a ser left->next->next(5), eliminando asi 4 de la lista.
        
        */
    }
};

// Eficiencia temporal: O(n)
// Eficiencia espacial: O(1)