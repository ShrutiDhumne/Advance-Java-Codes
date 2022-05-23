/*Write a program in C++ to implement binary search tree with the following options:
    1. Insert node 2. Non-Recursive Traversals (inorder, preorder, postorder)*/

/* Name: Shruti Deepak Dhumne       Rollno: 227             Batch-E1
   Seatno: S204156                  PRN: 0220200161                     */

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
        cout<<"\nEnter Node : ";
        cin>>data;
    }
};
class BST{
public :
    Node* root;
    BST(){
       root = NULL;
    }
    Node* create();
    void iterativePreorder(Node* root);
    void iterativeInorder(Node* root);
    void iterativePostorder(Node* root);
    void insertNode(Node *root);
};
Node* BST :: create(){                          //Creating a Tree
    char ch;
    do{
        Node *temp ,*p;
        temp=new Node();
        if(root==NULL){
            root=temp;
        }
        else{
            p = root;
            while(1){
                if(temp->data < p->data){
                    if(p->left==NULL){		    //No left child
                        p->left=temp;
                        break;
                    }
                    else
                        p=p->left;
                }
                else{
                    if(p->right == NULL){		    //No Right child
                        p->right=temp;
                        break;
                    }
                    else
                        p=p->right;
                }
            }
        }
        cout<<"Do you want to add more (Y/N)? ";
        cin>>ch;
    }while(ch=='Y' || ch=='y');
    return root;
}
void BST :: insertNode(Node *root){
    Node *temp ,*p;
    temp=new Node();
    if(root==NULL){
        root=temp;
    }
    else{
        p=root;
        while(1){
            if(temp->data < p->data){
                if(p->left==NULL){                      //No left child
                    p->left=temp;
                    break;
                }
                else{
                    p=p->left;
                }
            }
            else{                                       //temp->data >root->data
                if(p->right==NULL){                     //No right child
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
void BST :: iterativeInorder(Node *root){                 //Iterative Inorder
    stack<Node*> s;
    Node *cur = root;
    while (cur != NULL || s.empty() == false){
        while (cur !=  NULL){			                  //left sub tree
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout <<cur->data<<"  ";
        cur = cur->right;			                     // right sub tree
    }
}
void BST :: iterativePreorder(Node *root){               //Iterative Preorder
    stack<Node *> S;
    S.push(root);		                                 //print root push right push left then pop right first push to process left first
    while (S.empty() == false){
        Node* cur = S.top();
        cout<<cur->data<<"  ";
        S.pop();			                             // Push right and left children of the popped node to stack
        if (cur->right != NULL )
            S.push(cur->right);
        if (cur->left != NULL )
            S.push(cur->left);
    }
}
void BST :: iterativePostorder(Node *root){              //Iterative Postorder
    stack<Node *> s1, s2;
    s1.push(root);
    Node* cur;
    while (!s1.empty()){
        cur = s1.top();		                            // Pop an item from s1 and push it to s2
        s1.pop();
        s2.push(cur);			                        // Push left and right children // of removed item to s1
        if (cur->left != NULL){
            s1.push(cur->left );
        }
        if (cur->right != NULL ){
            s1.push(cur->right);
        }
    }
    while (!s2.empty()){		                        // Print all elements of second stack
        cur = s2.top();
        s2.pop();
        cout <<cur->data <<"  ";
    }
}

int main(){
    BST b;
    int ch,i = 0;
    Node* r;
    char n;
    cout<<"\n*******************************  Binary Search Tree  *****************************\n";
    cout<<"Creation of Binary Search Tree --> \n";
    r = b.create();
    while(1){
        cout<<"\n-----------------------------------------------------------------------------------";
        cout<<"\n1. Insert \n2. Inorder Traversal \n3. Preorder Traversal \n4. Postorder Traversal \n5. Exit";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\nInserting A Node --> ";
            b.insertNode(r);
            break;
        case 2:
            cout<<"\nInorder Traversal  --> ";
            b.iterativeInorder(r);
            break;
        case 3:
            cout<<"\nPreorder Traversal  --> ";
            b.iterativePreorder(r);
            break;
        case 4:
            cout<<"\nPostorder Traversal  --> ";
            b.iterativePostorder(b.root);
            break;
        case 5:
            return 0;
        default:
            cout<<"\nInvalid Choice !!";
        }
    }
}

/*

*******************************  Binary Search Tree  *****************************
Creation of Binary Search Tree -->

Enter Node : 50
Do you want to add more (Y/N)? y

Enter Node : 40
Do you want to add more (Y/N)? y

Enter Node : 70
Do you want to add more (Y/N)? y

Enter Node : 30
Do you want to add more (Y/N)? y

Enter Node : 45
Do you want to add more (Y/N)? y

Enter Node : 60
Do you want to add more (Y/N)? y

Enter Node : 90
Do you want to add more (Y/N)? n

-----------------------------------------------------------------------------------
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter Your Choice : 1

Inserting A Node -->
Enter Node : 99

-----------------------------------------------------------------------------------
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter Your Choice : 2

Inorder Traversal  --> 30  40  45  50  60  70  90  99
-----------------------------------------------------------------------------------
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter Your Choice : 3

Preorder Traversal  --> 50  40  30  45  70  60  90  99
-----------------------------------------------------------------------------------
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter Your Choice : 4

Postorder Traversal  --> 30  45  40  60  99  90  70  50
-----------------------------------------------------------------------------------
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter Your Choice : 5

Process returned 0 (0x0)   execution time : 55.242 s
Press any key to continue.
*/
