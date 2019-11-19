#include <iostream>
using namespace std;

#define maxsize 100

typedef struct{
    char data[maxsize];
    int top=-1;
}sqstack;

bool match(char a[],int n){
    bool match=true;
    int i=0;
    sqstack sq;
    while(match&&i<n){
        if(a[i]=='{'){ 
            sq.top++;
            sq.data[sq.top]=a[i];
        }
        else if(a[i]=='}'){
            if(sq.top==-1){
                return !match;
            }
            if(sq.data[sq.top]=='{'){
                sq.top--;
            }
        }  
        if(a[i]=='['){ 
            sq.top++;
            sq.data[sq.top]=a[i];
        }
        else if(a[i]==']'){
            if(sq.top==-1){
                return !match;
            }
            if(sq.data[sq.top]=='['){
                sq.top--;
            }
        }  
        if(a[i]=='('){ 
            sq.top++;
            sq.data[sq.top]=a[i];
        }
        else if(a[i]==')'){
            if(sq.top==-1){
                return !match;
            }
            if(sq.data[sq.top]=='('){
                sq.top--;
            }
        }
        i++;  
    }
    if(sq.top>=0){
        return !match;
    }
    return match;
}

int main(){
    char a[11]="{";
    cout<<match(a,10);
}
