#include<iostream>
using namespace std;

bool binary_search(int ar[], int target, int size) {
	int left = 0, right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target < ar[mid]) {
			right = mid - 1;
		} else if (target > ar[mid]) {
			left = mid + 1;
		} else {
			return true;
		}
	}
	return false;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin>>k;
    if(binary_search(a,k,n) == true){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}