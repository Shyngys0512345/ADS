#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node *prev;
    int cnt;

    Node(int value){
        this->value=value;
        next=NULL;
        prev=NULL;
        cnt=1;
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
            head=item;
        }
        else{
            Node *cur = head;
            while(cur!=NULL){
                if(cur->value==value){
                    cur->cnt++;
                }
                else if(cur->next==NULL){
                    cur->next=item;
                    break;
                }
                cur=cur->next;
            }
        }
    }

    int getMax(){
        Node *cur = head;
        int maxi=1;
        while(cur!=NULL){
            if(cur->cnt>maxi){
                maxi=cur->cnt;
            }
            cur=cur->next;
        }
        return maxi;
    }

    void second(){
        Node *cur = head;
        vector<int> v;
        while(cur!=NULL){
            if(cur->cnt == getMax()){
                v.push_back(cur->value);
            }
            cur = cur->next;
        }
        sort(v.rbegin(), v.rend());
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
    }
};



int main(){
    Linked narse;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        narse.push_back(num);
    }
    narse.second();
    return 0;
}
//2020