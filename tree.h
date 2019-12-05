#include <iostream>
using namespace std;

#define maxsize 100
#define maxsons 100

typedef char sqbtree[maxsize];

typedef struct node{
   struct node *lchild;
   struct node *rchild;
   char data;
}btnode;//二叉树的链式储存

typedef struct{
    char data;
    int parent;
}ptree[maxsize];//双亲储存结构

typedef struct{
    char data;
    struct node *sons[maxsons];
}tsonnode;//孩子链储存结构

typedef struct tnode{
    char data;
    struct tnode *hp;//指向兄弟
    struct tnode *vp;//指向孩子节点
}tsbnode;//兄弟链储存结构

typedef struct{
    char data;
    int ltag,rtag;//线索标记
    struct node *lchild;
    struct node *rchild;
}tbtnode;//线索树节点类型

btnode *createbtnode(char *c);//创建二叉树

void destroybt(btnode *&b);//销毁二叉树

btnode *findnode(btnode *b,char x);//寻找节点

int btnodedepth(btnode *b);//求二叉树高度

void dispbtnode(btnode *b);//输出二叉树

void preorder(btnode *b);//先序遍历

void inorder(btnode *b);//中序遍历

void postorder(btnode *b);//后序遍历

void levelorder(btnode *b);//层次遍历

btnode *createbt1(char *pre,char *in,int n);//由先序和中序序列构造二叉树

btnode *trans1(sqbtree a,int i);//将二叉树顺序储存结构转化为二叉链

