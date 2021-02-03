
#include <bits/stdc++.h>
using namespace std;

void shm() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\input.txt", "r", stdin);
    freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

//Insertion or Deletion (any operation on Tress) require traversal of tree
//there are 4 ways this can be done
//1. Breadth First Search
//2. Depth First Seaarch
//  a. preorder
//  b. inorder
//  c. postorder
class Node{
    public:
        int key;
        Node *left,*right;
        Node (int x){
            key =x;
            left = right =NULL;
        }
};

void inorder(Node *temp){
    if(!temp)return;
    inorder(temp->left);
    std::cout << temp->key <<" ";
    inorder(temp->right);
}

void preorder(Node *temp){
    if(!temp)return;
    std::cout << temp->key <<" ";
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(Node *temp){
    if(!temp)return;
    postorder(temp->left);
    postorder(temp->right);
    std::cout << temp->key <<" ";
}

//bfs to insert,bfs uses queue
void insert (Node *temproot,int key){
    queue<Node*> q ;
    q.push(temproot);

    //we will try to fill in left side first
    //if left not available than right
    //so that the tree can be balanced
    //we r doing level traversal
    while(!q.empty()){
        Node* newTemp = q.front();
        q.pop();
        //checking left child of the node
        if(!newTemp->left){
            newTemp->left = new Node(key);
            break;
        }
        else{
            q.push(newTemp->left);
        }
        //checking right child of node
        if(!newTemp->right){
            newTemp->right = new Node(key);
            break;
        }else{
            q.push(newTemp->right);
        }
    }
}

void deleteDeepestNode(Node* root,Node* delNode)
{
    //traversing in level order to find the nodeTobeDeleted which is the deepest rightest node
    std::queue<Node*> q ;
    q.push(root);
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp == delNode){
            temp = NULL;
            delete(delNode);
            return;
        }

        if(temp->right){
            if(temp->right==delNode){
                temp->right = NULL;
                delete(delNode);
                return;
            }else q.push(temp->right);
        }

        if(temp->left){
            if(temp->left == delNode){
                temp->left = NULL;
                delete(delNode);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

Node *deletion(Node* root, int item){
    //checking if tree is empty
    if(root == NULL) return NULL;
    //checking if tree has only one node
    if(root->left == NULL && root->right == NULL){
        if(root->key == item)
            return NULL;
        else
            return root;
    }
    //bfs to find deepest Node and search item to be deleted

    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* nodeTobeDeleted = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        //the node to be deleted and also traversing to the deepest node
        if(temp->key == item ) nodeTobeDeleted=temp;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }//after this temp has deepest node

    if(nodeTobeDeleted!=NULL){
        int x = temp->key;
        deleteDeepestNode(root,temp);
        nodeTobeDeleted->key = x;
    }
    return root;
}

int main()
{
    shm();
    Node *root =new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout<<"Inorder before insertion"<<endl;
    inorder(root);
    cout << endl;

    int key = 12;
    insert(root,key);

    std::cout << "Inorder after insertion" << std::endl;
    inorder(root);
    cout<<endl;
    std::cout << "Preorder after insertion" << std::endl;
    preorder(root);

    cout<<endl;
    std::cout << "Postorder after insertion" << std::endl;
    postorder(root);
    cout<<endl;

    int item = 12;
    root = deletion(root,item);
    std::cout << "Inorder after deletion" << std::endl;
    inorder(root);
    std::cout << std::endl;
    return 0;

}

