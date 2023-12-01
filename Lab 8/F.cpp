#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e15+9;
long long P=31;

void getHash(string &s){
    unordered_map<unsigned long long, bool> mp;    
    for(int i=0; i<s.size(); i++){
        long long hash=0;
        long long curP=1;
        for(int j=i; j<s.size(); j++){
            long long curHash=(s[j]-'a'+1)*curP%MOD;
            hash=(hash+curHash)%MOD;
            curP=(curP*P)%MOD;
            if(mp[hash]==0){
                mp[hash]=true;
            }
        }
    }
    cout << mp.size() << endl;
}

int main(){
    string s; 
    cin >> s;
    getHash(s);
}