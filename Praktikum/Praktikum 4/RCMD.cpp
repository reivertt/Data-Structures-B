#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

/*
map yg isinya edgelist tp namanya itu book / weight
*/

map<string, vector<vector<string>>> somthin;

int getIndex(vector<string> &a, string input) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == input) {
            return i;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n;
    while (n--) {
        char c_from[11], c_item[11], c_to[11];
        scanf("%s recommended %s to %s", c_from, c_item, c_to);
        string from(c_from), item(c_item), to(c_to);
        if (somthin.find(item) != somthin.end()) {
            vector<vector<string>> temp;
            // somthin.insert(item, temp);
        }
    }
    
    cin >> m;
    while (m--) {
        string target;
        cin >> target;
    }

    return 0;
}