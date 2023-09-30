#include <bits/stdc++.h>
using namespace std;
struct Node{
    string val;
    Node* next;
    Node* prev;

    Node(string val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void add_back(string val){
        Node* item = new Node(val);
        if(tail==NULL){
            tail=head=item;
        } else {
            tail->next=item;
            item->prev=tail;
            tail=item;
        }
        size++;
        cout << "ok" << endl;
    }

    void add_front(string val){
        Node* item = new Node(val);
        if(head==NULL){
            head=tail=item;
        } else {
            head->prev=item;
            item->next=head;
            head=item;
        }
        size++;
        cout << "ok" << endl;
    }

    void erase_front(){
        if(head!=NULL){
            cout << head->val << endl;
            head=head->next;
            size--;
            if(head==NULL){
                tail=NULL;
            } else {
                head->prev=NULL;
            }
        } else {
            tail=NULL;
            cout << "error" << endl;
        }
    }

    void erase_back(){
        if(tail!=NULL){
            cout << tail->val << endl;
            tail=tail->prev;
            size--;
            if(tail==NULL){
                head=NULL;
            } else {
                tail->next=NULL;
            }
        } else {
            head=NULL;
            cout << "error" << endl;
        }
    }

    void front(){
        if(head!=NULL){
            cout << head->val << endl;
        } else {
            cout << "error" << endl;
        }
    }

    void clear(){
        head=NULL;
        tail=NULL;
        size=0;
        cout << "ok" << endl;
    }

    void back(){
        if(tail!=NULL){
            cout << tail->val << endl;
        } else {
            cout << "error" << endl;
        }
    }

};
int main(){
    LinkedList list;
    string s;
    while(cin >> s){
        if(s=="add_front"){string t; cin >> t; list.add_front(t);}
        else if(s=="add_back"){string t; cin >> t; list.add_back(t);}
        else if(s=="erase_front"){list.erase_front();}
        else if(s=="erase_back"){list.erase_back();}
        else if(s=="front"){list.front();}
        else if(s=="back"){list.back();}
        else if(s=="clear"){list.clear();}
        else if(s=="exit"){cout << "goodbye" << endl; return 0;}
    }
}
//6964