vector<int> p1, p2;
bool getPath(TreeNode* root, TreeNode* key, vector<int> &path){
    if(root==NULL) return false;
    path.push_back(root->val);
    if(root->val==key->val) return true;
    if(getPath(root->left, key, path) || getPath(root->right,key,path)) return true;
    path.pop_back();
    return false;
}
int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!getPath(root,p,p1)||!getPath(root,q,p2)) return -1;
    int pc;
    for(pc=0;pc<p1.size()&&p2.size();++pc){
        if(p1[pc]!=p2[pc]) break;
    }
    return p1[pc-1];
}