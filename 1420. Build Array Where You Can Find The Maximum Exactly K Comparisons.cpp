class Solution {
public:
     int table[51][101][51]={0};
     const int mode = 1000000007;

    int lookUp(const int n, const int m, const int k){
        if(k < 1 || n < k || m < k) return 0;
        if(n == 1 && k == 1) return m;
        if(table[n][m][k] != 0) return table[n][m][k] - 1;
        
        long long case1 = lookUp(n, m - 1, k);
        long long case2 = lookUp(n - 1, m - 1, k - 1);
        long long case3 = mode + lookUp(n - 1, m, k) - lookUp(n - 1, m - 1, k);
		
        int ans = (case1 + case2 + case3 * m) % mode;
        table[n][m][k] = ans + 1;
        return ans;
    }
    inline int numOfArrays(const int n, const int m, const int k) {
        return lookUp(n, m, k);
    }
};
