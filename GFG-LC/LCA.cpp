TreeNode* find_lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL || root==p || root==q) return root;
    TreeNode* left=find_lca(root->left, p, q);
    TreeNode* right=find_lca(root->right, p, q);
    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;
}