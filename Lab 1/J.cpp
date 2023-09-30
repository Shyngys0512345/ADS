#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dk;
    while(true){
        char command;
        cin >> command;
        if(command == '+'){
            int num;
            cin >> num;
            dk.push_front(num);
        }
        else if(command == '-'){
            int num;
            cin >> num;
            dk.push_back(num);
        }
        else if(command == '*'){
            if(dk.empty()){
                cout << "error" << endl;
            }
            else{
                int sum = dk.front() + dk.back();
                cout << sum << endl;
                dk.pop_front();
                if (!dk.empty()) {
                    dk.pop_back();
                }
            }
        }

        else if(command == '!'){
            break;
        }
    }
    return 0;
}