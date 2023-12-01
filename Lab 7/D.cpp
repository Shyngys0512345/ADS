#include <bits/stdc++.h>
using namespace std;

struct Student{
    string first_name, last_name;
    double gpa;
};

bool comp(Student a, Student b){
    if(a.gpa==b.gpa){
        if(a.first_name==b.first_name){
            return a.last_name>b.last_name;
        } else {
            return a.first_name>b.first_name;
        }
    }
    return a.gpa>b.gpa;
}

double isLetter(string a){
    if(a=="A+") return 4.00;
    if(a=="A") return 3.75;
    if(a=="B+") return 3.50;
    if(a=="B") return 3.00;
    if(a=="C+") return 2.50;
    if(a=="C") return 2.00;
    if(a=="D+") return 1.50;
    if(a=="D") return 1.00;
    if(a=="F") return 0;
}

void MergeOne(vector<Student> &v, int l, int mid, int r){
    int i, j;
    i=l;
    j=mid+1;
    vector<Student> v2;
    while(i<=mid && j<=r){
        if(!comp(v[i], v[j])){   
            v2.push_back(v[i]);
            i++;
        } else {
            v2.push_back(v[j]);
            j++;
        }
    }
    for(; i<=mid; i++){
        v2.push_back(v[i]);
    }

    for(; j<=r; j++){
        v2.push_back(v[j]);
    }

    for(i=l; i<=r; i++){
        v[i]=v2[i-l];
    }

}

void MergeSort(vector<Student> &v, int l, int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(v, l, m);
        MergeSort(v, m+1, r);
        MergeOne(v, l, m, r);
    }
}

int main(){
    int n; 
    cin >> n;
    vector<Student> v(n);
    int m;
    for(auto &i : v){
        cin >> i.first_name >> i.last_name >> m;
        double sum=0;
        double SumCredits=0;



        
        for(int j=0; j<m; j++){
            string a;
            int credits;
            cin >> a >> credits;
            sum+=isLetter(a)*credits;
            SumCredits+=credits;
        }
        i.gpa =sum/SumCredits;
        
    }

    MergeSort(v, 0, v.size()-1);
    for(auto &i : v){
        cout << i.first_name << " " << i.last_name << " " << fixed << setprecision(3) << i.gpa << endl;
    }
}