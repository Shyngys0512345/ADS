#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    char val;
    int cnt;

    Node(char val){
        this->val=val;
        next=NULL;
        prev=NULL;
        cnt=1;
    }
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head=NULL;
    }

    void push(char val){
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
    }

    void solve(vector<int>v){
        while(head!=NULL && v[head->val-'a']>1){
            head=head->next;
        }
        if(head==NULL){
            cout << -1 << " ";
        } else { 
            cout << head->val << " ";
        }
    }
};
int main(){
    int n;
    cin >> n;
    while(n-- ){
        LinkedList list;
        vector<int>v(30, 0);
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            char x;
            cin >> x;
            v[x-'a']++;
            list.push(x);
            list.solve(v);
        }
        cout << endl;
    }
}
//6971