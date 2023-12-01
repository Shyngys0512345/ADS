#include <bits/stdc++.h>
using namespace std;

long long p=2;
long long pows[52];

int main() {
    pows[0] = 1;
    for (int i = 1; i <= 51; i ++){
        pows[i] = pows[i - 1] * p;
    }
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++){
        long long x; cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i ++){
        if (i!=0){
            cout << char((v[i] - v[i - 1]) / pows[i] + 'a');
        } else {
            cout << char(v[i] / pows[i] + 'a');
        }
    }
}