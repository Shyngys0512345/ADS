#include <bits/stdc++.h> 
using namespace std; 
long long ans = 0; 
long long k; 
class Heap{ 
    long long size; 
    long long a[100005]; 
 
public: 
    Heap(){ 
        size=0; 
        a[0]=INT_MIN; 
    } 
 
    long long sz(){ 
        return size; 
    } 
 
    long long arr(){ 
        return a[1]; 
    } 
 
    long long parent(long long i){ 
        return i/2; 
    } 
 
    long long left(long long i){ 
        return i*2; 
    } 
 
    long long right(long long i){ 
        return i*2+1; 
    } 
 
    void insert(long long val){ 
        if(size<k){ 
            size++; 
            a[size]=val; 
            sift_up(size); 
        } else if(a[1]<val){ 
            a[1]=val; 
            sift_down(1); 
        } 
    } 
 
    void sift_up(long long i){ 
        while(i>1 && a[parent(i)]>a[i]){ 
            swap(a[i], a[parent(i)]); 
            i=parent(i); 
        } 
    } 
 
    void sift_down(long long i){ 
        long long l=left(i); 
        long long r=right(i); 
        long long childMin=left(i); 
        if(l>size) return; 
        if(r<=size){ 
            if(a[r]<a[l]) childMin=r; 
        } 
        if(a[i]>a[childMin]){ 
            swap(a[childMin], a[i]); 
            sift_down(childMin); 
        } 
    } 
 
    long long extractMin(){ 
        long long min=a[1]; 
        swap(a[1], a[size]); 
        size--; 
        sift_down(1); 
        return min; 
    } 
 
     
    void print(){ 
        for(int i=1; i<=size; i++){ 
            ans+=a[i]; 
        } 
        cout << ans << endl; 
        ans=0; 
    } 
}; 
 
int main(){ 
    Heap h; 
    int q; 
    cin >> q >> k; 
    for(int i=0; i<q; i++){ 
        string s; 
        cin >> s; 
        if(s=="insert"){ 
            long long l; cin >> l;  
            h.insert(l); 
        } 
        if(s=="print"){ 
            if(h.sz()==0){ 
                cout << 0 << endl; 
            } else { 
                h.print(); 
            } 
        } 
    } 
}