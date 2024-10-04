#include<iostream>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* newNode=new Node;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
//them node vao cay nhi phan
Node* insert(Node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    	
    }
}
void Preorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
//hàm tìm kiếm node có giá trị k trong cây nhị phân
Node* findk(Node* root,int k){
    while(root!=NULL){
        if(root->data==k){
            return root;
        }
        else if(root->data>k){
            root=root->left;
        }
        else {
            root=root->right;
        }
    }
    return root;
}
//ham tim node co gtri nho nhat trong cay
Node* findMin(Node* root) {
    if (root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}
//hàm xóa node có giá trị k
Node* DeleteNode(Node*root,int k){
    if(root==NULL){
        return root;
    }
    if(root->data>k){
        root->left=DeleteNode(root->left,k);
    }
    else if(root->data<k){
        root->right=DeleteNode(root->right,k);
    }
    else {
        Node*p=root;
        if(root->left==NULL){
            root=root->right;
            delete p;
        }
        else if(root->right==NULL){
            root=root->left;
            delete p;
        }
        else {
            Node* temp=findMin(root->right);
            root->data= temp->data;
            root->right = DeleteNode(root->right,temp->data);
           
            }

    }
    return root;

}
//hàm tìm node kế tiếp
Node* findSuccessor(Node* root, Node* x) {
    if(x==NULL){
        return NULL;
    }
    if (x->right) {
        return findMin(x->right);
    }
    Node* successor=NULL;
    while (root != NULL && x->data != root->data) {
        if (x->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (x->data > root->data) {
            root = root->right;
        }
    }
    return successor;
}


int main(){
    int A[10]={15,3,7,9,8,6,18,17,4,20};
    Node*root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,A[i]);
    }
    /*inorder(root);
    cout<<"\n";
    Preorder(root);
    int k;cout<<"\nNhap phan tu k:";
    cin>>k;
    Node*p=findk(root,k);
    if(p!=NULL){
        cout<<"Phan tu can tim co trong cay"<<endl;
    }
    else {
        cout<<"ko co ptu trong cay";
    }*/
    Node* x = findk(root, 17);
//     cout << "Node: " << x->key << endl;
    Node* succ = findSuccessor(root, x);
     if (!succ) {
        cout << "Not found"<<endl;
    }
    else
        cout << "Successor: "<< succ->data<<endl;
    inorder(root);
}