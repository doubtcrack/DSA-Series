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
void convert(TreeNode* node, int& cumulative_sum) {
        if (!node) return;

        convert(node->right, cumulative_sum);

        node->val += cumulative_sum;
        cumulative_sum = node->val;
        
        convert(node->left, cumulative_sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int cumulative_sum = 0;
        convert(root, cumulative_sum);
        return root;
    }
};