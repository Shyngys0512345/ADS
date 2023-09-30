#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    int cnt;
    Node* next;
    Node* prev;

    Node(string val){
        this->val=val;
        cnt=1;
        next=NULL;
        prev=NULL;
    }
};

class Database{
    Node* head;
    Node* tail;
    int size;

public:
    Database(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void push_front(string val){
        Node* item = new Node(val);
        if(head==NULL){
            head=tail=item;
            size=1;
        } else {
            if(head->val==val){
                head->cnt++;
                // size--;
            }
            else if(head->prev==NULL){
                head->prev=item;
                item->next=head;
                head=item;
                size++;
            }
        }
    }

    void print(){
        Node* cur = head;
        cout <<"All in all: " << size << endl;
        cout <<"Students:" << endl;
        while(cur!=NULL){
            cout << cur->val << endl;
            cur=cur->next;
        }
    }
};
int main(){
    Database list;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        while(cin >> s){
            list.push_front(s);
        }
    }
    list.print();
}
//6963