#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        int n,k;
        cin>>n;
        cin>>k;
        string s;

        cin>>s;
        int count = 0;
        for (size_t j = 0; j < n;)
        {
            if(s[j]=='B'){
                for(int z = 0;z<k ;z++){
                    s[j+z] = 'W';
                }
                j = j+k;
                count++;
            }
            else{
                j++;
            }
        }
        cout<<count<<endl;

    }

}
