class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string A="",B="";
        for(auto e:word1)  A+=e;
         for(auto e:word2)  B+=e;
         return A==B;
    }
};