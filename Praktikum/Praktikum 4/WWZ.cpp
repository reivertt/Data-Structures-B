#include <iostream>
#include <vector>
#include <stack>
#define ull unsigned long long
#define we using
#define bare namespace
#define bears std
we bare bears;

void dfs(vector<ull> adjList[], ull n, ull start){
    if (n == 1) {
        std::cout << "0" << endl;
        return;
    }

    vector<bool> visited(n, false);
    stack<ull> st;
    int iter = 0;
    st.push(start);
    visited[start] = true;

    while(!st.empty()){
        ull temp = st.top();
        st.pop();
        int neighboor = 0, virus = 1;

        if(!visited[temp]){
            visited[temp] = true;
            iter++;
        }

        for(auto it:adjList[temp]){
            if (!visited[it]){
                st.push(it);
                neighboor++;
            }
        }

        while (virus <= neighboor) {
            virus *= 2; 
            iter++; 
        }
        
    }

    std::cout << iter << endl;
}

int main(int argc, char const *argv[]) {
    ull n;
    cin >> n;
    vector<ull> edges[n];
    vector<bool> visited(n, false);

    for (int i = 0; i < n - 1; i++) {
        ull a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(edges, n, 0);
    
    return 0;
}
