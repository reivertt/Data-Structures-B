#include <iostream>
#include <stack>
#define t "test "
#define pengen using
#define motor namespace
#define baru std
pengen motor baru;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    stack <int> cable;
    while (n--) {
        int op;
        cin >> op;
        if (op) {
            // cout << t << cable.size() << endl;
            if (cable.empty()) {
                cable.push(1);
                cable.push(0);
            }
            else {
            // cout << t << cable.size() << endl;
                if (cable.top() == 1 && cable.size() >= 1) cable.pop();
                else if (!cable.empty() && !cable.top()) {
                    if (cable.size() == 1) continue;
                    else {
                        cable.pop();
                        cable.push(1);
                        cable.push(0);
                        cable.push(1);
                        cable.push(0);
                    }
                }
            }
        }
        else {
            // cout << t << cable.size() << endl;
            if (cable.empty()) cable.push(0);
            else if (!cable.empty() && cable.size() >= 1) {
                if (cable.top() == 1) cable.push(0);
                else cable.pop();
            }
        }
        // cout << t << cable.size() << endl;
    }
    cout << cable.size();
    return 0;
}
