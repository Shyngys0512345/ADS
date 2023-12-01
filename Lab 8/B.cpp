#include <bits/stdc++.h>

using namespace std;

long long Range = 1e9 + 7;
long long P = 31;
map <int, int> mp;
int cnt = 0;

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

void rabinKarp(string & s, string & t) {
    if (t.size() > s.size()) return;
    long long smallHash = getHash(t);
    vector<long long> hash = getPrefix(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hash[i + t.size() - 1];
        if (i != 0) hashDif -= hash[i - 1];
        if (hashDif < 0) hashDif += Range;
        if (i != 0) smallHash = (smallHash * P) % Range;
        if (smallHash == hashDif){
            if (mp.find(i) != mp.end()) {
                cnt++;
            }
            mp[i] = 1;
        }
    }

}

int main() {
    string s, t, str;
    cin >> s >> t >> str;
    rabinKarp(s, str);
    rabinKarp(t, str);
    cout << cnt << endl;
}