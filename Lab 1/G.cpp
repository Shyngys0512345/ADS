#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

bool isPrime(int num) {
    if(num <= 1){
        return false;
    }
    for(int i=2; i*i <= num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;

    return true;
}

int nextPrime(int num) {
    if (num % 2 == 0) {
        num++;
    } else {
        num += 2;
    }

    while (!isPrime(num)) {
        num += 2;
    }

    return num;
}

bool isSuperprime(int num) {
    int index = 0;
    int prime = 2;

    while (prime <= num) {
        index++;
        prime = nextPrime(prime);
    }

    return isPrime(index);
}

int main() {
    int n;
    cin >> n;

    deque<int> superprimes;

    int num = 2;
    while (superprimes.size() < n) {
        if (isSuperprime(num)) {
            superprimes.push_back(num);
        }
        num = nextPrime(num);
    }

    cout << superprimes.back() << endl;

    return 0;
}
