#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        right = left = NULL;
    }
};
int cnt = 0;
class BST{
private:
    Node* root;

    map<int, int> mp;

    Node* push(Node* cur, int val){
        if(cur==NULL){
            return new Node(val);
        } 
        if(val<cur->val) cur->left = push(cur->left, val);
        if(val>cur->val) cur->right = push(cur->right, val);
        return cur;
    }
    
    void levelSum(Node* cur, int x){
        if(cur==NULL){
            return;
        }
        mp[x]+=cur->val;
        levelSum(cur->right, x+1);
        levelSum(cur->left, x+1);
    }

    void print(Node* cur){
        vector<int> v;
        map<int, int>:: iterator it;
        for(it = mp.begin(); it!=mp.end(); it++){
            v.push_back(it->second);
        }

        cout << v.size() << endl;
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
    }
    

public:
    BST(){
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void levelSum(){
        levelSum(root, 0);
    }
    
    void print(){
        print(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        tree.push(a[i]);
    }
    tree.levelSum();
    tree.print();
}