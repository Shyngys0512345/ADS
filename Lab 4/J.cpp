#include <bits/stdc++.h>
using namespace std;

void binFun(vector<int> &v, int l, int r){
    int m = (r+l)/2;
    cout << v[m] << " ";
    if(l==r) return;
    binFun(v, l, m-1);
    binFun(v, m+1, r);
}
int main(){
    int n;
    cin >> n;
    int sz = pow (2, n)-1;
    vector<int> v;
    for(int i=0; i<sz; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    binFun(v, 0, sz-1);
    return 0;
}