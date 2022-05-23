// Name: Shruti Deepak Dhumne           Batch: E1
// Roll: 227        PRN: 0220200161     Assignment_6(Blooms Filter)

#include<iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int h1(string s, int SIZE){                                 // hash function 1
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++){
        hash = (hash + ((int)s[i]));
        hash = hash % SIZE;
    }
    return hash;
}
int h2(string s, int SIZE){                                // hash function 2
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++){
        hash = hash + pow(2, i) * s[i];
        hash = hash % SIZE;
    }
    return hash % SIZE;
}
int h3(string s, int SIZE) {                                 // hash function 3
    ll int hash = 7;
    for (int i = 0; i < s.size(); i++){
        hash = (hash * 3 + s[i]) % SIZE;
    }
    return hash % SIZE;
}
bool lookup(bool* bitarray, int SIZE, string s){            // loookup operation
    int a = h1(s, SIZE);
    int b = h2(s, SIZE);
    int c = h3(s, SIZE);
    if (bitarray[a] && bitarray[b] && bitarray)
        return true;
    else
        return false;
}
void insert(bool* bitarray, int SIZE, string s){            // insert operation
                                                            // check if the element in already present or not
    if (lookup(bitarray, SIZE, s))
        cout << s << " is Probably already present" << endl;
    else{
        int a = h1(s, SIZE);
        int b = h2(s, SIZE);
        int c = h3(s, SIZE);

        bitarray[a] = true;
        bitarray[b] = true;
        bitarray[c] = true;

        cout << s << " inserted" << endl;
    }
}
int main(){
    cout<<"\n******************************** Blooms Filter *********************************\n";
    bool bitarray[100] = { false };
    int MAX = 100, SIZE=0;

    cout<<"\nEnter Total number of elements  :  ";
    cin>>SIZE;
    string A[SIZE];

    cout<<"\nEnter the word elements --> \n";
    for (int i=0;i<SIZE;i++){
        cout<<"--> ";
        cin>>A[i];
    }
    cout<<endl<<endl;
    for (int i = 0; i < SIZE; i++) {
        insert(bitarray, MAX, A[i]);
    }
    return 0;
}

/*
Output :


******************************** Blooms Filter *********************************

Enter Total number of elements  :  9

Enter the word elements -->
--> Don't
--> talk,
--> act.
--> Don't
--> say,
--> show.
--> Don't
--> promise,
--> prove


Don't inserted
talk, inserted
act. inserted
Don't is Probably already present
say, inserted
show. inserted
Don't is Probably already present
promise, inserted
prove inserted

Process returned 0 (0x0)   execution time : 64.949 s
Press any key to continue.
*/

