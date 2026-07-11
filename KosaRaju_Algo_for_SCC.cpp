class Solution {
public:
    void dfs1(int node, vector<vector<int>>& adj,
              vector<int>& vis, stack<int>& st) {
        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs1(nei, adj, vis, st);
        }

        st.push(node); // finish time order
    }

    void dfs2(int node, vector<vector<int>>& revAdj,
              vector<int>& vis, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);

        for (int nei : revAdj[node]) {
            if (!vis[nei])
                dfs2(nei, revAdj, vis, component);
        }
    }

    vector<vector<int>> kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> vis(V, 0);

        // Step 1: Topological-like ordering by finish time
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs1(i, adj, vis, st);
        }

        // Step 2: Reverse the graph
        vector<vector<int>> revAdj(V);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                revAdj[v].push_back(u);
            }
        }

        // Step 3: DFS on reversed graph in stack order
        fill(vis.begin(), vis.end(), 0);

        vector<vector<int>> sccs;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                vector<int> component;
                dfs2(node, revAdj, vis, component);
                sccs.push_back(component);
            }
        }

        return sccs;
    }
};
