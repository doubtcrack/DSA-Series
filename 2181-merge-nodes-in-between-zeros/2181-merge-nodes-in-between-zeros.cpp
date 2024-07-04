/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
    ListNode* current = head;
    ListNode* newHead = nullptr;
    ListNode* tail = nullptr;
    
    while (current != nullptr) {
        if (current->val == 0) {
            int sum = 0;
            current = current->next;
            while (current != nullptr && current->val != 0) {
                sum += current->val;
                current = current->next;
            }
            if (sum != 0) {
                ListNode* newNode = new ListNode(sum);
                if (newHead == nullptr) {
                    newHead = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }
    return newHead;
    }
};