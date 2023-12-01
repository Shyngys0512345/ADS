#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> g[maxn];
vector<int> used(maxn);
int cnt = 0;
int n;
void DFS(int i){
    used[i]=1;
    for(int j=0;j<g[i].size();j++){
        int u=g[i][j];
        if(!used[u]){
            if(g[u].size()>g[i].size()){
                cnt++;
            }
            DFS(u);
        }
    }
    return;
}
int main(){
    cin>>n;
    int m; cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            DFS(i);
            cnt++;
        }
    }
    cout<<cnt;
}