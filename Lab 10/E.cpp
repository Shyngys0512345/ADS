#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
bool used[maxn][maxn];
int a[maxn][maxn];

int main(){
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j]==1){
                used[i][j]=true;
            }
        }
    }
    
    for(int i=0; i<q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(a[x][y] && a[y][z] && a[x][z]){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}