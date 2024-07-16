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


    // Helper function to find the path from root to a given node value
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        if (root->left && findPath(root->left, value, path)) {
            path += 'L';
            return true;
        }
        
        if (root->right && findPath(root->right, value, path)) {
            path += 'R';
            return true;
        }
        
        return false;
    }

    // Function to find the Lowest Common Ancestor (LCA)
    TreeNode* findLCA(TreeNode* root, int s, int t) {
        if (!root || root->val == s || root->val == t) return root;
        TreeNode* left = findLCA(root->left, s, t);
        TreeNode* right = findLCA(root->right, s, t);
        if (left && right) return root;
        return left ? left : right;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
    // Find the Lowest Common Ancestor (LCA) of startValue and destValue
    TreeNode* lca = findLCA(root, startValue, destValue);
    
    // Find the path from LCA to startValue
    string pathToStart;
    findPath(lca, startValue, pathToStart);
    
    // Find the path from LCA to destValue
    string pathToDest;
    findPath(lca, destValue, pathToDest);
    
    // Reverse the paths to get the correct directions
    reverse(pathToStart.begin(), pathToStart.end());
    reverse(pathToDest.begin(), pathToDest.end());
    
    // Convert pathToStart to 'U' (up) directions
    for (char& c : pathToStart) {
        c = 'U';
    }
    
    // Combine the paths
    return pathToStart + pathToDest;
    }
};