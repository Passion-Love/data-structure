//假设二叉树中每个节点值为单个字符，采用二叉链存储结构存储。设计一个算法void findparent(BTNode *b，char x，BTNode *&p)求二叉
//树b中指定值为x的节点的双亲节点p，提示：根节点的双亲为NULL，若在b中未找到值为x的节点，p亦为NULL，并假设二叉树中所有节点值是唯一的

#include "tree.cpp"

void findparent(btnode *b,char x,btnode *&p){
   if(b->data==x){
      p=NULL;
      return;
   }
   else if(b==NULL){
      return;
   }
   else if((b->lchild!=NULL)&&(b->lchild->data==x)){
      p=b;
      return;
   }
   else if((b->rchild!=NULL)&&(b->rchild->data==x)){
      p=b;
      return;
   }
   else{
      if(b->lchild!=NULL){
         findparent(b->lchild,x,p);
      }
      if(b->rchild!=NULL){
         findparent(b->rchild,x,p);
      }
   }
}

int main(){
   int n;
   cout<<"the number of char"<<endl;
   cin>>n;
   char c[n+1],x;
   cout<<"tree"<<endl;
   cin>>c;
   cout<<"which char"<<endl;
   cin>>x;
   btnode *b,*p;
   b=createbtnode(c);
   findparent(b,x,p);
   cout<<p->data;
   system("pause");
   //A(B(C,D),E(F,G))
}