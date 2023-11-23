class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for (auto i = 0, j = 0; i < l.size(); ++i) {
        vector<int>v(nums.begin() + l[i], nums.begin() + r[i] + 1);
        sort(v.begin(),v.end());
        for (j = 2; j < v.size(); ++j)
            if (v[j] - v[j - 1] != v[1] - v[0])
                break;
        res.push_back(j == v.size());
    }
    return res;
}
};