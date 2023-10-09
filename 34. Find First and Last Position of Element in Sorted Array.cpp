class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x){
        int n=arr.size();
         int s=0,e=n-1;
    int ans1=-1,ans2=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            ans1=mid;
            e=mid-1;
        }
        else if(arr[mid]<x) s=mid+1;
        else e=mid-1;
    }
    s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            ans2=mid;
            s=mid+1;
        }
        else if(arr[mid]<x) s=mid+1;
        else e=mid-1;
    }
    return {ans1,ans2};
    }
};