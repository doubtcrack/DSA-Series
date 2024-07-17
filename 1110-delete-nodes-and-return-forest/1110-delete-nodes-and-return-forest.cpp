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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        // Lambda Function
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
            if (!node) return nullptr;
            bool deleted = toDeleteSet.count(node->val);
            cout<<deleted<<" ";
            if (is_root && !deleted) result.push_back(node);
            node->left = dfs(node->left, deleted);
            node->right = dfs(node->right, deleted);
            return deleted ? nullptr : node;
        };

        
        dfs(root, true);
        return result;
    }
};