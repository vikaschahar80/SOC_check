class Solution {
public:
int dp[2000];
int solve(int i,int n,vector<int>& cost)
{
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=1e9;
    ans=cost[n-1-i]+min(solve(i-1,n,cost),solve(i-2,n,cost));
    return dp[i]=ans;
}
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        int n=cost.size();
        return min(solve(n-1,n,cost),solve(n-2,n,cost));
    }
};