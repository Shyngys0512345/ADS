#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* next;
    Node* prev;
    int val;

    Node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class LinkedList{
    Node *head;
    Node* tail;

public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    void push_back(int val){
        Node* item=new Node(val);
        if(head==NULL){
            head=tail=item;
        } else {
            tail->next=item;
            item->prev=tail;
            tail=item;
        }
    }

    void Shop(int k){
        Node* cur= head;
        vector<int>v;
        int min=99999;
        int index=0;
        while(cur!=NULL){
            v.push_back(abs(k-cur->val));
            cur=cur->next;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i]<min){
                min=v[i];
                index=i;
            }
        }

        cout << index;
    }

};
int main(){
    LinkedList l;
    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        l.push_back(x);
    }
    int k;
    cin >> k;
    l.Shop(k);
}

//6978