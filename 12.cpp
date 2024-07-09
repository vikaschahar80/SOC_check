class Solution {
private:
void solve(int n, int k,int i,vector<vector<int>> &ans,vector<int> &output){
    if(i>n){
        if(output.size()==k){
        ans.push_back(output);
        }
        return;
    }
    if(output.size()==k){
        ans.push_back(output);
        return;
    }
    solve(n,k,i+1,ans,output);
    output.push_back(i);
    solve(n,k,i+1,ans,output);
    output.pop_back();

}
public:
    vector<vector<int>> combine(int n, int k) {
        int i =1;
        vector<vector<int>> ans;
        vector<int> output;
        solve(n,k,i,ans,output);
        return ans;
    }
};
