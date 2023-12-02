class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> chFreq;
        for(auto ch : chars){
                   chFreq[ch]++;
        }
        bool flag = true;
        int ans=0;
        for(auto str : words){
            flag = true;
            unordered_map<char,int> copyFreq;
            for(auto ch : str) copyFreq[ch]++;
            for(auto ch : str){ 
                if(copyFreq[ch] > chFreq[ch]) 
                       flag = false;
            }
            if(flag) ans += str.size();
        }
        return ans;
    }
};