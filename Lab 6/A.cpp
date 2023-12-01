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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char>v1, v2;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='u'){
            v1.push_back(s[i]);
        } else {
            v2.push_back(s[i]);
        }
    }
    
    quickSort(v1, 0, v1.size()-1);
    quickSort(v2, 0, v2.size()-1);

    for(int i=0; i<v1.size(); i++){
        cout << v1[i];
    }
    
    for(int i=0; i<v2.size(); i++){
        cout << v2[i];
    }

}