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

int main(){
    int n;
    cin >> n;
    while(n--){
        string t; int x;
        cin >> t >> x;
        vector<int> v=prefix(t);
        cout << (t.size()-v[v.size()-1])*x + v[v.size()-1] << endl;
    }
}