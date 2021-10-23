Node* removekeys(Node* root, int l, int r) {
    if(!root) return NULL;
    
    root->left = removekeys(root->left, l, r);
    root->right = removekeys(root->right, l, r);
    
    if(root->data < l) {
        Node *rt = root->right;
        delete root;
        return rt;
    }
    else if(root->data > r){
        Node* lt = root->left;
        delete root;
        return lt;
    }
    else return root;
}