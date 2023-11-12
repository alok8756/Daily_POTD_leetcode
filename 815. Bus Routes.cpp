class Solution {
public:
        int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        queue<pair<int, int>>q;
        q.push({S, 0});
        unordered_set<int> seen = {S};
        while (!q.empty()) {
            int stop = q.front().first;
            int bus =  q.front().second;
            q.pop();
            if (stop == T)
                return bus;
            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        q.push({j, bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};