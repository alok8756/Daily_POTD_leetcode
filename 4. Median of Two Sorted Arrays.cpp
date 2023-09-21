class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        vector<int> v;
        for(int i = 0; i < array1.size(); i++)
           v.push_back(array1[i]);
       for(int i = 0; i < array2.size(); i++)
          v.push_back(array2[i]);
          
        sort(v.begin(), v.end());
        int n = v.size();
      if(n%2 == 0)
            return ((double)v[n/2]+(double)v[n/2-1])/2;
     return (double)v[n/2];
    }
};