#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int binarySearchMax(vector<int> v){
//     int left = 0, right = v.size();
//     int max = 0;
//     while(left < right){
//         if()
//     }
// }

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> res;
    while(n--){
        int x = 4;
        vector<int> v;
        while(x--){
            int y;
            cin>>y;
            v.push_back(y);
        }
        sort(v.begin(),v.end());
        res.push_back(v[v.size()-1]);
    }
    sort(res.begin(),res.end());
    cout<<res[k-1];
}