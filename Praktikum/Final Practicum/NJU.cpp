#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define pengen using
#define motor namespace
#define baru std
pengen motor baru;

struct graph {
    int vertexCount, edgeCount;
    vector<set<int>> adjList;

    void init(int v) {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++) {
            adjList.push_back({});
        }
    }

    void addEdge(int v1, int v2) {
        adjList[v1].insert(v2);
        edgeCount++;
    }

    void BFS(int src) {
        vector<bool> visited(vertexCount, false);
        vector<int> dist(vertexCount, (int)(1e9));
        queue<int> q;
        dist[src] = 0;
        int ans = INT32_MAX;
        visited[src] = true;
        q.push(src);
    
        while (!q.empty()) {
            int s = q.front();
            cout << s << " ";
            q.pop();
    
            for (auto child : adjList[s]) {
                if (visited[child] && child == s) {
                    ans = min(ans, ans/*ini bakal diganti*/);
                }
                else if (!visited[child]) {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
        if (ans == INT32_MAX) cout << "gak bisa pulang mamah" << endl;
        else cout << ans << endl;
    }

    int bfs(int self) {
        vector<bool> visited(vertexCount, false);
        queue<pair<int, int>> q;

        q.push(make_pair(self, 0));

        while (!q.empty()) {
            int temp = q.front().first;
            int dis = q.front().second;
            q.pop();

            for (auto it : adjList[temp]) {
                if (!visited[it]) {
                    q.push({it, dis + 1});
                    visited[it] = true;
                    if (it == self) {
                        return dis + 1;
                    }
                }
            }
        }
        return INT32_MAX;
    }

    // void shortest_cycle() {
    //     int ans;
    //     for (int i = 0; i < vertexCount; i++) {
    //         ans = INT32_MAX;
    //         vector<int> dist(vertexCount, (int)(1e9));
    //         vector<int> par(vertexCount, -1);
    //         dist[i] = 0;
    //         queue<int> q;
    //         q.push(i);
    
    //         while (!q.empty()) {
    //             int x = q.front();
    //             q.pop();
    //             for (int child : adjList[x]) {
    //                 if (dist[child] == (int)(1e9)) {
    //                     dist[child] = 1 + dist[x];
    //                     par[child] = x;
    //                     q.push(child);
    //                 }
    //                 else if (par[x] != child and par[child] != x)
    //                     ans = min(ans, dist[x] + dist[child] + 1);
    //             }
    //         }
    //         if (ans == INT32_MAX) cout << "gak bisa pulang mamah" << endl;
    //         else cout << ans << endl;
    //     }
    
    // }

};


int v;
int main(int argc, char const *argv[]) {
    cin >> v;
    graph g;
    g.init(v);
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        g.addEdge(a, b);
    }

    // g.shortest_cycle();
    for (int i = 0; i < v; i++) {
        int ans = g.bfs(i);
        if (ans == INT32_MAX) cout << "gak bisa pulang mamah" << endl;
        else cout << ans << endl;
    }
   
    return 0;
}