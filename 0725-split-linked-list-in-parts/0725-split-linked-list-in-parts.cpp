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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int length = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }

    int partSize = length / k;
    int extra = length % k; 

    vector<ListNode*> result(k, nullptr);
    curr = head;

    for (int i = 0; i < k && curr != nullptr; i++) {
        result[i] = curr; 
        int currentPartSize = partSize + (extra > 0 ? 1 : 0);
        extra--;
        for (int j = 1; j < currentPartSize; j++) {
            if (curr != nullptr) {
                curr = curr->next;
            }
        }

        if (curr != nullptr) {
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
    }

    return result;
    }
};