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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
 
        /*delete leaf nodes that are = target, if deleting a node that = target 
        makes parent node of deleted node a leaf node, delete that too. 
        
        approach could be dfs,

        we travers trhoguht the Tree

        we check if check left if it has children, if it doesnt we chec kif it is = target
        if it'#s not we delete that node.
        */  

        return dfs(root, target);
    }

private:
    TreeNode* dfs(TreeNode* node, int target){
        if (!node) {
            return nullptr;
        }
        node->left  = dfs(node->left, target);
        node->right = dfs(node->right, target);
        
        if (node->left == nullptr &&
            node->right == nullptr &&
            node->val == target) {
            delete node;
            return nullptr; 
        }
        return node;

    }

};