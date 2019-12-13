#include "graph.h"

void create(algraph &g){
    int j=0;
    arcnode *a,ar[maxv];
    cout<<"vertex number"<<endl;
    cin>>g.n;
    cout<<"arc number"<<endl;
    cin>>g.e;
    for(int i=0;i<g.n;i++){
        cout<<"vnode data"<<endl;
        cin>>g.adjlist[i].data;
        g.adjlist[i].firstarc=NULL;
        cout<<"arcnode adjvex"<<endl;
        if(cin>>ar[j].adjvex){
            g.adjlist[i].firstarc=&ar[j];
            g.adjlist[i].firstarc->nextarc=NULL;
            a=g.adjlist[i].firstarc;
            j++;
        }
        while(cin>>ar[j].adjvex){    
            a->nextarc=&ar[j];
            a=a->nextarc;
            a->nextarc=NULL;
            j++;
        }
        cin.clear();
    }
}

int visit[maxv];

void initvisit(){
    for(int i=0;i<maxv;i++){
       visit[i]=0;
    }
}

void dfs0(algraph *g,int v){
    visit[v]=1;
    cout<<v<<endl;
    for(int i=0;i<g->n;i++){
        if(g->adjlist[i].data==v){
            v=i;
            break;
        }
    }
    arcnode *p;
    int w;
    p=g->adjlist[v].firstarc;
    while(p!=NULL){
        w=p->adjvex;
        if(visit[w]==0){
            dfs0(g,w);
        }
        p=p->nextarc;
    }
}

void dfs(algraph *g,int v){
    initvisit();
    dfs0(g,v);
}

void bfs(algraph *g,int v){
    initvisit();
    int a[maxv];
    arcnode *p;
    int front=-1,rear=-1;
    cout<<v<<endl;
    visit[v]=1;
    rear++;
    a[rear]=v;
    while(front!=rear){
        front=(front+1)%maxv;
        for(int i=0;i<g->n;i++){
            if(g->adjlist[i].data==a[front]){
                p=g->adjlist[i].firstarc;
                break;
            }
        }
        while(p!=NULL){
            if(visit[p->adjvex]==0){
                rear=(rear+1)%maxv;
                a[rear]=p->adjvex;
                cout<<p->adjvex<<endl;
                visit[p->adjvex]=1;
            }
            p=p->nextarc;   
        }
    }
}

void dfs1(algraph *g){
    initvisit();
    int j;
    for(int i=0;i<g->n;i++){
        j=g->adjlist[i].data;
        if(visit[j]==0){
            dfs0(g,j);
        }
    }
}

void bfs1(algraph *g){
    int j;
    for(int i=0;i<g->n;i++){
        j=g->adjlist[i].data;
        if(visit[j]==0){
            bfs(g,j);
        }
    }
}

bool connect(algraph *g){
    bool b=true;
    int j,v=1;
    cout<<"which vertex"<<endl;
    cin>>v;
    dfs(g,v);
    for(int i=0;i<g->n;i++){
        j=g->adjlist[i].data;
        if(visit[j]==0){
            b=false;
            break;
        }
    }
    return b;
}

void existpath0(algraph *g,int u,int v,bool &has){
    if(u==v){
        has=true;
        return;
    }
    has=false;
    visit[u]=1;
    arcnode *p;
    p=g->adjlist[u].firstarc;
    while(p!=NULL){
        if(visit[p->adjvex]==0){
            existpath0(g,p->adjvex,v,has);
        }
        p=p->nextarc;
    }
}

void existpath(algraph *g,int u,int v,bool &has){
    initvisit();
    existpath0(g,u,v,has);
}

void findapath0(algraph *g,int u,int v,int path[],int d){
    d++;
    path[d]=u;
    visit[u]=1;
    if(u==v){
        for(int i=0;i<=d;i++){
            cout<<path[i];
        }
        cout<<endl;
        return;
    }
    arcnode *p;
    p=g->adjlist[u].firstarc;
    while(p!=NULL){
        if(visit[p->adjvex]==0){
            findapath0(g,p->adjvex,v,path,d);
        }
        p=p->nextarc;
    }
}

void findapath(algraph *g,int u,int v,int path[],int d){
    initvisit();
    findapath0(g,u,v,path,d);
}

void findpath0(algraph *g,int u,int v,int path[],int d){
    d++;
    path[d]=u;
    visit[u]=1;
    if(u==v){
        for(int i=0;i<=d;i++){
            cout<<path[i];
        }
        cout<<endl;
    }
    arcnode *p;
    p=g->adjlist[u].firstarc;
    while(p!=NULL){
        if(visit[p->adjvex]==0){
            findpath0(g,p->adjvex,v,path,d);
        }
        p=p->nextarc;
    }
    visit[u]=0;
}

void findpath(algraph *g,int u,int v,int path[],int d){
    initvisit();
    findpath0(g,u,v,path,d);
}

void pathall0(algraph *g,int u,int v,int l,int path[],int d){
    d++;
    path[d]=u;
    visit[u]=1;
    if(u==v&&d==l){
        for(int i=0;i<=d;i++){
            cout<<path[i];
        }
        cout<<endl;
    }
    arcnode *p;
    p=g->adjlist[u].firstarc;
    while(p!=NULL){
        if(visit[p->adjvex]==0){
            pathall0(g,p->adjvex,v,l,path,d);
        }
        p=p->nextarc;
    }
    visit[u]=0;
}

void pathall(algraph *g,int u,int v,int l,int path[],int d){
    initvisit();
    pathall0(g,u,v,l,path,d);
}

typedef struct{
    int data;
    int parent;
}quere;

void shortpath(algraph *g,int u,int v){
    initvisit();
    quere q[maxv];
    arcnode *p;
    int front=-1,rear=-1,w;
    rear++;
    q[rear].data=u;
    q[rear].parent=-1;
    visit[u]=1;
    while(front!=rear){
        front++;
        p=g->adjlist[q[front].data].firstarc;
        while(p!=NULL){
            if(q[rear].data==v){
                w=q[rear].parent;
                cout<<v;
                while(w!=-1){
                    cout<<q[w].data;
                    w=q[w].parent;
                }
                return;
            }
            if(visit[p->adjvex]==0){
                rear++;
                q[rear].data=p->adjvex;
                q[rear].parent=front;
                visit[p->adjvex]=1;
            }
            p=p->nextarc;
        }
    }
}