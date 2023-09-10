class Solution {
public:
  int M=1e9+7;
    int countOrders(int n) {
        long long ans=1;
        if(n==1)
        return 1;
        for(int i=2;i<=n;i++){
            int space=(2*i)-1;
            int totalWay=(space*(space+1))/2;
            ans *=totalWay;
            ans %=M;
        }
        return ans;
    }
};