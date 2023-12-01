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
    string s;
    cin >> s;
    vector<char>v;
    for(int i=0; i<s.size(); i++){
        v.push_back(s[i]);
    }
    
    quickSort(v, 0, v.size()-1);

    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    
    cout << endl;
}