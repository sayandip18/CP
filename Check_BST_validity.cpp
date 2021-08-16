// In order traversal
// Check for sorted
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void inorder(Node* node){
    inorder(node->left);
    v.push_back(node->val);
    inorder(node->right);
}
bool check_sorted(vector<int> v, int n){
    for(int i=1;i<n;++i){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}