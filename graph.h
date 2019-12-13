#include <iostream>
using namespace std;

#define maxv 100

typedef struct{
    int no;
    int info;
}vertextype;

typedef struct{
    int edges[maxv][maxv];
    int n,e;
    vertextype vexs[maxv];
}mgraph;//图的邻接矩阵储存

typedef struct anode{
    int adjvex;
    struct anode *nextarc;
    int info;
}arcnode;//边结点

typedef struct vnode{
    int data;
    arcnode *firstarc;
}vnode;//头结点

typedef struct{
    vnode adjlist[maxv];
    int n,e;
}algraph;//图的邻接表储存

void create(algraph &g);//构造无向图

void dfs(algraph *g,int v);//深度优先遍历

void bfs(algraph *g,int v);//高度优先遍历

void dfs1(algraph *g);//深度优先遍历非连通图

void bfs1(algraph *g);//高度优先遍历非连通图

bool connect(algraph *g);//判断无向图G的连通性

void existpath(algraph *g,int u,int v,bool &has);//判断u->v是否有简单路径

void findapath(algraph *g,int u,int v,int path[],int d);//输出从u->v的一条简单路径

void findpath(algraph *g,int u,int v,int path[],int d);//输出从u->v的所有简单路径

void pathall(algraph *g,int u,int v,int l,int path[],int d);//输出从u->v的长度为l的所有简单路径

void shortpath(algraph *g,int u,int v);//不带权无向图g从u->v的一条最短路径