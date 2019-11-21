#include <iostream>
using namespace std;
void hanoi1(int n,int x,int y,int z);
void move(int n,int x,int y);

void hanoi1(int n,int x,int y,int z){
    if(n==1){
        move(n,x,z);
    }
    else{
        hanoi1(n-1,x,z,y);
        move(n,x,z);
        hanoi1(n-1,y,x,z);
    }
}
void move(int n,int x,int y){
    cout<<n<<':'<<x<<"->"<<y<<endl;
}

int main(){
    int n;
    cout<<"input:"<<endl;
    cin>>n;
    hanoi1(n,1,2,3);
    system("pause");
    return 0;
}