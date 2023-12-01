#include <bits/stdc++.h>

using namespace std;

long long Range = 1e9 + 7;
long long P = 31;

long long getHash(string & s) {
    long long hash = 0;
    long long curP = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curP % Range;
        hash = (hash + curHash) % Range;
        curP = (curP * P) % Range;
    }
    return hash;
}

vector<long long> getPrefix(string & s) {
    vector<long long> hash(s.size());
    long long curP = 1;
    for (int i = 0; i < s.size(); i++) {
        hash[i] = (s[i] - 'a' + 1) * curP % Range;
        if (i != 0) {
            hash[i] = (hash[i] + hash[i - 1]) % Range;
        }
        curP = (curP * P) % Range;
    }
    return hash;
}

void rabinKarp(string & s, pair<string, int> & t, int &mx) {
    if (t.first.size() > s.size()) return;
    long long smallHash = getHash(t.first);
    vector<long long> hash = getPrefix(s);
    for (int i = 0; i < s.size() - t.first.size() + 1; i++) {
        long long hashDif = hash[i + t.first.size() - 1];
        if (i != 0) hashDif -= hash[i - 1];
        if (hashDif < 0) hashDif += Range;
        if (i != 0) smallHash = (smallHash * P) % Range;
        if (smallHash == hashDif){
            t.second++;
            mx=max(mx, t.second);
        }
    }

}

int main() {
    while(true){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        pair<string, int> v[n];
        for(int i=0; i<n; i++){
            cin >> v[i].first;
            v[i].second=0;
        }
        string s;
        cin >> s;
        int mx=-99999;
        for(int i=0; i<n; i++){
            rabinKarp(s, v[i], mx);
        }
        cout << mx << endl;
        for(int i=0; i<n; i++){
            if(v[i].second==mx){
                cout << v[i].first << endl;
            }
        }
    }
}