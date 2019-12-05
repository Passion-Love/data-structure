#include "tree.h"

typedef struct{
   btnode *bt[maxsize];
   int top=-1;
}st;

btnode *createbtnode(char *c){
   int k=1;
   btnode *p,*b;
   b=NULL;
   st s;
   while(*c!='\0'){
      if(*c=='('){
         k=1;
         s.top++;
         s.bt[s.top]=p;
      }
      else if(*c==','){
         k=2;
      }
      else if(*c==')'){
         k=1;
         s.top--;
      }
      else{
         switch(k){
            case 1:
                   p=(btnode*)malloc(sizeof(btnode));
                   p->lchild=NULL;
                   p->rchild=NULL;
                   p->data=*c;
                   s.bt[s.top]->lchild=p;  
                   if(b==NULL){
                       b=p;
                   }
                   break;     
            case 2:
                   p=(btnode*)malloc(sizeof(btnode));
                   p->lchild=NULL;
                   p->rchild=NULL;
                   p->data=*c;
                   s.bt[s.top]->rchild=p;   
                   if(b==NULL){
                       b=p;
                   }
                   break;  
         }
      }
      c++;
   }
   return b;
}

void destroybt(btnode *&b){
    if(b==NULL){
        return;
    }
    destroybt(b->lchild);
    destroybt(b->rchild);
    free(b);
}

btnode *findnode(btnode *b,char x){
    if(b==NULL){
        return NULL;
    }
    if(b->data==x){
        return b;
    }
    else{
        if(findnode(b->lchild,x)!=NULL){
            return findnode(b->lchild,x);
        }
        return findnode(b->rchild,x);
    }
}

int btnodedepth(btnode *b){
    int h=0;
    if(b==NULL){
        return 0;
    }
    else{
        h++;
        return ((h+btnodedepth(b->lchild))>(h+btnodedepth(b->rchild)))?(h+btnodedepth(b->lchild)):(h+btnodedepth(b->rchild));
    }
}

void dispbtnode(btnode *b){
    if(b!=NULL){
        cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL){
            cout<<'(';
            dispbtnode(b->lchild);
            if(b->rchild!=NULL){
                cout<<',';
            }
            dispbtnode(b->rchild);
            cout<<')';
        }
    }
}

void preorder(btnode *b){
    if(b!=NULL){
        cout<<b->data;
        preorder(b->lchild);
        preorder(b->rchild);
    }
}

void inorder(btnode *b){
    if(b!=NULL){
        inorder(b->lchild);
        cout<<b->data;
        inorder(b->rchild);
    }
}

void postorder(btnode *b){
    if(b!=NULL){
        postorder(b->lchild);
        postorder(b->rchild);
        cout<<b->data;
    }
}

void levelorder(btnode *b){
    btnode *bn[maxsize];
    int front=0,rear=0;
    if(b==NULL){
        cout<<"NULL";
    }
    else{
        bn[rear]=b;
        while(front<=rear){
            cout<<bn[front]->data;
            if(bn[front]->lchild!=NULL){
                rear=(rear+1)%maxsize;
                bn[rear]=bn[front]->lchild;
            }
            if(bn[front]->rchild!=NULL){
                rear=(rear+1)%maxsize;
                bn[rear]=bn[front]->rchild;
            }
            front=(front+1)%maxsize;
        }
        cout<<endl;
    }
}

btnode *createbt1(char *pre,char *in,int n){
    btnode *b;
    int k;
    for(k=0;k<n;k++){
        if(*pre==*(in+k)){
            break;
        }
    }
    if(k==n){
        return NULL;
    }
    b=(btnode*)malloc(sizeof(btnode));
    b->data=*pre;
    b->lchild=createbt1(pre+1,in,k);
    b->rchild=createbt1(pre+k+1,in+k+1,n-k-1);
    return b;
}

btnode *trans1(sqbtree a,int i){
    btnode *b;
    if(i>=maxsize){
        return NULL;
    }
    if(a[i]=='\0'||a[i]=='#'){
        return NULL;
    }
    b=(btnode*)malloc(sizeof(btnode));
    b->data=a[i];
    b->lchild=trans1(a,2*i);
    b->rchild=trans1(a,2*i+1);
    return b;
}

