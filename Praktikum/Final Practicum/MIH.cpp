#include <bits/stdc++.h>
using namespace std;

int items(int a[], int n) {
	priority_queue<int> pq;
	map<int, int> freq;

	int count = 0;
	for (int i = 0; i < n; ++i) 
        freq[a[i]]++;

	for (auto itr = freq.begin(); itr != freq.end(); itr++) 
        pq.push(itr->second);

	while (pq.size() > 1) {
		int freq1 = pq.top();
		pq.pop();

		int freq2 = pq.top();
		pq.pop();

		count++;
		freq1--;
		freq2--;

		if (freq1 > 0) pq.push(freq1);
		if (freq2 > 0) pq.push(freq2);
	}
	return count;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        int listofitems[a];
        for (int i = 0; i < a; i++) {
            int b;
            cin >> b;
            listofitems[i] = b;
        }
        cout << a - (items(listofitems, a) * 2) << endl;
    }

	return 0;
}