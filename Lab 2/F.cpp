#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class Linked{
    Node* head;
    Node* tail;
    int size;

public:
    Linked(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void push_back(int val){
        Node* item = new Node(val);
        if(head==NULL){
            head=item;
        } else {
            Node* cur = head;
            while(cur!=NULL){
                if(cur->next==NULL){
                    cur->next=item;
                    break;
                }
                cur=cur->next;
            }
        }
        size++;
    }
    
    void add(int pos, int val){
        Node* item = new Node(val);
        if(head==NULL){
            head=item;

        } else if(pos==0){
            item->next=head;
            head->prev=item;
            head=item;

        } else {
            Node* cur = head;
            int i=1;
            while(cur!=NULL){
                if(i==pos){
                    item->next=cur->next;
                    cur->next=item;
                    break;
                }
                cur=cur->next;
                i++;
            }
        }
        size++;
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
    int n;
    cin >> n;
    int data, pos;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        list.push_back(x);
    }
    cin >> data >> pos;
    list.add(pos, data);
    list.print();
}
//6960