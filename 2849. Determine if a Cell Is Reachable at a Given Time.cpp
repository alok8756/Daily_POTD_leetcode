class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t){
        if(sx==fx and sy==fy) return t!=1;
        return max(abs(fx-sx),abs(fy-sy))<=t;
    }
};