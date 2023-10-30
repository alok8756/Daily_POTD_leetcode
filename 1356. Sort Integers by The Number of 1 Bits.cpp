class Solution {
    #include<bits/stdc++.h>
public:
    vector<int> sortByBits(vector<int>& arr) {
       vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            int temp=__builtin_popcount(arr[i]);
           v.push_back(make_pair(temp,arr[i]));
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto ele:v){
        ans.push_back(ele.second);
        }
        return ans;
    }
};