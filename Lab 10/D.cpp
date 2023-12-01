#include <bits/stdc++.h>
using namespace std;

const int Maxn=5007;
vector<int> g[Maxn];
int d[Maxn];
bool used[Maxn];
int color[Maxn];
int red=1;

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s]=true;
    d[s]=0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<g[v].size(); i++){
            int to = g[v][i];
            if(d[to]>d[v]+1){
                d[to]=d[v]+1;
                used[to]=true;
                q.push(to);
            }
        }
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        d[i]=1e9;
    }

    while(k--){
        int i, j;
        cin >> i >> j;
        if(i==1){
            if(color[j]!=red){
                bfs(j);
                color[j]=red;
            }
        } else {
            if(d[j]==1e9){
                cout << -1 << endl;
            } else {
                cout << d[j] << endl;
            }
        }
    }
}