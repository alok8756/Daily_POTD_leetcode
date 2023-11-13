class Solution {
public:
    string sortVowels(string S) {
        string t=S;
        sort(t.begin(),t.end());
        set<char>s;
        s.insert('a'); s.insert('e'); s.insert('i');s.insert('o'); s.insert('u');
        s.insert('A'); s.insert('E');s.insert('I'); s.insert('O');s.insert('U'); 
        vector<char>ans;
        for(auto&e:t){
            if(s.find(e)!=s.end())
                  ans.push_back(e);
         }
         int index=0;
        for(int i=0;i<S.length();i++){
            if(s.find(S[i])!=s.end()){
                 S[i]=ans[index++];
            }
        }
        return S;
    }
};