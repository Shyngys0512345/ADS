#include <iostream>
#include <vector>
using namespace std;

int partition(vector<char> &v, int l, int h){
    int p = v[h];
    int i=l-1;
    for(int j=l; j<=h-1; j++){
        if(v[j]<p){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[h]);
    return i+1;
}

void quickSort(vector<char> &v, int l, int h){
    if(l<h){
        int pi=partition(v, l, h);
        quickSort(v, l, pi-1);
        quickSort(v, pi+1, h);
    }
}

int main(){
    int n; cin >> n;
    vector<char>v;
    for(int i=0; i<n; i++){
        char t; cin >> t;
        v.push_back(t);
    }
    char a; cin >> a;
    
    quickSort(v, 0, v.size()-1);

    if(v[v.size()-1]<=a){
        cout << v[0];
    } else {
        for(int i=0; i<v.size(); i++){
            if(v[i]>a){
                cout << v[i];
                break;
            }
        }
    }
}