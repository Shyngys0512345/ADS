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
    Node* head;
    Node* tail;

public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void push(int x, int pos){
        Node* item=new Node(x);
        if(pos==0){
            item->next=head;
            head=item;
        } else {
            Node *cur = head;
            int i=0;
            while(cur!=NULL){
                if(i + 1==pos){
                    item->next=cur->next;
                    cur->next=item;
                    break;
                }
                cur=cur->next;
                i++;
            }
        }
    }

    void remove(int pos){
        if(pos==0){
            head=head->next;
        } else {
            Node* cur = head;
            Node* prev = NULL;
            int i=0;
            while(cur!=NULL){
                if(i==pos){
                    prev->next=cur->next;
                    delete cur;
                    return;
                }
                prev=cur;
                cur=cur->next;
                i++;
            }
        }
    }
    void replace(int pos1, int pos2){
        int i=0;
        int val;
        Node* cur=head;
        while(cur!=NULL){
            if(i==pos1){
                val=cur->val;
                break;
            }
            cur=cur->next;
            i++;
        }
        // cout << val << endl;
        remove(pos1);
        push(val, pos2);        
    }

    void reverse(){
        Node* cur = head;
        Node* next = NULL;
        Node* prev = NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
        tail=next;
    }

    void rotate_right(int k){
        if(k==0){
            return;
        }
        int size=0;
        int i=0; 
        Node* start = head;
        Node* cur = head;
        Node* prev = NULL;
        while(cur!=NULL){
            if(cur->next==NULL) break;
            cur=cur->next;
            size++;
        }
        for(int i=0; i<size+1-k; i++){
            prev=start;
            start=start->next;
        }
        prev->next=NULL;
        cur->next=head;
        head=start;
    }

    void rotate_left(int k){
        if(k==0){
            return;
        }
        int i=0; 
        Node* start = head;
        Node* cur = head;
        Node* prev = NULL;
        while(cur!=NULL){
            if(i<k){
                prev=start;
                start=start->next;
            }
            if(cur->next==NULL) break;
            cur=cur->next;
            i++;
        }
        prev->next=NULL;
        cur->next=head;
        head=start;
    }

    void print(){
        if(head==NULL){
            cout << -1 << endl;
        }
        Node* cur=head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    int command;
    while(cin >> command){
        if(command==0){ return 0; } 
        else if(command==1){int x, pos; cin >> x >> pos; list.push(x, pos);}
        else if(command==2){int pos; cin >> pos; list.remove(pos);}
        else if(command==3){list.print();}
        else if(command==4){int pos1, pos2; cin >> pos1 >> pos2; list.replace(pos1, pos2);}
        else if(command==5){list.reverse();}
        else if(command==6){int k; cin >> k; list.rotate_left(k);}
        else if(command==7){int k; cin >> k; list.rotate_right(k);}
    }
    return 0;
}
//6951