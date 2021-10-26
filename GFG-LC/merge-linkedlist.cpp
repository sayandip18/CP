Node* merge(Node* a, Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->val > b->val) std::swap(a,b);

    Node* res = a;
    while(a!=NULL && b!=NULL){
        Node* temp = NULL;
        while(a!=NULL && a->val <= b->val){
            temp = a;
            a = a->next;
        }
        temp->next = b;
        std::swap(a,b);
    }
    return res;

}