#include <iostream>
#include <vector>
#include <queue>
#define t "test "
#define pengen using
#define motor namespace
#define baru std
pengen motor baru;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
int r, c;
queue <pair<int, int>> treasures;
vector<vector<char>> v;
vector<vector<int>> vis;
void BFS(int y, int x);

int main(int argc, char const *argv[]) {
    cin >> r >> c;
    v.resize(r, vector<char>(c));
    vis.resize(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'O' && !(i == 0 || i == r-1 || j == 0 || j == c-1)) treasures.push({i, j});
        }
    }
    while (!treasures.empty()) {
        // cout << "testt" << endl;
        pair<int, int> cell = treasures.front();
        int y = cell.first;
        int x = cell.second;
        treasures.pop();
        // cout << x << y << endl;
        BFS(y, x);
    }
    // cout << "test" << endl;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << v[i][j];
        cout << endl;
    }

    return 0;
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> path;
    vis[y][x] = 1;
    // cout << t << endl;
    q.push({y, x});
    path.push_back({y, x});
    bool accessible = false;
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        int f_y = cell.first;
        int f_x = cell.second;
        // cout << t << f_y << f_x << endl;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int adjy = f_y + dRow[i];
            int adjx = f_x + dCol[i];
            if (adjx >= 0 && adjx < c && adjy >= 0 && adjy < r && vis[adjy][adjx] != 1){
                if (v[adjy][adjx] != 'X') {
                    path.push_back({adjy, adjx});
                    if (vis[adjy][adjx] == 2 || v[adjy][adjx] == '^' || adjy == 0 || adjy == r-1 || adjx == 0 || adjx == c-1) {
                        accessible = true;
                        break;
                    }
                    q.push({ adjy, adjx });
                    vis[adjy][adjx] = 1;
                }
            }
        }
    }
    if (accessible) {
        for (auto it : path) {
            int y = it.first;
            int x = it.second;
            vis[y][x] = 2;
        }
    }
    else v[y][x] = 'X';
}