#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n1 = 0;
int n2 = 1;
int n3 = 2;
vector<int> g[maxn];
int used[maxn];
vector<int> vv;

void dfs(int v){
    if(used[v]==n2){
        cout << "Impossible" << endl;
        exit(0);
    }
    if(used[v]==n3){
        return;
    }
    used[v]=n2;

    for(int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    used[v]=n3;
    vv.push_back(v);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i=1; i<=n; i++){
        if(used[i]==n1){
            dfs(i);
        }
    }
    cout << "Possible" << endl;
    for(int i=vv.size()-1; i>=0; i--){
        cout << vv[i] << " ";
    }
    return 0;
}