#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 1007;
int a[MXN][MXN];
bool used[MXN][MXN];

int n,m;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};


int main(){
    vector <queue<pair<int, int> > > v;
    cin >> n >> m;
    int mushrooms = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                v.push_back(queue<pair<int, int> >());
                v[v.size() - 1].push(make_pair(i, j));
                used[i][j] = true;
            }
            else if (a[i][j] == 1){
                mushrooms++;
            }
        }
    }
    if(mushrooms == 0){
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    while(true){
        bool empty = true;
        for (int i = 0; i < v.size(); i++){
            if (!v[i].empty()){
                queue<pair <int, int> > cur = v[i];
                while (!cur.empty()) {
                    empty = false;
                    int v1 = cur.front().first;
                    int v2 = cur.front().second;
                    cur.pop();
                    v[i].pop();
                    for (int k = 0; k < 4; k++){
                        int tox = v1 + x[k];
                        int toy = v2 + y[k];
                        if (tox > 0 && toy > 0 && tox <= n && toy <= m ){
                            if (!used[tox][toy] and a[tox][toy] != 0){
                                used[tox][toy] = true;
                                if (a[tox][toy] == 1){
                                    mushrooms--;
                                    if (mushrooms == 0){
                                        cout << cnt + 1;
                                        return 0;
                                    }
                                }
                                a[tox][toy] = 2;
                                v[i].push(make_pair(tox, toy));
                            }
                        }
                    }
                }
            }
        }
        if (empty) break;
        cnt++;
    }
    cout << -1 << endl;
}