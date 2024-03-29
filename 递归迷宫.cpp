#include <iostream>
using namespace std;
#define m 4
#define n 4
#define maxsize 100
typedef struct{
    int i;
    int j;
}box;

typedef struct{
    box data[maxsize];
    int length;
}pathtype;

int mg[m+2][n+2]={
    {1,1,1,1,1,1},
    {1,0,0,0,1,1},
    {1,0,1,0,0,1},
    {1,0,0,0,1,1},
    {1,1,0,0,0,1},
    {1,1,1,1,1,1}
};

void mgpath(int xi,int yi,int xe,int ye,pathtype path){
    int di,k,i,j;
    if(xi==xe&&yi==ye){
        path.data[path.length].i=xi;
        path.data[path.length].j=yi;
        path.length++;
        printf("�Թ�·��%d����:\n");
        for(k=0;k<path.length;k++){
            printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
            if((k+1)%5==0){
                printf("\n");
            }
        }
        printf("\n");
    }
    else{
        if(mg[xi][yi]==0){
            di=0;
            while(di<4){
                switch(di){
                    case 0:i=xi-1;
                           j=yi;
                           break;
                    case 1:i=xi;
                           j=yi+1;
                           break;
                    case 2:i=xi+1;
                           j=yi;
                           break;
                    case 3:i=xi;
                           j=yi-1;
                           break;
                }
                path.data[path.length].i=xi;
                path.data[path.length].j=yi;
                path.length++;
                mg[xi][yi]=-1;
                mgpath(i,j,xe,ye,path);
                path.length--;
                mg[xi][yi]=0;
                di++;
            }
        }
    }
}

int main(){
    pathtype path;
    path.length=0;
    mgpath(1,1,4,4,path);
}