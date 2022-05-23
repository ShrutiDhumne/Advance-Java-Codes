// Name: Abhijeet Ashok Gandhi           Batch: E2
// Roll: 244        PRN: 0220200160     Assignment_5

#include<bits/stdc++.h>
#include<conio.h>
#define MAX 10
using namespace std;
class Hash{                                                      //Linear Probing With Replacement
private:
    int a[MAX];
public:
    Hash();
    int create(int);
    void linear_prob(int,int),display();
};
Hash::Hash(){
    int i;
    for(i=0;i<MAX;i++)
        a[i]=-1;
}
int Hash::create(int num){
    int key;
    key=num%10;
    return key;
}
void Hash::linear_prob(int key,int num){
    int flag,i,count=0;
    flag=0;
    if(a[key]==-1)                                                         //if the location indicated by hash key is empty
        a[key]=num;                                                        //place the number in the hash table
    else{
            i=0;
            while(i<MAX){
                if(a[i]!=-1)
                    count++;
                i++;
            }
        if(count==MAX){                                                         //checking for the hash full
            cout<<"\nHash Table Is Full Hence "<<num<<" Can not Be Inserted";
            display();
            exit(1);
        }
        for(i=key+1;i<MAX;i++){                                                    //moving linearly down
            if(a[i]==-1){                                                           // searching for empty location
                a[i]=num;                                                          //placing the number at empty location
                flag=1;
                break;
            }
         }                                                               //From key position to the end of array we have searched empty location
                                                                        //and now we want to check empty location in the upper part of the array
        for(i=0;i<key&&flag==0;i++){                                           //array from 0th to keyth loaction will be scanned
            if(a[i]==-1){
                a[i]=num;
                flag=1;
                break;
            }
        }
    }
}
void Hash::display(){
    int i;
    cout<<"\nThe Hash Table is --> "<<endl;
    for(i=0;i<MAX;i++)
        cout<<"\n  "<<i<<" --> "<<a[i];
}
class Hash_without_replacement{                                         //Linear Probing Without Replacement
    public:
    int a[MAX][2];
    Hash_without_replacement();
    int create(int);
    int hash(int,int);
    void display();
};

Hash_without_replacement :: Hash_without_replacement(){
    int i;
    for(i=0;i<MAX;i++){
        a[i][0]=-1;
        a[i][1]=-1;
    }
}

int Hash_without_replacement::create(int num){
    int key;
    key=num%10;
    return key;

}


int Hash_without_replacement::hash(int key,int num){
    int flag,i,count=0,ch;
    flag=0;
    i=0;
    while(i<MAX){
        if(a[i][0]!=-1)
            count++;
        i++;
    }
    if(count==MAX) {
        cout<<"\nHash Table Is Full";
        display();
        getch();
    }
    if(a[key][0]==-1)
        a[key][0]=num;
    else{
        ch=a[key][1];
        if(ch==-1){
            for(i=key+1;i<MAX;i++){
                if(a[i][0]==-1){
                    a[i][0]=num;
                    a[key][1]=i;
                    flag=1;
                    break;
                }
            }
        }
        else{
            while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
                ch=a[ch][1];
            for(i=ch+1;i<MAX;i++){
                if(a[i][0]==-1){
                    a[i][0]=num;
                    a[ch][1]=i;
                    flag=1;
                    break;
                }
            }
        }
        if(flag!=1){
            if(ch==-1){
                for(i=0;i<key;i++){
                    if(a[i][0]==-1){
                        a[i][0]=num;
                        a[key][1]=i;
                        flag=1;
                        break;
                    }
                }
            }
            else{
                while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
                ch=a[ch][1];
                for(i=ch+1;i<key;i++){
                    if(a[i][0]==-1){
                        a[i][0]=num;
                        a[ch][1]=i;
                        flag=1;
                        break;
                    }
                }
            }
        }
    }
}
void Hash_without_replacement::display(){
    int i;
    cout<<"\nThe Hash Table is --> ";
    for(i=0;i<MAX;i++)
    cout<<"\n  "<<i<<" --> "<<a[i][0];
}

int main(){
    int num,key,i,ch;
    char ans;
    cout<<"\n******************************* Linear Probing *******************************";
    cout<<"\n1. Linear Probing With Replacement\n2. Linear Probing Without Replacement \n\nSelect one type of Linear Probing : ";
    cin>>ch;
    if(ch == 1){
        Hash h;
        cout<<"\n********************* Linear Probing with Replacement **********************";
        do{
            cout<<"\nEnter The Numbe --> ";
            cin>>num;
            key=h.create(num);                                  //returns hash key
            h.linear_prob(key,num);                             //collision handled by linear probing
            cout<<"Do U Wish To Continue?(y/n) : ";
            cin>>ans;
        }while(ans=='y');
        h.display();
        cout<<endl;                                            //displays hash table
    return 0;
    }
    else{
         Hash_without_replacement h;
        cout<<"\n********************* Linear Probing Without Replacement **********************";
        do{
            cout<<"\nEnter The Number --> ";
            cin>>num;
            key=h.create(num);
            h.hash(key,num);
            cout<<"Do U Wish To Continue?(y/n) : ";
            cin>>ans;
        }while(ans=='y');
    h.display();
    return 0;

    }
}
/*

Output --> Linear Probing With Replacement


******************************* Linear Probing *******************************
1. Linear Probing With Replacement
2. Linear Probing Without Replacement

Select one type of Linear Probing : 1

********************* Linear Probing with Replacement **********************
Enter The Numbe --> 22
Do U Wish To Continue?(y/n) : y

Enter The Numbe --> 55
Do U Wish To Continue?(y/n) : y

Enter The Numbe --> 66
Do U Wish To Continue?(y/n) : y

Enter The Numbe --> 26
Do U Wish To Continue?(y/n) : y

Enter The Numbe --> 99
Do U Wish To Continue?(y/n) : n

The Hash Table is -->

  0 --> -1
  1 --> -1
  2 --> 22
  3 --> -1
  4 --> -1
  5 --> 55
  6 --> 66
  7 --> 26
  8 --> -1
  9 --> 99

Process returned 0 (0x0)   execution time : 19.579 s
Press any key to continue.

Output --> Linear Probing Without Replacement



******************************* Linear Probing *******************************
1. Linear Probing With Replacement
2. Linear Probing Without Replacement

Select one type of Linear Probing : 2

********************* Linear Probing Without Replacement **********************
Enter The Number --> 11
Do U Wish To Continue?(y/n) : y

Enter The Number --> 33
Do U Wish To Continue?(y/n) : y

Enter The Number --> 22
Do U Wish To Continue?(y/n) : y

Enter The Number --> 42
Do U Wish To Continue?(y/n) : y

Enter The Number --> 66
Do U Wish To Continue?(y/n) : y

Enter The Number --> 76
Do U Wish To Continue?(y/n) : n

The Hash Table is -->
  0 --> -1
  1 --> 11
  2 --> 22
  3 --> 33
  4 --> 42
  5 --> -1
  6 --> 66
  7 --> 76
  8 --> -1
  9 --> -1
Process returned 0 (0x0)   execution time : 25.137 s
Press any key to continue.
*/
