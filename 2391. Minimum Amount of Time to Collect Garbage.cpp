class Solution 
{
public:
    int garbageCollection(vector<string>& gar, vector<int>& time){
        int cnt=0;
        int last_g=0, last_p=0, last_m=0;
        for(int i=0; i<gar.size(); i++){
            for(auto it:gar[i]){
                if(it=='M') last_m=i;
                else if(it=='P') last_p=i;
                else last_g=i;
                cnt++; 
            }
        }
        int ans=cnt;
        int sum=0;
        for(int i=0; i<time.size(); i++){
            sum += time[i];
            if(last_g==i+1) ans += sum;
            if(last_p==i+1) ans += sum;
            if(last_m==i+1) ans += sum;   
        }
        return ans;
    }
};