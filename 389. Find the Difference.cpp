class Solution {
public:
    char findTheDifference(string s, string t) {
       s +=t;
       char c=0;
       for(auto&e:s) c ^=e;
       return c;
    }
};