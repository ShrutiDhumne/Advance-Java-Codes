
// Name: Abhijeet Ashok Gandhi           Batch: E2
// Roll: 244        PRN: 0220200160     Assignment_1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public :
    int data;
    Node * left;
    Node * right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
class BST{
public :
    Node* root;
    BST(){
       root=NULL;
    }
    Node* create();
    void inorder(Node *root);
    void preorder(Node *root);
    void postorder(Node *root);
    Node* searchNode(Node *root,int n);
    bool iterativeSearch(Node *root, int key);
    void iterativePreorder(Node* root);
    void iterativeInorder(Node* root);
    void iterativePostorder(Node* root);
    void levelwisePrint();
    void printLevelOrder (Node* node);
    void deleteNode(int key);
    void insertNode(Node *root);
    Node* getInorderPredecessor(Node *node);

};

Node* BST :: create(){          //Creating a Tree
    char ch;
    do{
        Node *temp ,*p;
        temp=new Node();
        cout<<"Enter Node: ";
        cin>>temp->data;

        if(root==NULL){
            root=temp;
        }
        else{
            p=root;
            while(1){
                if(temp->data < p->data){
                    if(p->left==NULL){		//No left child
                        p->left=temp;
                        break;
                    }
                    else{
                        p=p->left;
                    }
                }
                else{
                    if(p->right==NULL){		//No Right child
                        p->right=temp;
                        break;
                    }
                    else{
                        p=p->right;
                    }
                }
            }
        }
        cout<<"\nDo you want to add more (Y/N)? ";
        cin>>ch;
    }while(ch=='Y' || ch=='y');
    return root;
}
 void BST :: insertNode(Node *root){
    Node *temp ,*p;
    temp=new Node();
    cout<<"\nEnter Node : ";
    cin>>temp->data;
    if(root==NULL){
        root=temp;
    }
    else{
        p=root;
        while(1){
            if(temp->data < p->data){
                if(p->left==NULL){           //No left child
                    p->left=temp;
                    break;
                }
                else{
                    p=p->left;
                }
            }
            else{                        //temp->data >root->data
                if(p->right==NULL){           //No right child
                    p->right=temp;
                    break;
                }
                else{
                    p=p->right;
                }
            }
        }
    }
}

//LNR
void BST :: inorder(Node *root){        //Recursive Inorder Traversal
    if(root!=NULL){
        inorder(root->left);		//first traverse left child
        cout<<root->data<<" ";		// visit node
        inorder(root->right);		//traverse right child
    }
}
//NLR
void BST :: preorder(Node *root){       //Recursive Preorder Traversal
    if(root!=NULL){
        cout<<root->data<<" ";		// visit node
        preorder(root->left);		// traverse left child
        preorder(root->right);		//traverse right child
    }
}
//LRN
void BST :: postorder(Node *root){      //Recursive Postorder Traversal
    if(root!=NULL){
        postorder(root->left);		// traverse left child
        postorder(root->right);		//traverse right child
        cout<<root->data<<" ";		// visit node
    }
}
Node*  BST :: searchNode(Node *root, int n){        //Recursive Search
    if (root == NULL || root->data == n)
        return root;
    if (root->data < n)
       return searchNode(root->right,n);
    return searchNode(root->left,n);
}
bool BST :: iterativeSearch(Node *root, int key){       //Iterative Search
    int flag = 0;
    while (root != NULL) {		// Run the loop untill temp points to a NULL pointer.
        if (key > root->data)		// Shift pointer to right child.
            root = root->right;
        else if (key < root->data)	// Shift pointer to left child.
            root = root->left;
        else
            return 1;
    }
    return 0;
}
void BST :: iterativeInorder(Node *root){       //Iterative Inorder
    stack<Node*> s;
    Node *temp = root;
    while (temp != NULL || s.empty() == false){		//left most node
        while (temp !=  NULL){			 //left sub tree
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout <<temp->data<<"  ";
        temp = temp->right;			 // right sub tree
    }
}
void BST :: iterativePreorder(Node *root){          //Iterative Preorder
    if (root == NULL)
        return;
    stack<Node *> S;
    S.push(root);		//print root push right push left then pop right first push to process left first
    while (S.empty() == false){
        Node* temp = S.top();
        cout<<temp->data<<"  ";
        S.pop();			  // Push right and left children of the popped node to stack
        if (temp->right != NULL )
            S.push(temp->right);
        if (temp->left != NULL )
            S.push(temp->left);
    }
}
void BST :: iterativePostorder(Node *root){         //Iterative Postorder
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    Node* temp;
    while (!s1.empty()){
        temp = s1.top();		// Pop an item from s1 and push it to s2
        s1.pop();
        s2.push(temp);			 // Push left and right children
            				 // of removed item to s1
        if (temp->left != NULL){
            s1.push(temp->left );
        }
        if (temp->right != NULL ){
            s1.push(temp->right);
        }
    }
    while (!s2.empty()){		 // Print all elements of second stack
        temp = s2.top();
        s2.pop();
        cout <<temp->data <<"  ";
    }
}
void BST:: levelwisePrint(){        //Iterative Levelwise Print
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false){
        int cnt = q.size();
        cout<<"\n==> ";
        while (cnt > 0){
            Node *temp = q.front();
            cout<<temp->data<<"\t";
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            cnt--;
        }
    }
}
void BST :: deleteNode (int key){       //Iterative Delete
    Node *node =root, *current;
    if (root == NULL)
        return;
    while(1){
        if(key<=node->data){
            if(node->left==NULL){
                cout<<"\nNode Not found !";
                return;
            }
            else if(node->left->data==key){
                if((node->left->left)!=NULL && (node->left->right)==NULL){
                    current = node->left;
                    node->left = node->left->left;
                }
                else if(node->left->right!=NULL && node->left->left==NULL){
                    current = node->left;
                    node->left = node->left->right;
                }
                else if(node->left->left==NULL && node->left->right==NULL){
                    current = node->left;
                    node->left = NULL;
                }
                else if (node->left->left!=NULL && node->left->right!=NULL){
                    current = node->left;
                    node->left = getInorderPredecessor(node->left->left);
                }
                delete current;
                cout<<"\nNode Deleted !";
                return;
            }
            else
                node = node->left;
        }
        else if(key >= node->data){
            if(node->right==NULL){
                cout<<"\nNode Not found !";
                return;
            }
            else if (node->right->data==key){
                if((node->right->left)!=NULL && (node->right->right)==NULL){
                    current     = node->right;
                    node->right = node->right->left;
                }
                else if (node->right->right!=NULL && node->right->left==NULL){
                    current = node->right;
                    node->right = node->right->right;
                }
                else if (node->right->left==NULL && node->right->right==NULL){
                    current = node->right;
                    node->right = NULL;
                }
                else if (node->right->left!=NULL && node->right->right!=NULL){
                    current = node->right;
                    node->right = getInorderPredecessor(node->right->left);
                }
                delete current;
                cout<<"\nNode Deleted !";
                return;
            }
            else
                node = node->right;
        }
    }
}
Node* BST :: getInorderPredecessor(Node *node){         //Get Predecessor
    Node *temp = node;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}
int main()
{
    int ch;
    char ans;
    BST bst;
    Node *r;
    cout<<"****************************Binary Search Tree******************************";
    while(1){
        cout<<"\n\n1. Create Node\n2. Recursive Inorder\n3. Recursive Preorder\n4. Recursive Postorder\n5. Recursive Search \n6. Iterative Search\n";
        cout<<"7. Iterative Inorder\n8. Iterative Preorder\n9. Iterative Postorder\n10.Iterative Levelwise Print\n11. Delete Node\n12. Insert\n13. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nCreating --> ";
                r=bst.create();
                break;
            case 2:
                cout<<"\nRecursive Inorder --> ";
                bst.inorder(r);
                break;
            case 3:
                cout<<"\nRecursive Preorder --> ";
                bst.preorder(r);
                break;
            case 4:
                cout<<"\nRecursive Postorder --> ";
                bst.postorder(r);
                break;
            case 5:
                int n;
                Node* ans;
                cout<<"\nEnter the Node to Search : ";
                cin>>n;
                ans = bst.searchNode(r,n);
                if( ans->data == n)
                    cout<<"\nNode Found!";
                else
                    cout<<"\nNode Not Found!";
                break;
            case 6:
                cout<<"\nEnter the Node to Search : ";
                cin>>n;
                if( bst.iterativeSearch(r,n))
                    cout<<"\nNode Found!";
                else
                    cout<<"\nNode Not Found!";
                break;
            case 7:
                cout<<"\nIterative Inorder --> ";
                bst.iterativeInorder(r);
                break;
            case 8:
                cout<<"\nIterative Preorder --> ";
                bst.iterativePreorder(r);
                break;
            case 9:
                cout<<"\nIterative Postorder --> ";
                bst.iterativePostorder(r);
                break;
            case 13:
                return 0;
            case 10:
                cout<<"\nIterative Levelwise Print --> ";
                bst.levelwisePrint();
                break;
            case 11:
                int key;
                cout<<"\n Enter the Key to Delete --> ";
                cin>>key;
                bst.deleteNode(key);
                break;
            case 12:
                cout<<"\nInsert --> ";
                bst.insertNode(r);
                break;

        }

    }
}

/*
****************************Binary Search Tree******************************

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 1

Creating --> Enter Node: 55

Do you want to add more (Y/N)? y
Enter Node: 40

Do you want to add more (Y/N)? y
Enter Node: 30

Do you want to add more (Y/N)? y
Enter Node: 10

Do you want to add more (Y/N)? y
Enter Node: 20

Do you want to add more (Y/N)? y
Enter Node: 70

Do you want to add more (Y/N)? y
Enter Node: 60

Do you want to add more (Y/N)? n


1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 2

Recursive Inorder --> 10 20 30 40 55 60 70

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 3

Recursive Preorder --> 55 40 30 10 20 70 60

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 4

Recursive Postorder --> 20 10 30 40 60 70 55

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 5

Enter the Node to Search : 30

Node Found!

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 6

Enter the Node to Search : 70

Node Found!

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 7

Iterative Inorder --> 10  20  30  40  55  60  70

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 8

Iterative Preorder --> 55  40  30  10  20  70  60

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 9

Iterative Postorder --> 20  10  30  40  60  70  55

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 10

Iterative Levelwise Print -->
==> 55
==> 40  70
==> 30  60
==> 10
==> 20

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 11

 Enter the Key to Delete --> 70

Node Deleted !

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 2

Recursive Inorder --> 10 20 30 40 55 60

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 12

Insert -->
Enter Node : 999


1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 2

Recursive Inorder --> 10 20 30 40 55 60 999

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Recursive Search
6. Iterative Search
7. Iterative Inorder
8. Iterative Preorder
9. Iterative Postorder
10.Iterative Levelwise Print
11. Delete Node
12. Insert
13. Exit
Enter your choice: 13

Process returned 0 (0x0)   execution time : 67.041 s
Press any key to continue.
*/
















