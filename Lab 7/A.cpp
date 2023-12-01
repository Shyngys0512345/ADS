#include <bits/stdc++.h>
using namespace std;
int c[1000008];

bool comp(string &s, string &t){
    return s.size()>t.size();
}

void MergeOne(vector<string> &v, int l, int mid, int r){
    int i, j;
    i=l;
    j=mid+1;
    vector<string> v2;
    while(i<=mid && j<=r){
        if(!comp(v[i], v[j])){   
            v2.push_back(v[i]);
            i++;
        } else {
            v2.push_back(v[j]);
            j++;
        }
    }
    for(; i<=mid; i++){
        v2.push_back(v[i]);
    }

    for(; j<=r; j++){
        v2.push_back(v[j]);
    }

    for(i=l; i<=r; i++){
        v[i]=v2[i-l];
    }

}

void MergeSort(vector<string> &v, int l, int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(v, l, m);
        MergeSort(v, m+1, r);
        MergeOne(v, l, m, r);
    }
}

int main(){
    int n; cin >> n;
    string s;
    getline(cin, s);
    for(int i=0; i<n; i++){
        getline(cin, s);
        vector<string> v;
        string t="";
        for(int j=0; j<s.size(); j++){
            if(s[j]!=' '){
                t=t+s[j];
            } else {
                v.push_back(t);
                t="";
            }
        }
        v.push_back(t);
        MergeSort(v, 0, v.size()-1);

        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}