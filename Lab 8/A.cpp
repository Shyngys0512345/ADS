#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
long long P=11;

string gethash(string &s){
    long long curP=1;
    long long hash=0;
    for(int i=0; i<s.size(); i++){
        hash=(hash+((s[i]-47)*curP)%MOD)%MOD;
        curP=(curP*P)%MOD;
    }
    return to_string(hash);
}

int main() {
    int n;
    cin >> n;
    vector<string>v;
    map<string, string> mp;
    for(int i=0; i<n*2; i++){
        string s;
        cin >> s;
        v.push_back(s);
        mp[s]=gethash(s);
    }
    int cnt=0;
    for(int i=0; i<v.size(); i++){
        if (mp.find(gethash(v[i])) != mp.end()) {
            cout << "Hash of string " << " \"" << v[i] << "\"" << " is " << gethash(v[i]) << endl;
            cnt++;
        }
        if(cnt==n) break;
    }

}