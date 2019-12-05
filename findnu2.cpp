//假设二叉树中每个节点值为单个字符，采用二叉链存储结构存储。设计一个算法，输出二叉树b中第k层（根节点的层次为1）上的所有叶子节点。

#include "tree.cpp"

void output(btnode *b,int k){
    if(b==NULL){
        return;
    }
    if(k==1){
        if(b->lchild==NULL&&b->rchild==NULL){
            cout<<b->data;
        }
        return;
    }
    else{
        output(b->lchild,k-1);
        output(b->rchild,k-1);
    }
}

int main(){
   int n,k;
   cout<<"the number of char"<<endl;
   cin>>n;
   char c[n+1];
   cout<<"order"<<endl;
   cin>>c;
   btnode *b;
   b=createbtnode(c);
   cout<<"which depth"<<endl;
   cin>>k;
   output(b,k);
   system("pause");
}//A(B(D(E),F),C)