#include <bits/stdc++.h> 
using namespace std; 
#define ull long long 
ull n, k, sum=0; 
ull cnt=0; 
class Heap{ 
    ull size; 
    ull a[1000005]; 
public: 
 
    Heap(){ 
        size=0; 
        a[0]=INT_MIN; 
    } 
 
    ull sz(){ 
        return size; 
    } 
 
    ull arr(){ 
        return a[1]; 
    } 
 
    ull parent(ull i){ 
        return i/2; 
    } 
 
    ull left(ull i){ 
        return i*2; 
    } 
 
    ull right(ull i){ 
        return i*2+1; 
    } 
 
    void insert(ull val){ 
        size++; 
        a[size]=val; 
        sift_up(size); 
    } 
 
    void sift_up(ull i){ 
        while(i>1 && a[parent(i)]>a[i]){ 
            swap(a[parent(i)], a[i]); 
            i=parent(i); 
        } 
    } 
 
    void sift_down(ull i){ 
        ull l = left(i); 
        ull r = right(i); 
        ull min =left(i); 
        if(l>size) return; 
        if(r<=size){ 
            if(a[r]<a[l]) min=r; 
        } 
        if(a[i]>a[min]){ 
            swap(a[i], a[min]); 
            sift_down(min); 
        } 
    } 
 
    ull extract_min(){ 
        ull m = a[1]; 
        swap(a[1], a[size]); 
        size--; 
        sift_down(1); 
        return m; 
    } 
 
    ull getMin(){ 
        return a[1]; 
    } 
 
    void mix(){ 
        if(getMin()>k){ 
            cout << 0 << endl; 
            return; 
        } 
        while(sz()>1 && a[1]<k){ 
            cnt++; 
            ull m1=extract_min(); 
            ull m2=extract_min(); 
            ull ans=m1+2*m2; 
            sum=m1+m2; 
            // cout << ans << endl; 
            insert(ans); 
        } 
 
        if(sum<k){ 
            cout << -1 << endl; 
        } else { 
            cout << cnt << endl; 
        } 
    } 
}; 
int main(){ 
    Heap h; 
    cin >> n >> k; 
    for(int i=0; i<n; i++){ 
        ull x; cin >> x; 
        h.insert(x); 
    } 
    h.mix(); 
}