#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int binary_search( int target) {
	int left = 0, right = v.size()-1;
    int res = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target < v[mid]) {
			right = mid - 1;
		} else if (target >= v[mid]) {
            res = mid;
			left = mid + 1;
		} 
	}
	return res + 1;
}
int finish(int l, int r){
    return binary_search( r) - binary_search( l - 1);
}
int main(){
    int n;
    unsigned long long q;
    cin >> n >> q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(unsigned long long i = 0; i < q; i++){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > r2 || l2 > r1){
            cout<<finish(l1,r1) + finish(l2,r2)<<endl;
        }else{
            int minn = min(l1,l2);
            int maxx = max(r1,r2);
            cout<<finish(minn,maxx)<<endl;
        }
    }
    return 0;
}