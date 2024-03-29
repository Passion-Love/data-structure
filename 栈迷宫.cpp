#include <iostream>
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
    int i;
    int j;
    int di;
} box;

typedef struct{
    box data[maxsize];
    int top;
}sttype;

bool mgpath(int xi,int yi,int xe,int ye){
    int i,j,k,di,find;
    sttype st;
    st.top=-1;
    st.top++;
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=-1;
    mg[xi][yi]=-1;
    while(st.top>-1){
        i=st.data[st.top].i;
        j=st.data[st.top].j;
        di=st.data[st.top].di;
        if(i==xe&&j==ye){
            printf("迷宫路径如下：\n");
            for(k=0;k<=st.top;k++){
                printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
                if((k+1)%5==0){
                    printf("\n");
                }
            }
            printf("\n");
            return true;
        }
        find=0;
        while(di<4&&find==0){
            di++;
            switch(di){
                case 0:i=st.data[st.top].i-1;
                       j=st.data[st.top].j;
                       break;
                case 1:i=st.data[st.top].i;
                       j=st.data[st.top].j+1;
                       break;
                case 2:i=st.data[st.top].i+1;
                       j=st.data[st.top].j;
                       break;
                case 3:i=st.data[st.top].i;
                       j=st.data[st.top].j-1;
                       break;
            }
            if(mg[i][j]==0){
                find=1;
            }
        }
        if(find==1){
            st.data[st.top].di=di;
            st.top++;
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=-1;
            mg[i][j]=-1;
        }
        else{
            mg[st.data[st.top].i][st.data[st.top].j]=0;
            st.top--;
        }
    }
    return false;
}

int main(){
    if(!mgpath(1,1,M,N)){
        printf("该迷宫问题没有解！");
    }
    system("pause");
    return 0;
}