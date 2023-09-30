#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    deque<int> q1, q2;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        q1.push_back(x);
    }
    
    while(!q1.empty()){
        if(q2.empty()){
            cout << -1 << " ";
            q2.push_back(q1.front());
            q1.pop_front();
        }
        else if(q2.back()<=q1.front()){
            cout << q2.back() << " ";
            q2.push_back(q1.front());
            q1.pop_front();
        } else if(q2.back()>q1.front()){
            q2.pop_back();
        }
    }
}