#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    priority_queue<int> pq;

    int n, m;
    cin >> n;
    m = n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if (x == m) {
            while(!pq.empty() && pq.top() == m) {
                cout << pq.top() << ' ';
                pq.pop();
                m--;
            }
        }
        cout << endl;
    }
 
    return 0;
}