#include <bits/stdc++.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

int main(int argc, char const *argv[]) {
    int n, q;
    cin >> n >> q;
    map<string, pair<string, map<string, vector<string>> >> mail;
    while (n--) {
        map<string, vector<string>> mailbox;
        string ip, name;
        cin >> ip >> name;
        mail[ip] = make_pair(name, mailbox);
    }

    // if name exists, nanti kyknya bakal utak atik di output deh
    //else skip
    while (q--) {
        string ip_f, ip_t, message;
        cin >> ip_f >> ip_t;
        cin.ignore();
        getline(cin, message);
        //find if target and sender exists
        if (mail.find(ip_f) != mail.end() && mail.find(ip_t) != mail.end()) {
            //so no duplicates arise
            if (mail[ip_t].second.find( ip_f ) != mail[ip_t].second.end()){
                mail[ip_t].second[ ip_f ].push_back(message);
            } else {
                vector<string> temp;
                temp.push_back(message);
                mail[ip_t].second[ ip_f ] = temp;
            }
        }
    }

    for (auto it = mail.begin(); it != mail.end(); ++it) {
        if (it->second.second.empty()) continue;
        cout << "===========" << endl;
        cout << "Mail: " << it->second.first << endl;
        for (auto it2 = it->second.second.begin(); it2 != it->second.second.end(); ++it2) {
            cout << "From: " << mail[it2->first].first << endl;
            for (auto it3 = it2->second.begin(); it3 != it2->second.end(); ++it3) {
                cout << ">> " << *it3 << endl;
            }
        }
    }

    return 0;
}
