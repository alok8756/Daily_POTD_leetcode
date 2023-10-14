class Solution {
public:
     int helper(int i, int n, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if (walls <= 0)
            return 0;

        if (i >= n)
            return 2000000000;
        
        if (dp[i][walls] != -1)
            return dp[i][walls];
    
        int take = cost[i] + helper(i + 1, n, walls - time[i] - 1, cost, time, dp);
        int dontTake = helper(i + 1, n, walls, cost, time, dp);
        return dp[i][walls] = min(take, dontTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return helper(0, n, n, cost, time, dp);
    }  
};