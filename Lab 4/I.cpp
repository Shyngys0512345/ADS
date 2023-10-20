#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int cnt;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->cnt=1;
        right=left=NULL;
    }
};

class BST{
private:
    Node* root;

    Node* push(Node* cur, int val){
        if(cur==NULL){
            return new Node(val);
        }
        if(cur->val==val) cur->cnt++;
        if(cur->val>val) cur->left = push(cur->left, val);
        if(cur->val<val) cur->right = push(cur->right, val);
        return cur;
    }

    void printCnt(Node* cur, int val){
        if(cur==NULL){
            cout << 0 << endl;
            return;
        } else if(cur->val==val){
            cout << cur->cnt << endl;
            return;
        }
        if(cur->val>val) printCnt(cur->left, val);
        if(cur->val<val) printCnt(cur->right, val);
    }

    void Del(Node* cur, int val){
        if(cur!=NULL){
            if(cur->val==val){
                if(cur->cnt>0){
                    (cur->cnt)--;
                    return;
                } else {
                    cur->cnt=0;
                }
            } 
            if(val<cur->val) Del(cur->left, val);
            if(val>cur->val) Del(cur->right, val);
        }
        return;
    }

public:
    BST(){
        root = NULL;
    }

    void push(int n){
        root = push(root, n);
    }

    void printCnt(int x){
        printCnt(root, x);
    }

    void Del(int x){
        Del(root, x);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s; 
        int x;
        cin >> s >> x;
        if(s=="insert"){
            tree.push(x);
        }
        else if(s=="cnt"){
            tree.printCnt(x);

        } else if(s=="delete"){
            tree.Del(x);
        }
    }
}