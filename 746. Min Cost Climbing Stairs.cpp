class Solution {
public:
   int solve(vector<int> a, int i, vector<int>&dp){
          if(i<=1)   
             return dp[i] = a[i];
        if(dp[i]!=-1)   
             return dp[i];
        int pick =  solve(a, i-1, dp);
        int nonpick = solve(a, i-2, dp);

        return dp[i] = a[i] + min(pick, nonpick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    }
};