#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[]) {
    list<int> queue;
    bool visited[v];
 
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (unsigned i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
                
                if (adj[u][i] == dest) return true;
            }
        }
    }
 
    return false;
}
 
void shortestPath(vector<int> adj[], int s, int dest, int v) {
    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "RIP LAPET 2023";
        return;
    }
 
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    cout << dist[dest]+1 << endl;

    int f = 0;
    for (unsigned i = path.size() - 1; i >= 0; i--){
        cout << path[i]+1 << " ";
        f++;
        if (f > dist[dest]) break;
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> edges[n];
    vector<bool> visited(n, false);
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    shortestPath(edges, 0, n-1, n);
    return 0;
}