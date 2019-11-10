//某非空单链表L中所有元素为整数，设计一个算法将所有小于零的节点移到所有大于等于零的节点的前面。
#include <iostream> 
using namespace std;

typedef struct lnode{
    int data;
    struct lnode *next;
}linklist;

void rank1(linklist *&l){
    linklist *l1,*r,*r1,*p;
    p=l->next;
    l1=NULL;
    r=l;
    r1=l1;
    while(p!=NULL){
        if(p->data>=0){
            if(l1==NULL){
                r->next=p->next;
                l1=p;
                l1->next=NULL;
                r1=l1;
                p=r->next;
            }
            else{
                r->next=p->next;
                p->next=r1->next;
                r1->next=p;
                r1=r1->next;
                p=r->next;
            }
        }
        else{
            r=r->next;
            p=p->next;
        }
    }
    r->next=l1;
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
    s->data=-2;
    s->next=l->next;
    l->next=s;
    s=(linklist*)malloc(sizeof(linklist));
    s->data=2;
    s->next=l->next;
    l->next=s;
    s=(linklist*)malloc(sizeof(linklist));
    s->data=-3;
    s->next=l->next;
    l->next=s;
    rank1(*&l);
    cout<<l->next->next->next->next->data;
    return 0;
}