#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b+c)- min(a,min(b,c))>=10){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
}
