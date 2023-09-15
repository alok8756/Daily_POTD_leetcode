class Solution {
public:

  int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
 }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<pair<int, pair<int, int>>> edges; 
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
    int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dis, {i, j}});
            }
        }
        sort(edges.begin(), edges.end()); 
        vector<int> parent(n);
       
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        int minCost = 0; 
        int numEdges = 0; 

        for (auto edge : edges) {
            int dis = edge.first; 
            int u = edge.second.first;
            int v = edge.second.second; 
            int pU = findParent(parent, u); 
            int pV = findParent(parent, v); 
            if (pU != pV) {
                parent[pU] = pV; 
                minCost += dis; 
                numEdges++; 
            }
           
            if (numEdges == n - 1) {
                break;
            }
        }
        return minCost;
    }

};