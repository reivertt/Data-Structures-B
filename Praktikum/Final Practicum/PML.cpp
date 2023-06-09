#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    list <int> list1, list2, res;
    while (n--) {
        int num;
        cin >> num;
        list1.push_back(num);
    }
    while (m--) {
        int num;
        cin >> num;
        list2.push_back(num);
    }
    
    int wan = list1.size(), tu = list2.size();
    int sum = 0, carry = 0;
    for (int i = 0; i < max(wan, tu); i++) {
        if (!list1.empty() && !list2.empty()) {
            sum = carry + list1.back() + list2.back();
            carry = sum / 10;
            res.push_back(sum % 10);
            list1.pop_back();
            list2.pop_back();
        }
        else if (!list1.empty()){
            sum = carry + list1.back();
            carry = sum / 10;
            res.push_back(sum % 10);
            list1.pop_back();
        }
        else if (!list2.empty()){
            sum = carry + list2.back();
            carry = sum / 10;
            res.push_back(sum % 10);
            list2.pop_back();
        }
    }
    while (carry > 0) {
        res.push_back(carry);
        carry /= 10;
    }
    while (!res.empty()) {
        cout << res.back();
        res.pop_back();
    }

    return 0;
}
