struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        int carry = 0; // carry almacena el acarreo (solo 1 digito en cada nodo)
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int v1, v2;
            if(l1 != nullptr)
                v1 = l1->val;
            else
                v1 = 0;
            if(l2 != nullptr)
                v2 = l2->val;
            else
                v2 = 0;
            
            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);

            cur = cur->next;
            
            if(l1 != nullptr)
                l1 = l1->next;
            else
                l1 = nullptr;
            if(l2 != nullptr)
                l2 = l2->next;
            else
                l2 = nullptr;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

//Eficiencia temporal: O(max(n, m)) donde n y m son las longitudes de las listas l1 y l2 respectivamente.
//Eficiencia espacial: O(max(n, m)) para la lista resultante.