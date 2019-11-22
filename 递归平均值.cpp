#include <iostream>
using namespace std;

void ave(double a[],int n,double &av,int i){
    if(i==0){
        av=(av+a[i])/n;
        return;
    }
    av+=a[i];
    ave(a,n,av,i-1);
}

int main(){
    double a[]={1,2,3,4,5};
    int n=5;
    double av=0;
    int i=n-1;
    ave(a,n,av,i);
    cout<<av;
}