#include <bits/stdc++.h>
using namespace std;

const int Maxn=1e6;
vector<int> g[Maxn];
bool used[Maxn];

void dfs(int v){
    used[v]=true;
    for(int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]){
            dfs(to);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    int s, f;
    cin >> s >> f;
    dfs(s);
    if(used[f]){
        cout << "YES";  
    } else {
        cout << "NO";
    }
}