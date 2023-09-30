#include <bits/stdc++.h>
using namespace std;

bool equalStrings(string s1, string s2){
    string first, second;

    for(char c: s1){
        if(c == '#'){
            if(!first.empty()){
                first.pop_back();
            }
        }
        else{
            first.push_back(c);
        }
    }

    for(char c: s2){
        if(c == '#'){
            if(!second.empty()){
                second.pop_back();
            }
        }
        else{
            second.push_back(c);
        }
    }

    return first == second;


}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    if(equalStrings(str1, str2)){
        cout << "yes";
    }
    else{
        cout << "no";
    }


    return 0;
}