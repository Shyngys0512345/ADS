#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *prev;
    Node *next;

    Node(int value){
        this->value=value;
        prev=NULL;
        next=NULL;
    }
};

class Linked{
    Node *head;
    Node *tail;
public:
    Linked(){
        head=NULL;
        tail=NULL;
    }

    void push_back(int value){
        Node *item = new Node(value);
        if(head==NULL){
            head = item;
        }
        else{
            Node *cur = head;
            while(cur->next!=NULL){
                cur =cur->next;
            }
            cur->next = item;
        }
    }

    void print(){
        Node *cur = head;
        while(cur!=NULL){
            cout << cur->value << " ";
            cur = cur->next;
        }
    }
};

int main(){
    Linked list;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(i%2==0){
            list.push_back(num);
        }
    }
    list.print();


    return 0;
}
//2025