//假设二叉树中每个节点值为单个字符，采用二叉链存储结构存储。设计一个算法求二叉树b的最小枝长。
//所谓最小最小枝长是指的是根节点到最近叶子节点的路径长度。

#include "tree.cpp"

int minpath(btnode *b){
    int n=0;
    if(b==NULL){
        return 0;
    }
    if(b->lchild!=NULL||b->rchild!=NULL){
        n=1;
    }
    return (n+minpath(b->lchild))>(n+minpath(b->rchild))?(n+minpath(b->rchild)):(n+minpath(b->lchild));
}

int main(){
   int n;
   cout<<"the number of char"<<endl;
   cin>>n;
   char c[n+1];
   cout<<"order"<<endl;
   cin>>c;
   btnode *b;
   b=createbtnode(c);
   cout<<minpath(b);
   system("pause");
}//A(B(D(,E),F),C)