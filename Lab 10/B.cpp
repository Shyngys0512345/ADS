#include <bits/stdc++.h>
using namespace std;

const int Maxn=1005;
vector<int> g[Maxn];
vector<int> p(Maxn);
vector<int> d(Maxn);
bool used[Maxn];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;
            if(x==1){
                g[i].push_back(j);
            }
        }
    }
    int s, e;
    cin >> s >>e;
    queue<int> q;
    q.push(s);
    used[s]=true;
    p[s]=-1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to]=true;
                q.push(to);
                d[to]=d[v]+1;
                p[to]=v;
            }
        }
    }

    if(used[e]){
        cout << d[e] <<endl;
    } else {
        cout << -1 << endl;
    }
}