#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;
 
bool valdi(string strin) {
    stack<char> temp;

    for (unsigned i = 0; i < strin.length(); i++) {
        // if (i == 0 || i == strin.length() - 1) continue; //! im losing it
        // if (temp.top() == '\"') temp.pop();
        if (temp.empty())
            temp.push(strin[i]);
        else if ((temp.top() == '(' && strin[i] == ')') || (temp.top() == '{' && strin[i] == '}') || (temp.top() == '[' && strin[i] == ']')) 
            temp.pop();
        else 
            temp.push(strin[i]);
    }
    if (temp.empty()) return true;
    else return false;
}
 
int main(int argc, char const *argv[]) {
    string S, equal, strin;
    // char a;
    // cin >> S >> equal >> strin;
    // strin.erase(0,1);
    // cout << strin << endl;
    cin >> strin;
    (valdi(strin)) ? cout << "valdi" : cout << "unvaldi";
    return 0;
}