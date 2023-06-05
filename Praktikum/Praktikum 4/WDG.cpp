#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

vector<int> vis, yes, AdjList[9];
vector<vector<int>> acs;

void init() {
    vector<int> temp;
    for (int i = 0; i < 9; i++) {
        temp.push_back(0);
    }
    for (int i = 0; i < 9; i++) {
        acs.push_back(temp);
        acs[i][i] = 1;
    }
}

int tf(char* a){
    if (!strcmp(a, "A1")) return 0;
    else if (!strcmp(a, "A2")) return 1;
    else if (!strcmp(a, "A3")) return 2;
    else if (!strcmp(a, "B1")) return 3;
    else if (!strcmp(a, "B2")) return 4;
    else if (!strcmp(a, "B3")) return 5;
    else if (!strcmp(a, "C1")) return 6;
    else if (!strcmp(a, "C2")) return 7;
    else if (!strcmp(a, "C3")) return 8;
    else return -1;
}

void dfs(int start) {
    vis[start] = 1;
    yes.push_back(start);

    for (int i = 0; i < yes.size(); i++) { 
        acs[yes[i]][start] = 1;
        acs[start][yes[i]] = 1;
    }

    for (int i = 0; i < AdjList[start].size(); i++) {
        int v = AdjList[start][i];
        if (vis[v] == -1) dfs(v);
    }
}

int main(int argc, char const *argv[]) {
    vis.assign(9, -1);
    init();
    
    int n;
    cin >> n;
    while (n--) {
        char a[3], b[3];
        scanf("%s <-> %s", a, b);
        int c = tf(a), d = tf(b);
        AdjList[c].push_back(d);
        AdjList[d].push_back(c);
    }

    for (int i = 0; i < 9; i++) {
        if (vis[i] = -1) {
            dfs(i);
            yes.clear();
        }
    }

    int res = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!acs[i][j] && !acs[j][i]) {
                acs[i][j] = 1;
                acs[j][i] = 1;
                res++;
            }
        }
    }
    cout << res << endl;

    return 0;
}
