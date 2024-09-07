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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      // Helper function to check if the linked list corresponds to a downward path in the binary tree
    bool dfs(TreeNode* root, ListNode* head) {
        // Base case: if the linked list is fully traversed, return true
        if (!head) return true;
        
        // Base case: if the tree node is null, return false
        if (!root) return false;
        
        // Check if the current tree node matches the linked list node value
        if (root->val != head->val) return false;
        
        // Recursively check the left and right subtrees for a matching path
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }

    // Main function to determine if there's a matching downward path
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        
        // Check if the current tree node starts a valid path, or recurse further in the tree
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};