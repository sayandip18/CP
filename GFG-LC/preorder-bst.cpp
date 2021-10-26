class Solution {
public:
    TreeNode* buildBST(TreeNode* &root, int x){
        if(!root) return root = new TreeNode(x);
        if(root->val > x) root->left = buildBST(root->left, x);
        else root->right = buildBST(root->right, x);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(auto x: preorder)
            buildBST(root, x);
        return root;
    }
};