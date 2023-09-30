#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> player1, player2;
    // player1 = Boris    player2 = Nursik

    for(int i=0; i<5; i++){
        int num;
        cin >> num;
        player1.push(num);
    }
    for(int i=0; i<5; i++){
        int num;
        cin >> num;
        player2.push(num);
    }

    int moves=0;

    while(moves < 1000000 && !player1.empty() && !player2.empty()){
        int card1 = player1.front();
        int card2 = player2.front();
        player1.pop();
        player2.pop();

        if(card1 == 0 && card2 == 9){
            player1.push(card1);
            player1.push(card2);
        }
        else if(card1 == 9 && card2 == 0){
            player2.push(card1);
            player2.push(card2);
        }
        else if(card1 > card2){
            player1.push(card1);
            player1.push(card2);
        }
        else if(card1 < card2){
            player2.push(card1);
            player2.push(card2);
        }
        moves++;
    }
    if(player1.empty()){
        cout << "Nursik " << moves << endl;
    }
    else if(player2.empty()){
        cout << "Boris " << moves << endl;
    }
    else{
        cout << "blin nichya" << endl;
    }

    return 0;
}