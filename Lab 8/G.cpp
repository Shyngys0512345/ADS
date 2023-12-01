#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+9;
long long P=31;

long long getHash(string &s){
    long long hash=0;
    long long curP=1;
    for(int i=0; i<s.size(); i++){
        long long curHash=(s[i]-'a'+1)*curP%MOD;
        hash=(hash+curHash)%MOD;
        curP=(curP*P)%MOD;
    }
    return hash;
}

vector<long long> getPrefix(string &s){
    vector<long long> hash(s.size());
    long long curP=1;
    for(int i=0; i<s.size(); i++){
        hash[i]=(s[i]-'a'+1)*curP%MOD;
        if(i!=0){
            hash[i]=(hash[i]+hash[i-1])%MOD;
        }
        curP=(curP*P)%MOD;
    }
    return hash;
}

int rabin_carp(string &s, string &t, vector<long long> &hash){
    long long smallHash = getHash(t);
    int cnt=0;
    for(int i=0; i<s.size()-t.size()+1; i++){
        long long hashDiff=hash[i+t.size()-1];
        if(i!=0) hashDiff-=hash[i-1];
        if(hashDiff<0) hashDiff+=MOD;
        if(i!=0) smallHash=(smallHash*P)%MOD;
        if(smallHash==hashDiff){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s;
    cin >> s;
    vector<long long> v = getPrefix(s);
    int n;
    cin >> n;
    while(n--){
        int r, l;
        cin >> l >> r;
        l--;
        string str="";
        for(int j=l; j<r; j++){
            str+=s[j];
        }
        // cout << str << endl;
        cout << rabin_carp(s, str, v) << endl;
    }
}