class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>m;
         vector<vector<int>>ans;
        for(int i=0;i<groupSizes.size();i++){
            m[groupSizes[i]].push_back(i);
            if(groupSizes[i]==m[groupSizes[i]].size()){
                ans.push_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }
       
        for(auto&e:m){
            if(e.second.size()>0)
               ans.push_back(e.second);
        }
        return ans;
    }
};