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

class Linked{
    Node* head;
    Node* tail;

public:
    Linked(){
        head=NULL;
        tail=NULL;
    }

    void push_back(string val){
        Node* item = new Node(val);
        if(head==NULL){
            head=tail=item;
        } else {
            tail->next=item;
            item->prev=tail;
            tail=item;
        }
    }
    void rotate(int k){
        while(k>0){
            tail->next=head;
            tail=head;
            head=head->next;
            tail->next=NULL;
            k--;
        }
    }

    void print(){
        Node* cur = head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->next;
        }
    }
};
int main(){
    Linked list;
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        list.push_back(s);
    }
    list.rotate(k);
    list.print();
}
//6974