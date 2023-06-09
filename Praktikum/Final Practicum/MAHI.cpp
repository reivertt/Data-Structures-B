#include <bits/stdc++.h>
using namespace std;

struct graph {
    int vertexCount, edgeCount;
    vector<map<int, int>> adjList;

    void init(int v) {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++) {
            adjList.push_back({});
        }
    }

    void addEdge(int v1, int v2, int w) {
        adjList[v1].insert(make_pair(v2, w));
        adjList[v2].insert(make_pair(v1, w));
        edgeCount++;
    }

    void djikstra(vector<int>& result, int src) {
        vector<bool> visited(vertexCount, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        result = vector<int>(vertexCount, INT32_MAX);

        pq.push(make_pair(0, src));
        result[src] = 0;

        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();

            if (visited[u.second]) continue;

            visited[u.second] = true;

            for (auto vertex : adjList[u.second]) {
                int nextVertex = vertex.first;
                int weight = vertex.second;

                if (u.first + weight < result[nextVertex]) {
                    result[nextVertex] = u.first + weight;
                    pq.push(make_pair(result[nextVertex], nextVertex));
                }
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    int v;
    cin >> v;
    map<int, pair<string, int>> store;
    int i = 1, a = v;
    while (a--) {
        string s;
        int p;
        cin >> s >> p;
        store.insert({p, {s, i}});
        i++;
    }
    
    graph g;
    g.init(v+1);
    
    int e;
    cin >> e;
    while (e--) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.addEdge(v1, v2, w);
    }
    
    int w;
    cin >> w;

    vector<int> result;
    g.djikstra(result, 0);

    for (auto it = store.begin(); it != store.end(); it++) {
        if (result[it->second.second] <= w) {
            cout << "hari ini makan di " << it->second.first;
            break;
        }
    } 

    return 0;
}
