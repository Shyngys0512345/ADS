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
    string s;
    string t;
    cin >> s >> t;
    string st = t+'#'+s;
    int cnt=0;
    vector<int> v1;
    vector<int> v=prefix(st);
    for(int i=0; i<st.size(); i++){
        if(v[i]==t.size()){
            cnt++;
            int j=i-2*t.size();
            v1.push_back(j+1);
        }
    }
    cout << cnt << endl;
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }
}