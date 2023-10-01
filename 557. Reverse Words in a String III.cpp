class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(auto&e:s){
            if(e==' '){
               reverse(temp.begin(),temp.end());
                ans +=temp;
                ans +=" ";
                temp="";
            }
          else temp +=e;
        }
         reverse(temp.begin(),temp.end());
          ans +=temp;
        return ans;
    }
};