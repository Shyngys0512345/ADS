#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, string> s, pair<string, string> t){
    if(s.first==t.first){
        return s.second>t.second;
    }
    return s.first>t.first;
}

int partition(vector<pair<string, string> > &v, int l, int h){
    int p = h;
    int i=l-1;
    for(int j=l; j<=h-1; j++){
        if(comp(v[p], v[j])){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[h]);
    return i+1;
}

void quickSort(vector<pair<string, string> > &v, int l, int h){
    if(l<h){
        int pi=partition(v, l, h);
        quickSort(v, l, pi-1);
        quickSort(v, pi+1, h);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<string, string> > v;
    for(int i=0; i<n; i++){
        string s, t;
        cin >> s >> t;
        bool shop=false;
        for(int j=0; j<v.size(); j++){
            if(s==v[j].second){
                v[j].second=t;
                shop=true;
            }
        }
        if(shop==false) v.push_back(make_pair(s, t));
    }

    quickSort(v, 0, v.size()-1);

    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}