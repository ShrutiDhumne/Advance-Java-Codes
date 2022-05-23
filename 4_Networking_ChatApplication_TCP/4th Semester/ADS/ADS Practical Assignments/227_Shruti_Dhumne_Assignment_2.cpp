// Name: Shruti Deepak Dhumne           Batch: E1
// Roll: 227        PRN: 0220200161     Assignment_2

#include<bits/stdc++.h>
using namespace std;
class Node{
public :
    int data;
    Node *left,*right;
    bool lth,rth;
    Node(){
        left = right = NULL;
        lth = rth = 1;
    }
};
class TBT{
    public :
    Node *mainroot, *dummy;
    TBT(){
       mainroot=NULL;
       dummy==NULL;
    }
    Node* create();
    void rec_Inorder(Node *mainroot);
    void rec_Preorder(Node *mainroot);
    void rec_postorder(Node *mainroot);
    Node* find_inorder_successor(Node *root);
    Node* find_preorder_successor(Node *root);
    void itr_Inorder(Node *mainroot);
    void itr_Preorder(Node *mainroot);
    void search(Node *mainroot,int key);

};

Node* TBT :: create(){
    int n,i;
    cout<<"\nEnter total number of elements you want to insert : ";
    cin>>n;
    for(i=0;i<n;i++){
        Node *temp = new Node();
        cout<<"Enter data : ";
        cin>>temp->data;
        if(mainroot==NULL){
            dummy=new Node();
            dummy->data=9999;
            dummy->left=mainroot;                   //Making connection between Dummynode and Root
            dummy->right=dummy;
            dummy->lth=0;
            dummy->rth=1;
            mainroot=temp;
            mainroot->left=dummy;
            mainroot->right=dummy;
        }
        else{
            Node *root=mainroot;
            while(1){
                if(temp->data < root->data){
                    if(root->lth==1){               //Check if node is absent at left side
                        temp->left=root->left;
                        root->left=temp;
                        root->lth=0;
                        temp->right=root;
                        break;
                    }
                    else{
                        root=root->left;
                    }
                }
                else{
                    if(root->rth==1){               //Check if node is absent at right side
                        temp->right=root->right;
                        root->right=temp;
                        root->rth=0;
                        temp->left=root;
                        break;
                    }
                    else{
                        root=root->right;
                    }
                }
            }
        }
    }
    return mainroot;
}
void TBT :: rec_Inorder(Node *mainroot) {
    Node *root=mainroot;
    if(root!=dummy){
        if(root->lth==0)                            //left child is present
            rec_Inorder(root->left);                //first traverse left child
        cout<<root->data<<"\t";                     // visit node
        if(root->rth==0)
            rec_Inorder(root->right);               //traverse right child
    }
}
void TBT :: rec_Preorder(Node *mainroot){
    Node *root=mainroot;
    if(root!=dummy){
        cout<<root->data<<"\t";                     // visit node
        if(root->lth==0)
            rec_Preorder(root->left);               //first traverse left child
        if(root->rth==0)
            rec_Preorder(root->right);              //traverse right child
    }
}
void TBT :: rec_postorder(Node *mainroot){
    Node *root=mainroot;
    if(root!=dummy){
        if(root->lth==0)
            rec_postorder(root->left);              //first traverse left child
        if(root->rth==0)
            rec_postorder(root->right);             //traverse right child
        cout<<mainroot->data<<"\t";                 // visit node
    }
}
Node* TBT :: find_inorder_successor(Node *root){
    if(root->rth == 1)
        root = root->right;
    else{
        root = root->right;
        while(root->lth == 0)
            root = root->left;
    }
    return root;
}
void TBT :: itr_Inorder(Node *mainroot){
    Node *root=mainroot->left;
    while(root->lth==0)
        root=root->left;
    while(root!=dummy){
        cout<<root->data<<"\t";
        root=find_inorder_successor(root);      //get the inorder successor to print the next element
    }
}
Node* TBT :: find_preorder_successor(Node *root){
    if(root->lth == 0)
        root = root->left;
    else if(root->rth == 0)
        root = root->right;
    else{
        while(root->rth == 1){
            root = root->right;
            if(root == mainroot)
                break;
        }
        root = root->right;
    }
    return root;
}
void TBT :: itr_Preorder(Node *mainroot){
    Node *root = mainroot;
    cout<<root->data<<"\t";                     //Display the root first
    while(1){
        root = find_preorder_successor(root);   //get the Preorder successor to print the next element
        if(root==dummy)
            break;
        cout<<root->data<<"\t";
    }
}
void TBT :: search(Node *mainroot,int key){
    Node *temp = new Node;
    temp = mainroot;
    while(temp != dummy){
        if(temp->data == key){                  //Node Found
            cout<<"Element found !!!";
            return;
        }
        else if(temp->data > key)               //Node at left subtree
            temp = temp->left;
        else                                    //Node at right subtree
            temp = temp->right;
    }
    cout<<"Element not found !!!";
    return;
}
int main(){
    int ch,key;
    TBT tbt;
    Node *mainroot;
    cout<<"\n--------------------------Threaded Binary Tree--------------------------";
    do{
        cout<<"\n\n1. Create Node\n2. Recursive Inorder\n3. Recursive Preorder\n4. Recursive Postorder";
        cout<<"\n5. Iterative Inorder\n6. Iterative Preorder\n7. Search\n8. Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                mainroot=tbt.create();
                break;
            case 2:
                cout<<"\nRecursive Inorder --> ";
                tbt.rec_Inorder(mainroot);
                break;
            case 3:
                cout<<"\nRecursive Preorder --> ";
                tbt.rec_Preorder(mainroot);
                break;
            case 4:
                cout<<"\nRecursive Postorder --> ";
                tbt.rec_postorder(mainroot);
                break;
            case 5:
                cout<<"\nIterative Inorder --> ";
                tbt.itr_Inorder(mainroot);
                break;
            case 6:
                cout<<"\nIterative Preorder --> ";
                tbt.itr_Preorder(mainroot);
                break;
            case 7:
                cout<<"Enter the element to Search : ";
                cin>>key;
                tbt.search(mainroot,key);
                break;
            case 8:
                return 0;
            default:
                cout<<"\nEnter valid choice\n";
        }
    }while(ch!=0);
    return 0;
}

/*
OUTPUT -->


--------------------------Threaded Binary Tree--------------------------

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 1

Enter total number of elements you want to insert : 6
Enter data : 50
Enter data : 30
Enter data : 35
Enter data : 10
Enter data : 70
Enter data : 60


1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 2

Recursive Inorder --> 10        30      35      50      60      70

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 3

Recursive Preorder --> 50       30      10      35      70      60

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 4

Recursive Postorder --> 10      35      30      60      70      50

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 5

Iterative Inorder --> 10        30      35      50      60      70

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 6

Iterative Preorder --> 50       30      10      35      70      60

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 7
Enter the element to Search : 10
Element found !!!

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 7
Enter the element to Search : 99
Element not found !!!

1. Create Node
2. Recursive Inorder
3. Recursive Preorder
4. Recursive Postorder
5. Iterative Inorder
6. Iterative Preorder
7. Search
8. Exit
Enter your choice : 8

Process returned 0 (0x0)   execution time : 41.216 s
Press any key to continue.



*/
