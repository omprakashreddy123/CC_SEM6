#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        stack<int> st;
        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    st.push(neigh);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for (auto conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;    }
        }
        return components - 1;
    }
};
