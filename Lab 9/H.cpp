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
    cin >> s;
    vector<int> v = prefix(s);
    int cnt=0;
    for(int i=1; i<s.size()-1; i++){
        int n=i+1;
        int size=n-v[i];
        if(size!=0 && n%size==0){
            int res = n/size;
            if(res%2==0){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}