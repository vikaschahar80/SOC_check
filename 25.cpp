#include<iostream>
#include<vector>
using namespace std;
void solve(int x,int l,int r,vector<int> &a){
    int max = 0;
    for(int i=l;i<=r;i++){
        if((x^i) > max){
            max  = x^i;
        }
    }
    a.push_back(max);
}
int main(){
    int n;
    cin>>n;
    vector<int> a;

    for(int i=0;i<n;i++){
        int x,l,r;
        cin>>x>>l>>r;
        solve(x,l,r,a);

    }
    for(int j= 0;j<n;j++){
        cout<<a[j]<<endl;
    }
}
