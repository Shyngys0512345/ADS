#include <bits/stdc++.h> 
using namespace std; 
int ans=0; 
class Heap{ 
    int size; 
    int a[100005]; 
public: 
    Heap(){ 
        size=0; 
        a[0]=INT_MAX; 
    } 
 
    int sz(){ 
        return size; 
    } 
 
    int arr(){ 
        return a[1]; 
    } 
 
    int parent(int i){ 
        return i/2; 
    } 
 
    int left(int i){ 
        return i*2; 
    } 
     
    int right(int i){ 
        return i*2+1; 
    } 
 
    void sift_up(int i){ 
        while(i>1 && a[parent(i)]<a[i]){ 
            swap(a[parent(i)], a[i]); 
            i=parent(i); 
        } 
    } 
 
    void sift_down(int i){ 
        int l=left(i); 
        int r=right(i); 
        int childMax=left(i); 
        if(l>size) return; 
        if(r<=size){ 
            if(a[r]>a[l]) childMax=r; 
        } 
        if(a[i]<a[childMax]){ 
            swap(a[childMax], a[i]); 
            sift_down(childMax); 
        } 
    } 
 
    void insert(int val){ 
        size++; 
        a[size]=val; 
        sift_up(size); 
    } 
 
    int extractMax(){ 
        int max=a[1]; 
        swap(a[1], a[size]); 
        size--; 
        sift_down(1); 
        return max; 
    } 
 
    void print(){ 
        for(int i=1; i<=size; i++){ 
            cout << a[i] << " "; 
        } 
        cout << endl; 
    } 
}; 
 
int main(){ 
    Heap h; 
    int n; 
    cin >> n; 
    for(int i=0; i<n; i++){ 
        int x; 
        cin >> x; 
        h.insert(x); 
    } 
 
    while(h.sz()>1){ 
        int max1=h.extractMax(); 
        int max2=h.extractMax(); 
        ans = max1-max2; 
        // cout << ans << endl; 
        h.insert(ans); 
    } 
 
    if(h.sz()==1){ 
        cout << h.arr() << endl; 
    } 
}