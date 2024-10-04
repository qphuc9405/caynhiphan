#include<iostream>

using namespace std;
//nhap vao cay nhi phan cac so nguyen . xuat ra man hinh cac phan tu cay nhi phan
//khai bao cau truc mot node
struct node{
    int data;//du lieu cua node 
    struct node*pleft;
    struct node*pright;
};
typedef struct node NODE;
typedef NODE* TREE;
//khoi tao cay
void KhoiTaoCay(TREE &t){
    t=NULL;//cây rỗng
}
//hàm thêm phần tử x vào cây nhị phân
void Themnode(TREE &t,int x){
    //nếu cây rỗng
    if(t==NULL){
        NODE*p=new NODE;//khởi tạo 1node để thêm vào cây
        p->data=x;//thêm dữ liệu x vào data
        p->pleft=NULL;
        p->pright=NULL;
        t=p;//node p chính là node gốc <=> x chính là node gốc
    }
    else 
    {
        if(t->data > x){
            Themnode(t->pleft,x);
        }
        else if(t->data < x){
            Themnode(t->pright,x);
        }
    }
}
//hàm xuất theo Preorder(NLR)
/*void Preorder(TREE t){
    if(t!=NULL){
        cout<<t->data<<" ";
        Preorder(t->pleft);
        Preorder(t->pright);
    }
}

void Inorder(TREE t){//xuat ra cac gia tri tu be den lon
    if(t!=NULL){
        Inorder(t->pleft);
        cout<<t->data<<" ";
        Inorder(t->pright);
    }
}
void RNL(TREE t){//xuat ra cac gia tri tu lớn về bé
    if(t!=NULL){
        RNL(t->pright);
        cout<<t->data<<" ";
        RNL(t->pleft);
    }
}
void NRL(TREE t){
    if(t!=NULL){
        cout<<t->data<<" ";
        NRL(t->pright);
        NRL(t->pleft);
    }
}
void Postorder(TREE t){ 
    if(t!=NULL){
        Postorder(t->pleft);
        Postorder(t->pright);
        cout<<t->data<<" ";
    }
}  */
//ham kiem tra so nguyen to
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
//ham dem so nguyen to trong cay
void soluongsonguyento(TREE t,int &dem){

    if(t!=NULL){
        if(isPrime(t->data)==true){
            dem++;
        }
        soluongsonguyento(t->pleft,dem);
        soluongsonguyento(t->pright,dem);
    }
}
//tim kiem phan tu trong cay ->tra ve node do
NODE* findk(TREE t,int k){
    while(t!=NULL){
        if(t->data==k){
            return t;
        }
        else if(t->data>k){
            t=t->pleft;
            }
        else{
            t=t->pright;
        }
    }
    return NULL;
}
//hàm kiểm tra node lá
void ktraNode_la(TREE t){
    if(t!=NULL){
        if(t->pleft==NULL && t->pright==NULL){
            cout<<t->data<<" ";
        }
        ktraNode_la(t->pleft);
        ktraNode_la(t->pright);
    }
}


int main(){
    TREE t;
    KhoiTaoCay(t);
    int A[11]={15,6,7,13,9,3,2,4,18,17,20};
    for(int i=0;i<11;i++){
        Themnode(t,A[i]);
    }
    /*cout<<"\nPreorder:";
    Preorder(t);
    cout<<"\nInorder:";
    Inorder(t);
    cout<<"\nRNL:";
    RNL(t);
    cout<<"\nNRL:";
    NRL(t);
    cout<<"\nPostorder:";
    Postorder(t);
    int dem=0;
    soluongsonguyento(t,dem);
    cout<<"so luong so nguyen to trong cay la: "<<dem<<endl;
    int k;cout<<"\nNhap k:";
    cin>>k;
    NODE*p=findk(t,k);
    if(p!=NULL){
        cout<<"Phan tu can tim co trong cay"<<endl;
    }
    else cout<<"ko co ptu trong cay";*/
    cout<<"\nCac node la trong cay:";
    ktraNode_la(t);
    return 0;

}