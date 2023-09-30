#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    if(n <= 1){
        return false;
    }
    for(int i=2; i*i <=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cin >> num;
    if(is_prime(num)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}