#include <iostream>
#include<vector>
using namespace std;

int sum_of_string(string s){
    int x = 0;
    for(int i = 0; i < s.size(); i++){
        x += s[i];
    }
    return x;
}
bool comp(pair<string,pair<string,string>>& a, pair<string,pair<string,string>>& b){
    if(a.second.second[0] != b.second.second[0]){
        return a.second.second < b.second.second;
    }else{
        if(a.second.second[1] != b.second.second[1]){
            return a.second.second < b.second.second;
        }else{
            if(a.second.second[2] != b.second.second[2]){
                return a.second.second < b.second.second;
            }else{
                if(a.second.second[3] != b.second.second[3]){
                    return a.second.second < b.second.second;
                }
            }
        }    
    }
    if(a.second.first[0] != b.second.first[0]){
        return a.second.first < b.second.first;
    }else{
        if(a.second.first[1] != b.second.first[1]){
            return a.second.first < b.second.first;
        }    
    }
    if(a.first[0] != b.first[0]){
        return a.first < b.first;
    }else{
        return a.first[1] < b.first[1];
    }
}

int partition(vector<pair<string,pair<string,string>>>& a, int l, int r){
    int i = l - 1;
    int pivot = r;
    for(int j = l; j < r; j++){
        if(comp(a[j],a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(vector<pair<string,pair<string,string>>>& a, int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}
int main() {
	int n;
    cin >> n;
    vector<pair<string,pair<string,string>>> v;
    while(n--){
        string s;
        cin >> s;
        string d = "", m = "", y = "";
        //d = s[0] + s[1];
        d += s[0];
        d += s[1];
        m += s[3];
        m += s[4];
        y += s[6];
        y += s[7];
        y += s[8];
        y += s[9];
        
        v.push_back(make_pair(d,make_pair(m,y)));
    }
    qsort(v,0,v.size() - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << "-"<<  v[i].second.first << "-" << v[i].second.second << endl;
    }
	return 0;
}