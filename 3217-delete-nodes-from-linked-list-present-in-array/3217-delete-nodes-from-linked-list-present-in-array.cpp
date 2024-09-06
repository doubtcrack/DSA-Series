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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> values_to_remove(nums.begin(), nums.end());

    // Dummy node to handle edge cases (like removing the head)
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    // Pointer to traverse the list
    ListNode* current = dummy;
    
    // Traverse the linked list
    while (current->next != nullptr) {
        if (values_to_remove.count(current->next->val)) {
            // Remove the node if its value is in nums
            ListNode* node_to_remove = current->next;
            current->next = current->next->next;
            delete node_to_remove;
        } else {
            // Move to the next node
            current = current->next;
        }
    }

    // Return the new head of the list
    ListNode* new_head = dummy->next;
    delete dummy;
    return new_head;
    }
};