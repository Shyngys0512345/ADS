#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
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
        size++;
        a[size]=val;
        sift_up(size);
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
        int x; cin >> x;
        h.insert(x);
    }

    while(h.sz()>1){
        long long m1=h.extractMin();
        long long m2=h.extractMin();
        ans+=m1+m2;
        // cout << m1+m2 << " ";
        h.insert(m1+m2);
    }
    cout << ans << endl;
    
    // h.print();
}