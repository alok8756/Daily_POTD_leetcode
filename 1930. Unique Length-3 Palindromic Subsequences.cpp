class Solution {
public:
    int countPalindromicSubsequence(string s) {     
        int n = s.length(), ans = 0;
        vector <int> f(26,0);
        for(int i = 0; i < n; i++) 
            f[s[i]-'a']++;
        
        for(int i = 0; i < 26; i++){    
            if (f[i] <= 1)
                continue;
            int first=-1, last=-1; 
            for(int j=0;j<n;j++){ 
                if((s[j]-'a')==i){
                    first=j; break;
                }
            }
            for(int j=n-1;j>=0;j--){ 
                if((s[j]-'a')==i){
                    last=j; break;
                }
            }  
            unordered_set<int> st; 
            for(int k=first+1;k<last;k++){
                st.insert((s[k]-'a'));
            }
            ans+=st.size(); 
        }
        return ans;
    }
};