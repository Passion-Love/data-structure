//假设二叉树中每个节点值为单个字符，采用二叉链存储结构存储。设计一个算法，判断值为x的节点与值为y的节点是否互为兄弟，
//假设这样的节点值是唯一的。

#include "tree.cpp"

bool brother(btnode *b,char x,char y){
    if(b==NULL){
        return false;
    }
    if(b->lchild==NULL&&b->rchild==NULL){
        return false;
    }
    else if(b->lchild==NULL){
        return brother(b->rchild,x,y);
    }
    else if(b->rchild==NULL){
        return brother(b->lchild,x,y);
    }
    else{
        if((b->lchild->data==x&&b->rchild->data==y)||(b->lchild->data==y&&b->rchild->data==x)){
            return true;
        }
        else{
            return brother(b->lchild,x,y)||brother(b->rchild,x,y);
        }
    }
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
   char x,y;
   cout<<"x"<<endl;
   cin>>x;
   cout<<"y"<<endl;
   cin>>y;
   cout<<brother(b,x,y);
   system("pause");
}
//A(B(D(E(H,G)),F),C)