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
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};

        // If the node is a leaf
        if (!node->left && !node->right) return {0};

        // Get distances from left and right subtrees
        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);

        // Count the number of good pairs
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r + 2 <= distance) {
                    result++;
                }
            }
        }

        // Update distances
        vector<int> currentDistances;
        for (int l : leftDistances) {
            if (l + 1 < distance) {
                currentDistances.push_back(l + 1);
            }
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) {
                currentDistances.push_back(r + 1);
            }
        }

        return currentDistances;
    }
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
};