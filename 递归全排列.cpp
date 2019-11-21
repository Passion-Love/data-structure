#include <iostream>
using namespace std;

void swap(int *i,int *j){
    int a;
    a=*i;
    *i=*j;
    *i=a;
}

void perm(int a[],int n,int k){
    int i;
    if(k==0){
        for(i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");
    }
    else{
        for(i=0;i<=k;i++){
            swap(a[k],a[i]);
            perm(a,n,k-1);
            swap(a[k],a[i]);
        }
    }
}

int main(){
    int n=3,k=2;
    int a[]={1,2,3};
    perm(a,n,k);
}