#include <iostream>
#include <vector>
#define we using
#define bare namespace
#define bears std
we bare bears;

int r, c;
vector<string> vil;
int dfs(int y, int x);

int main(int argc, char const *argv[]) {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string temp;
        cin >> temp;
        vil.push_back(temp);
    }
    
    // cout << vil.size() << " " << vil[0].size() << endl;

    // cout << dfs(0,0) << endl;

    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cout << vil[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0, solve = dfs(0, 1), weird = dfs(1, 0);
    
    if (solve && weird) ans = 2;
    else if (solve || weird) ans = 1;
    
    cout << ans << endl;

    return 0;
}

int dfs(int y, int x) {
    if (y == r-1 && x == c-1) return 1;
    if (y < 0 || y >= r || x < 0 || x >= c) return 0;
    if (vil[y][x] == '#') return 0;

    int sum = 0;
    vil[y][x] = '#';
    
    sum |= dfs(y, x+1);
    if (sum) return 1;

    sum |= dfs(y+1, x);
    return sum;
}