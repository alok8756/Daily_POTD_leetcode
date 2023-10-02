class Solution {
public:
     bool winnerOfGame(string s) {
        int c=0,n=s.size();
        for(int i=0;i<n-2;i++){
            if(s[i]=='A' && s[i+1]=='A' && s[i+2]=='A') c++;
            else if(s[i]=='B' && s[i+1]=='B' && s[i+2]=='B') c--;
        }
        return c>0;
    }
};