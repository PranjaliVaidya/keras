#include <iostream>
using namespace std;


int fib(int n){
    if(n==0 ||n==1){
        return n;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main()
{
    int n;

    cout<<"Enter n :";
    cin>>n;
    cout<<"Fibonachi series with recursion :"<<endl;
    for(int i=0;i<n;i++){
        cout<<fib(i)<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Fibonachi series without_recursion :"<<endl;
    int c1=0,c2=1,c3;
    cout<<c1<<" "<<c2<<" ";
    for(int i=2;i<n;i++){
        c3=c1+c2;
        c1=c2;
        c2=c3;
        cout<<c3<<" ";
    }    
    return 0;
}

