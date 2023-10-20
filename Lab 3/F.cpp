//wrong
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binary_search(vector<int> v, int target, int size) {
	int left = 0, right = size;
    int res = 0;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (target < v[mid]) {
			right = mid;
		} else if (target > v[mid]) {
			left = mid + 1;
		}else{
            return mid + 1;
        }
        res = mid + 1;
	}
	return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int round;
    cin >> round;
    while(round --){
        int power;
        cin >> power;
        int sum = 0;
        for(int i  = 0; i < binary_search(v,power,v.size()); i++){
            sum+= v[i];
        }
        cout<< binary_search(v,power,v.size())<<" "<<sum<<endl;
    }
    return 0;
}