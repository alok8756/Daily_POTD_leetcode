class Solution {
public:
    int minDeletions(string s) {
        map<char,int>m;
        for(auto&e:s)m[e]++;
        set<int>st;
        int count=0;
        for(auto&e:m){
            if(st.find(e.second)==st.end()){
                st.insert(e.second);
            }
            else{
                int freq=e.second;
                while(st.find(freq)!=st.end()){
                    freq--;
                    count++;
                    if(freq==0) break;
                }
                if(freq>0) st.insert(freq);
            }
        }
        return count;
    }
};