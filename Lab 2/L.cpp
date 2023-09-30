#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* next;
    int val;

    Node(int val){
        this->val=val;
        next=NULL;
    }
};
class Ragnarok{
    Node* head;

public:
    Ragnarok(){
        head=NULL;
    }

    void push(int val){
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

    int MaxSum(){
        int res = -99999;
        int sum=0;
        Node* cur = head;
        while(cur!=NULL){
            sum+=cur->val;
            if(cur->val>sum){
                sum=cur->val;
            }
            res=max(res, sum);    // if(res>sum) res=sum
            cur=cur->next;
        }
        return res;
    }
};

int main(){
    Ragnarok l;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        l.push(x);
    }
    cout << l.MaxSum();
    return 0;
}
//6977