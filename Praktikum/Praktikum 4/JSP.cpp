#include <iostream>
#include <vector>
#define we using
#define bare namespace
#define bears std
we bare bears;

int r, c, sum = 0, cheese = 0;
vector<string> vil;
vector<vector<bool>> visited;
int dfs(int y, int x);

int main(int argc, char const *argv[]) {
    cin >> r >> c;
    visited.resize(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        string temp;
        cin >> temp;
        vil.push_back(temp);
    }
    
    // cout << visited.size() << " " << visited[0].size() << endl;

    // cout << dfs(0,0, &cheese) << endl;

    int ans = 0, solve = dfs(0, 0);
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    visited[0][0] = false;
    int weird = dfs(0, 0);
    if (!solve) {
        ans = 0;
    }
    else if (!weird) ans = 1;
    else {
        if (vil[r-2][c-1] == '.') ans++;
        if (vil[r-1][c-2] == '.') ans++;
    }
    cout << ans << endl;

    return 0;
}

int dfs(int y, int x) {
    if (y < 0 || y >= r || x < 0 || x >= c) return 0;
    if (visited[y][x]) return 0;
    if (vil[y][x] == '#') return 0;

    visited[y][x] = true;

    sum += dfs(y, x+1);
    sum += dfs(y+1, x);

    if (y == r-1 && x == c-1) sum = 1;
    return sum;
}