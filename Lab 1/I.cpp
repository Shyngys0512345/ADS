#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q1, q2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n; i++){
        if(s[i]=='K'){
            q1.push(i);
        } else {
            q2.push(i);
        }
    }
    while(!q1.empty() && !q2.empty()){
        if(q1.front()>q2.front()){
            q2.push(q2.front()+n);
        } 
        else{
            q1.push(q1.front()+n);
        }
        q1.pop();
        q2.pop();
    }

    if(q1.empty()){
        cout << "SAKAYANAGI" << endl;
    } 
    else {
        cout << "KATSURAGI" << endl;
    }
    return 0;
}



/*
KCKC
q1: 0 2  2+4=6  3    
q2: 1 3  1+4=5

*/