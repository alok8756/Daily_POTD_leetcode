typedef pair<int, int> pii;
#define INF INT_MAX
class Graph {
    vector<vector<pair<int,int>>> adj;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges){
        this->n = n;
        adj = vector<vector<pair<int,int>>> (n);
        for(auto val : edges){
            adj[val[0]].push_back({val[1],val[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int helper(int source,int dest){
        vector<int> dist(n , INF);
        vector<bool> vis(n , false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (vis[u]) continue;
            vis[u] = true;

            for (auto v : adj[u]) {
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }

        if (dist[dest] == INF) {
            return -1;
        } else {
            return dist[dest];
        }
    }
    
    int shortestPath(int node1, int node2) {
        return helper(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */