#include<bits/stdc++.h>
using namespace std;

int binary_search_in_range(int a[],int n,int l1, int r1){
    int left = 0, right = n - 1, cnt = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (l1 <= a[mid] && r1 >= a[mid] ) {
			cnt++;
		}else if ( a[mid] < l1) {
			left = mid + 1;
		} else {
            right = mid - 1;
		}
	}
	return cnt;
}
int main(){
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout<<binary_search_in_range(a,n,l1,r1)+binary_search_in_range(a,n,l2,r2)<<endl;
    return 0;
}