#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

class DSU {
    int *parent, *rank;
 
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    int find(int i) {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};
 
class Graph {
    vector<vector<int> > edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w) {
        edgelist.push_back({ w, x-1, y-1 });
    }
 
    void kruskals_mst() {
        sort(edgelist.begin(), edgelist.end());
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
 
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                if (ans < w) ans = w;
            }
        }
        cout << ans << endl;
    }
};
 
int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
 
    g.kruskals_mst();
 
    return 0;
}