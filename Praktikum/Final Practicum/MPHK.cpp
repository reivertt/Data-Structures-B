#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

int n;
void BFS(int y, int x);
vector<vector<int>> v;
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
void print();

int main(int argc, char const *argv[]) {
    int m;
    cin >> n >> m;
    vector<int> temp;
    for(int i = 0; i <= n+1; i++) 
        temp.push_back(0);
    for(int i = 0; i <= n+1; i++) 
        v.push_back(temp);

    while(m--) {
        int x, y;
        cin >> x >> y;
        BFS(y, x);
    }
    print();
    return 0;
}
 
void BFS(int y, int x) {
    queue<pair<int, int>> q;
    v[y][x] = 1;
    q.push({y, x});

    while (!q.empty()) {
 
        pair<int, int> cell = q.front();
        int y = cell.first;
        int x = cell.second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int adjy = y + dRow[i];
            int adjx = x + dCol[i];
            if(adjx > 0 && adjx <= n && adjy > 0 && adjy <= n){
                int a = v[adjy][adjx];
                int b = v[y][x];
                if (v[adjy][adjx] == 0 || a > b+1) {
                    v[adjy][adjx] = v[y][x] + 1;
                    if (v[adjy][adjx] < 4) q.push({ adjy, adjx });
                }
            }
        }
    }
}

void print(){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) 
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}