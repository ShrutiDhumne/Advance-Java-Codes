
//  Name: Shruti Deepak Dhumne      PRN: 0220200161
//  Rollno: 227                     E1-Batch (Assignment-3)


#include<bits/stdc++.h>
using namespace std;

class Node {
public :
    int key,height;
    Node * left;
    Node * right;
};

class AVL{
    public :
    Node * mainroot;
    AVL(){
       mainroot=NULL;
    }
    int height(Node *N);
    int max(int a, int b);
    Node* newNode(int key);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    int getBalance(Node *N);
    Node* insert(Node* mainroot, int key);
    void rec_Inorder(Node *mainroot);
    void rec_Preorder(Node *mainroot);
    void rec_postorder(Node *mainroot);
    void itr_Inorder(Node *mainroot);
    void itr_Preorder(Node *mainroot);
    void itr_Postorder(Node *mainroot);
};

int AVL :: height(Node *N){                                  // function to get the height of the tree
    if (N == NULL)
        return 0;
    return N->height;
}
                                                            //function to get maximum of two integers
int AVL :: max(int a, int b){
    return (a > b)? a : b;
}
                                                            //New Node Formation
Node* AVL :: newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;                                       // new node is initially
                                                            // added at leaf
    return(node);
}                                                            //Right Rotation
Node* AVL :: rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
                                                            // Update heights
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

                                                            // Return new root
    return x;
}
                                                            //left Rotation
Node* AVL :: leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;
                                                            // Perform rotation
    y->left = x;
    x->right = T2;
                                                            // Update heights
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
                                                            // Return new root
    return y;
}
                                                            // Get Balance factor of node N
int AVL :: getBalance(Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}                                                           //Insertion of node one by one
Node* AVL :: insert(Node* mainroot, int key){
    Node *node=mainroot;
                                                            // 1. Perform the normal BST insertion
    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else                                                    // Equal keys are not allowed in BST
        return node;
                                                            // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left),height(node->right));

                                                            // 3. Get the balance factor of this ancestor
                                                            //node to check whether this node became unbalanced
    int balance = getBalance(node);                         // If this node becomes unbalanced, then
                                                            // there are 4 cases
                                                            // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
                                                            // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
                                                            // Left Right Case
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
                                                            // Right Left Case
    if (balance < -1 && key < node->right->key)        {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
                                                            // return the (unchanged) node pointer
    return node;
}
void AVL :: rec_Inorder(Node *mainroot){                            //recursive
    if(mainroot!=NULL){
        rec_Inorder(mainroot->left);                        //first traverse left child
        cout<<mainroot->key<<"\t";                          // visit node
        rec_Inorder(mainroot->right);                       //traverse right child
    }
}
void AVL :: rec_Preorder(Node *mainroot){                           //recursive
    if(mainroot!=NULL){
        cout<<mainroot->key<<"\t";                           // visit node
        rec_Preorder(mainroot->left);                        //first traverse left child
        rec_Preorder(mainroot->right);                       //traverse right child
        cout<<"  ";
    }
}
void AVL :: rec_postorder(Node *mainroot){                         //recursive
    if(mainroot!=NULL){
        rec_postorder(mainroot->left);                          //first traverse left child
        rec_postorder(mainroot->right);                         //traverse right child
        cout<<mainroot->key<<"\t";                              // visit node
        cout<<"  ";
    }
}
void AVL :: itr_Inorder(Node *mainroot){
    stack<Node *> s;
    Node *temp = mainroot;
    while (temp != NULL || s.empty() == false){
                                                            //left most node
        while (temp !=  NULL){
                                                            //left sub tree
            s.push(temp);
            temp = temp->left;
        }
                                                            //pop and print node
        temp = s.top();
        s.pop();
        cout <<temp->key<<"\t";
                                                            // right sub tree
        temp = temp->right;
    }
}
void AVL :: itr_Preorder(Node *mainroot){
    if (mainroot == NULL){
        return;
    }
                                                            //push root in empty stack
    stack<Node *> S;
    S.push(mainroot);
                                                            //print root push right push left then pop
                                                            //right first push to process left first
    while (S.empty() == false){
                                                            // Pop the top item from stack and print it
        Node* temp = S.top();
        cout<<temp->key<<"\t";
        S.pop();
                                                            // Push right and left children of the popped node to stack
        if (temp->right)
            S.push(temp->right);
        if (temp->left)
            S.push(temp->left);
    }
}
void AVL :: itr_Postorder(Node *mainroot){
                                                            // Create two stacks
    stack<Node *> s1, s2;
                                                            // push root to first stack
    s1.push(mainroot);
    Node* temp;
                                                            // Run while first stack is not empty
    while (!s1.empty()){
                                                            // Pop an item from s1 and push it to s2
        temp = s1.top();
        s1.pop();
        s2.push(temp);                                      // Push left and right child // of removed item to s1
        if (temp->left){
            s1.push(temp->left);
        }
        if (temp->right){
            s1.push(temp->right);
        }
    }                                                       // Print all elements of second stack
    while (!s2.empty()){
        temp = s2.top();
        s2.pop();
        cout << temp->key <<"\t";
    }
}


int main(){
    int ch,key,n,i;
    AVL avl;
    Node *mainroot;
    cout<<"***************************AVL Tree**************************";
    do{
        cout<<"\n\n1.Create Tree\n2.Recursive Inorder\n3.Recursive Preorder\n4.Recursive Postorder\n";
        cout<<"5.Iterative Inorder\n6.Iterative Preorder\n7.Iterative Postorder\n8. Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<"______________________________________________________________\n";
        switch(ch){
            case 1:
                mainroot=NULL;
                cout<<"\nHow many nodes do you want to Enter : ";
                cin>>n;
                for(i=0;i<n;i++){
                    cout<<"Enter key Element : ";
                    cin>>key;
                    mainroot=avl.insert(mainroot,key);
                }
                break;
            case 2:
                cout<<"\nRecursive Inorder --> ";
                avl.rec_Inorder(mainroot);
                break;
            case 3:
                cout<<"\nRecursive Preorder --> ";
                avl.rec_Preorder(mainroot);
                break;
            case 4:
                cout<<"\nRecursive postorder --> ";
                avl.rec_postorder(mainroot);
                break;
            case 5:
                cout<<"\nIterative Inorder --> ";
                avl.itr_Inorder(mainroot);
                break;
            case 6:
                cout<<"\nIterative Preorder --> ";
                avl.itr_Preorder(mainroot);
                break;
            case 7:
                cout<<"\nIterative Postorder --> ";
                avl.itr_Postorder(mainroot);
                break;
            case 8:
                return 0;
            default:
                cout<<"\nEnter valid choice\n";
        }
    }while(ch!=0);
}

/*
OUTPUT-->


***************************AVL Tree**************************

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 1
______________________________________________________________

How many nodes do you want to Enter : 5
Enter key Element : 40
Enter key Element : 20
Enter key Element : 10
Enter key Element : 60
Enter key Element : 70


1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 2
______________________________________________________________

Recursive Inorder --> 10        20      40      60      70

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 3
______________________________________________________________

Recursive Preorder --> 20       10        60    40        70

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 4
______________________________________________________________

Recursive postorder --> 10        40      70      60      20

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 5
______________________________________________________________

Iterative Inorder --> 10        20      40      60      70

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 6
______________________________________________________________

Iterative Preorder --> 20       10      60      40      70

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 7
______________________________________________________________

Iterative Postorder --> 10      40      70      60      20

1.Create Tree
2.Recursive Inorder
3.Recursive Preorder
4.Recursive Postorder
5.Iterative Inorder
6.Iterative Preorder
7.Iterative Postorder
8. Exit
Enter your choice : 8
______________________________________________________________

Process returned 0 (0x0)   execution time : 58.851 s
Press any key to continue.

*/
