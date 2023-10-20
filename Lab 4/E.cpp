#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        right=left=NULL;
    }
};
int cnt=0;

class BST{
private:
    Node* root = new Node(1);
     
    void push(Node* cur, int x, int y, int z){
        if(!cur){
            return;
        }
        if(cur->val==x){
            if(z==1){
                cur->right = new Node(y);
            } else {
                cur->left = new Node(y);
            }
            return;
        }
        push(cur->right, x, y, z);
        push(cur->left, x, y, z);
    }

    int height(Node* cur){
        if(cur==NULL) return 0;
        return max(height(cur->left), height(cur->right))+1;
    }

    void levels(Node*cur, int level){
        if(cur==NULL) return;
        if(level==0){
            cnt++;
        } else {
            levels(cur->left, level-1);
            levels(cur->right, level-1);
        }
    }

public: 
    
    void push(int x, int y, int z){
        push(root, x, y, z);
    }

    int levels(){
        int h=height(root);
        int max = -999999;
        for(int i=0; i<h; i++){
            levels(root, i);
            if(cnt>max){
                max=cnt;
            }
            cnt=0;
        }
        return max;
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        tree.push(x, y, z);
    }
    cout << tree.levels();
}