//假设二叉树中每个节点值为单个字符，采用二叉链存储结构存储。设计一个算法，求二叉树b中第k层（根节点的层次为1）上节点个数。

#include "tree.cpp"

int findnu(btnode *b,int k){
    int n=0;
    if(b==NULL){
        return n;
    }
    if(k==1){
        n=1;
        return n;
    }
    else{
        return findnu(b->lchild,k-1)+findnu(b->rchild,k-1);
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
   cout<<findnu(b,k);
   system("pause");
}//A(B(D(E),F),C)