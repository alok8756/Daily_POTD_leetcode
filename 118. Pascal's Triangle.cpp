class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        for(int line=0;line<n;line++){
            for(int j=0;j<=line;j++){
                if(j==0 or j==line) ans[line].push_back(1);
                else{
                    ans[line].push_back(ans[line-1][j-1]+ans[line-1][j]);
                }
            }
        }
        return ans;
    }
};