#include <bits/stdc++.h>
using namespace std;

vector<int>prefix(string s){
    int n = (int) s.length();
    vector<int> pi(n);
    for(int i=1; i<n; i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) ++j;
        pi[i]=j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    s[0] += 32;
    int n;
    cin >> n;
    vector<string> v2;
    vector< pair <string, int> > res;
    int maxi=-1;
    while(n--){
        string t;
        string st="";
        cin >> t;
        t[0] += 32;
        st=t+s;
        vector<int> v = prefix(st);
        t[0] -= 32;
        maxi=max(maxi, v[v.size() - 1]);
        res.push_back({t, v[v.size()-1]});
        st = "";
    }
    for(int i=0; i<res.size(); i++){
        if(res[i].second==maxi){
            v2.push_back(res[i].first);
        }
    }

    if(maxi==0){
        cout << 0 << endl;
        return 0;
    } else {
        cout << v2.size() << endl;
        for(int i = 0; i < v2.size(); i++){
            cout << v2[i] << endl;
        }
    }  
    return 0;
}