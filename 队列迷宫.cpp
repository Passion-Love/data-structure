#include<iostream>
using namespace std;

#define maxsize 100
#define M 8
#define N 8

int mg[M+2][N+2]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

typedef struct{
    int i,j;
    int pre;
}box;

typedef struct{
    box data[maxsize];
    int front,rear;
}qutype;

bool mgpath1(int xi,int yi,int xe,int ye){
    int i,j,find=0,di;
    qutype qu;
    qu.front=qu.rear=-1;
    qu.rear++;
    qu.data[qu.rear].i=xi;
    qu.data[qu.rear].j=yi;
    qu.data[qu.rear].pre=-1;
    mg[xi][yi]=-1;
    while(qu.front!=qu.rear&&!find){
        qu.front++;
        i=qu.data[qu.front].i;
        j=qu.data[qu.front].j;
        if(i==xe&&j==ye){
            find=1;
            print(qu,qu.front);
            return true;
        }
        for(di=0;di<4;di++){
            switch(di){
                case 0: i=qu.data[qu.front].i-1;
                        j=qu.data[qu.front].j;
                        break;
                case 1: i=qu.data[qu.front].i;
                        j=qu.data[qu.front].j+1;
                        break;
                case 2: i=qu.data[qu.front].i+1;
                        j=qu.data[qu.front].j;
                        break;
                case 3: i=qu.data[qu.front].i;
                        j=qu.data[qu.front].j-1;
                        break;
            }
            if(mg[i][j]==0){
                qu.rear++;
                qu.data[qu.rear].i=i;
                qu.data[qu.rear].j=j;
                qu.data[qu.rear].pre=qu.front;
                mg[i][j]=-1;
            }
        }
    }
    return false;
}

void print(qutype qu);

int main(){
    if(!mgpath1(1,1,M,N)){
        printf("该迷宫问题没有解！");
    }
    system("pause");
    return 0;
}
