//有一个由整数元素构成的非空单链表A，设计一个算法，将其拆分成两个单链表A和B，使得A单链表中含有所有的偶数节点，
//B单链表中含有所有的奇数节点，且保持原来的相对次序。

#include <iostream> 
using namespace std;

typedef struct lnode{
    int data;
    struct lnode *next;
}linklist;

linklist* rank1(linklist *&l){
    linklist *l1,*r,*r1,*p;
    p=l->next;
    l1=(linklist*)malloc(sizeof(linklist));
    l1->next=NULL;
    r=l;
    r1=l1;
    while(p!=NULL){
        if(p->data%2!=0){
            r->next=p->next;
            p->next=r1->next;
            r1->next=p;
            r1=r1->next;
            p=r->next;
        }
        else{
            r=r->next;
            p=p->next;
        }
    }
    return l1;
}

int main(){
    linklist *l,*s;
    l=(linklist*)malloc(sizeof(linklist));
    l->next=NULL;
    s=(linklist*)malloc(sizeof(linklist));
    s->data=1;
    s->next=l->next;
    l->next=s;
    s=(linklist*)malloc(sizeof(linklist));
    s->data=2;
    s->next=l->next;
    l->next=s;
    s=(linklist*)malloc(sizeof(linklist));
    s->data=3;
    s->next=l->next;
    l->next=s;
    s=(linklist*)malloc(sizeof(linklist));
    s->data=4;
    s->next=l->next;
    l->next=s;
    s=rank1(*&l);
    cout<<s->next->data;
    return 0;
}