#include <bits/stdc++.h>
using namespace std;
map<unsigned long long, bool> used;
map<unsigned long long, unsigned long long> p;

void bfs(int n, int m){
    queue <unsigned long long> q;
    q.push(n);
    used[n] = true;
    while(!q.empty()){
        unsigned long long v = q.front();
        q.pop();
        if(!used[2 * v] && v < m){
            q.push(2 * v);
            used[2 * v] = true;
            p[2 * v] = v;
            if(2 * v == m)return;
        }
        if(v - 1 > 0 && !used[v - 1]){
            q.push(v - 1);
            used[v - 1] = true;
            p[v - 1] =  v;
            if(v - 1 == m)return;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n == m){
        cout << 0;
        return 0;
    } else if (n > m){
        cout << n - m << endl;
        n -= 1;
        while(n != m){
            cout << n << " ";
            n--;
        }
        cout << m;
        return 0;
    }
    bfs(n, m);
    vector <unsigned long long> res;
    while(m != n){
        res.push_back(m);
        m = p[m];
    }
    
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
}