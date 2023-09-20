class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int ans=0,sum=0,n=nums.size();
         int totalSum=0;
         int mini=INT_MAX;
         for(auto&e:nums){
             totalSum +=e;
             mini=min(mini,e);
         }
         if(mini>x || totalSum<x) return -1;
      int k=totalSum-x;
        map<int,int>m;
      for(int i=0;i<n;i++){
           sum +=nums[i];
          if(sum==k) ans=i+1;
          if(m.find(sum)==m.end()) m[sum]=i;
          if(m.find(sum-k)!=m.end()) ans=max(ans,i-m[sum-k]);
      }
      return (n-ans)>=0? (n-ans): -1;
    }
};