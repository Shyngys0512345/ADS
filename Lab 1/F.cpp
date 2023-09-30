#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;

}

int main(){
    int n;
    cin >> n;
    int num = 2;
    int count = 0;
    while(count < n){
        if(is_prime(num)){
            count++;
        }
        num++;
    }
    cout << num-1;
    
    
    return 0;
}