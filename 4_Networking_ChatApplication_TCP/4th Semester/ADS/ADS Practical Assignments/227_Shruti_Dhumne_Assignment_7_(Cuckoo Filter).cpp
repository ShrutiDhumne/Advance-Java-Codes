// Name: Shruti Deepak Dhumne           Batch: E1
// Roll: 227        PRN: 0220200161     Assignment_6(Cuckoo Filter)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAXN 11
#define ver 2

// Auxiliary space bounded by a small multiple
// of MAXN, minimizing wastage
int hashtable[ver][MAXN];
// Array to store possible positions for a key
int pos[ver];
/* function to fill hash table with dummy value
* dummy value: INT_MIN
* number of hashtables: ver */
void initTable(){
	for (int j=0; j<MAXN; j++)
		for (int i=0; i<ver; i++)
			hashtable[i][j] = INT_MIN;
}

/* return hashed value for a key
* function: ID of hash function according to which
	key has to hashed
* key: item to be hashed */
int hash(int function, int key){
	switch (function){
		case 1: return key%MAXN;
		case 2: return (key/MAXN)%MAXN;
	}
}

/* function to place a key in one of its possible positions
* tableID: table in which key has to be placed, also equal
to function according to which key must be hashed
* cnt: number of times function has already been called
in order to place the first input key
* n: maximum number of times function can be recursively
called before stopping and declaring presence of cycle */
void place(int key, int tableID, int cnt, int n){
	/* if function has been recursively called max number
	of times, stop and declare cycle. Rehash. */
	if (cnt==n){
		cout<<"\n\n"<<key<<" unpositioned\n";
		cout<<"Cycle present. REHASH.\n";
		return;
	}

	/* calculate and store possible positions for the key.
	* check if key already present at any of the positions.
	If YES, return. */
	for (int i=0; i<ver; i++){
		pos[i] = ::hash(i+1, key);
		if (hashtable[i][pos[i]] == key)
		return;
	}

	/* check if another key is already present at the
	position for the new key in the table
	* If YES: place the new key in its position
	* and place the older key in an alternate position
	for it in the next table */
	if (hashtable[tableID][pos[tableID]]!=INT_MIN){
		int dis = hashtable[tableID][pos[tableID]];
		hashtable[tableID][pos[tableID]] = key;
		place(dis, (tableID+1)%ver, cnt+1, n);
	}
	else //else: place the new key in its position
	hashtable[tableID][pos[tableID]] = key;
}

/* function to print hash table contents */
void printTable(){
	cout<<"\nFinal hash tables:\n";
	for (int i=0; i<ver; i++){
		for (int j=0; j<MAXN; j++){
			if (hashtable[i][j]==INT_MIN)
				cout<<endl<<" -1 ";
			else
				cout<<endl<<"  "<<hashtable[i][j];
		}
		//cout<<endl;
	}
	cout<<"\n";
}


void cuckoo(int keys[], int n){
	// initialize hash tables to a dummy value (INT-MIN)
	// indicating empty position
	initTable();
	// start with placing every key at its position in
	// the first hash table according to first hash
	// function
	for (int i=0, cnt=0; i<n; i++, cnt=0)
		place(keys[i], 0, cnt, n);
	//print the final hash tables
	printTable();
}

int main(){
	cout<<"\n***************************** Cuckoo Filter *********************************\n";
	int keys[MAXN], n;
	cout<<"Enter total number of elements :  ";
	cin>>n;
	cout<<"\nEnter the Elements : ";
	for (int i=0;i<n;i++)
		cin>>keys[i];

	cuckoo(keys,n);
	return 0;
}

/*
Output :

***************************** Cuckoo Filter *********************************

Enter total number of elements :  11

Enter the Elements : 30 50 63 55 100 76 115 99 88 3 1

Final hash tables:

  99
  1
 -1
  3
 -1
  115
  50
 -1
  63
 -1
  76
 -1
 -1
  30
 -1
 -1
  55
 -1
 -1
  88
  100
 -1


Process returned 0 (0x0)   execution time : 3.861 s
Press any key to continue.
*/

