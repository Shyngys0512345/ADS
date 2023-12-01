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

int partition(vector<Student> &v, int l, int h){
    Student p = v[h];
    int i=l-1;
    for(int j=l; j<=h-1; j++){
        if(comp(p, v[j])){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[h]);
    return i+1;
}

void quickSort(vector<Student> &v, int l, int h){
    if(l<h){
        int pi=partition(v, l, h);
        quickSort(v, l, pi-1);
        quickSort(v, pi+1, h);
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

    quickSort(v, 0, v.size()-1);
    for(auto i : v){
        cout << i.first_name << " " << i.last_name << " " << fixed << setprecision(3) << i.gpa << endl;
    }
}