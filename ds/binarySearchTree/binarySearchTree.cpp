
#include <bits/stdc++.h>
using namespace std;

void shm() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\input.txt", "r", stdin);
    freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
}

class BST{
    int data= 0;
    BST* left  ,*right  ;
    public:
    BST () : data(0),left(NULL),right(NULL){};
    BST (int value){
        data = value;
        left = right = NULL;
    }
    void inorder (BST*);
    BST*  search(BST*,int);
    BST* insert(BST*,int);
    BST* deletefromBST(BST*,int);
    BST* minValNode(BST*);
};

BST* BST :: insert(BST* root,int value){
    if(!root) return new BST(value);
    if(value>root->data) {
        root->right = insert(root->right,value);
    }else{
        root->left = insert(root->left,value);
    }
    return root;
}
BST* BST :: search (BST* root,int item){
    if(root == NULL || root->data == item) {
        cout<< root -> data;
        return root ;
    }
    if(root->data > item) return search(root->right,item);
    return search(root->left,item);
}

//Deletion in BST
//Tutorial https://www.youtube.com/watch?v=gcULXE7ViZw&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=36
BST * BST :: minValNode(BST * node){
    BST* current = node;
    while (current && current-> left != NULL){
        current = current-> left;
    }
    return current;
}
BST* BST :: deletefromBST(BST* root,int delKey){
    if(root == NULL) return root;
    else if (delKey < root->data) root->left = deletefromBST(root->left,delKey);
    else if (delKey > root->data) root->right = deletefromBST(root->right,delKey);
    else{
        if(root->left == NULL && root -> right == NULL){
        return NULL;
        }else if (root->left == NULL){
            BST* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            BST* temp = root->left;
            free(root);
            return temp;
        }
        BST* minNode = minValNode(root->right);
        root-> data = minNode->data;
        root-> right = deletefromBST(root->right,minNode-> data);
    }
    return root;
}

void BST :: inorder (BST* root){
    if(!root) return ;
    inorder(root->left);
    cout << root-> data << endl;
    inorder(root->right);
}

int main()
{
    shm();
    BST b,*root =NULL,*found = NULL;
    root = b.insert(root,50);
    b.insert(root,80);
    b.insert(root,30);
    b.insert(root,10);
    b.insert(root,60);
    b.insert(root,90);
    b.insert(root,70);
    b.inorder(root);
    //b.search(root,50);
    cout << "after deletion" << endl;
    b.deletefromBST(root,50);
    b.deletefromBST(root,60);
    b.inorder(root);
}

