class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        for(int i=0;i<mat.size();i++){
            int s=0,e=mat[i].size()-1;
            int index=0;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(mat[i][mid]==1){
                    index=mid+1;
                    s=mid+1;
                }
                else if(mat[i][mid]==0) 
                 e=mid-1;
            }
          ans.push_back({index,i});
        }
        vector<int>res(k,0);
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++) res[i]=ans[i].second;
        return res;
    }
};