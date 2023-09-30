#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        deque<int> q;
        vector<int> a(1001);
        for(int j=1; j<=m; j++){
            q.push_back(j);
        }
        int j=1;                    // 1 2 3 4
        while(!q.empty()){
            int l=0;
            while(l<j){             // 2 3 4 1
                int x=q.front();
                q.pop_front();
                q.push_back(x);
                l++;
            }
            int x=q.front();        // x=2
            if(a[x]!=0){
                cout << -1 << endl;
                return 0;
            }
            a[x]=j;                 //a[2]=1   j==1, x==2  ----> 2 3 4 1
            q.pop_front();          // 3 4 1
            j++;                    // j==2
        }
        for(int j=1; j<=m; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}