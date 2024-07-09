#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    int arr[50][2];
    for (size_t j = 0; j < t; j++)
    {
        int n;
        cin>>n;
        for (size_t i = 0; i < n; i++){
        cin>>arr[i][1]>>arr[i][2];
        }
        int cutcount = 0;
        for (size_t i = 0; i < n; i++){
            if(arr[i][1]>arr[i][2]){
                cutcount++;
            }
        }
        cout<<cutcount<<endl;
    }
    
    
    
}