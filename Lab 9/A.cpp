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
    string s, t;
    cin >> s >> t;
    string st=s;
    int cnt=1;
    while(st.size()<t.size()){
        st+=s;
        cnt++;
    }
    bool ok = false;
    string res=t+'#'+st;
    vector<int> v = prefix(res);
    for(int i=0; i<res.size(); i++){
        if(v[i]==t.size()){
            ok=true;
        }
    }
    if(ok==true){
        cout << cnt << endl;
        return 0;
    } else {
        vector<int> v1 = prefix(res+s);
        for(int i=0; i<v1.size(); i++){
            if(v1[i]==t.size()){
                ok=true;
            }
        }
        if(ok==true){ 
            cout << cnt+1 << endl;
            return 0;
        } else {
            cout << -1 << endl;
        }
    }
}