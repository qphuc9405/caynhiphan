#include "hoccaynhiphan.cpp"
int main(){
    int A[10]={15,3,7,9,8,6,18,17,4,20};
    Node*root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,A[i]);
    }
    int k;
    cout<<"Nhap gia tri cua node can xoa:";
    cin>>k;
    DeleteNode(root,k);
    inorder(root);
}