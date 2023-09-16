class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});

    
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == n - 1 && y == m - 1) {
                return diff;
            }
       
            for (int i = 0; i < 4; i++) {
                int newr = x + direction[i][0];
                int newc = y + direction[i][1];

              
                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                  
                    int w = max(abs(heights[x][y] - heights[newr][newc]), diff);
                    if (w < dis[newr][newc]) {
                        dis[newr][newc] = w;
                        pq.push({w, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};