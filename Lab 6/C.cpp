#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h){
    int p = a[h];
    int i=l-1;
    for(int j=l; j<=h-1; j++){
        if(a[j]<p){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return i+1;
}

void quickSort(int a[], int l, int h){
    if(l<h){
        int pi=partition(a, l, h);
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, h);
    }
}



int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    quickSort(a, 0, n-1);
    int min = 10000000;
    for(int i=0; i<n; i++){
        if(abs(a[i+1]-a[i])<min){
            min = abs(a[i+1]-a[i]);
        }
    }

    for(int i=0; i<n; i++){
        if(abs(a[i+1]-a[i])==min){
            cout << a[i] << " " << a[i+1] << " ";
        }
    }
}