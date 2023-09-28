class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        multiset<int>s1,s2;
        for(auto&e:nums){
            if(e&1) s2.insert(e);
            else s1.insert(e);
        }
        vector<int>ans;
        for(auto&e:s1) ans.push_back(e);
        for(auto&e:s2) ans.push_back(e);
        return ans;
    }
};