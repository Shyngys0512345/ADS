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
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    quickSort(a, 0, n-1);
    quickSort(b, 0, m-1);

    vector<int> v;

    if(n>m){
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(a[i]==b[j]){
                    cout << b[j] << " ";
                    a[i]=-1;             
                    break;
                }
            }
        }

    } else {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i]==b[j]){
                    cout << b[j] << " ";
                    break;
                }
            }
        }
    }
}