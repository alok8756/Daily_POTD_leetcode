class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3){
            return 0;
        }
        
        stack<int> st;
        int third = INT_MIN;

        for (int i=n-1; i>=0; i--){
            int currEle = nums[i];
            if (currEle < third){
                return true;
            }
            while (!st.empty() && st.top() < currEle){
                third = st.top();
                st.pop();
            }
            st.push(currEle);
        }

        return false;
    }
};