// Name: Shruti Deepak Dhumne           Batch: E1
// Roll: 227        PRN: 0220200161     Assignment_6 (Heap Sort)

#include<bits/stdc++.h>
using namespace std;
class Heap{
public:
    void heapify_asc(int arr[], int n, int i);
    void heapSort_asc(int arr[], int n);
    void heapify_desc(int arr[], int n, int i);
    void heapSort_desc(int arr[], int n);
    void printArray(int arr[], int n);
};
void Heap :: heapify_desc(int arr[], int n, int i){          //Used for Initial creation and further sorting
    int largest = i;                                        // Initialize largest as root
    int l = 2 * i + 1;                                      // left  = (2*i + 1)
    int r = 2 * i + 2;                                      // right = (2*i + 2)
                                                             // If left child is larger than root
    if (l < n && arr[l] < arr[largest])
        largest = l;                                         // If right child is larger than largest so far
    if (r < n && arr[r] < arr[largest])
        largest = r;
    if (largest != i) {                                      // If largest is not root
        swap(arr[i], arr[largest]);
        heapify_desc(arr, n, largest);                       // Recursive call for heapify to iterate through subtrees also
    }
}
void Heap :: heapSort_desc(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)                    // Build heap (rearrange array)
        heapify_desc(arr, n, i);
                                                            // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--){
                                                            // Move current root to end
        swap(arr[0], arr[i]);
        heapify_desc(arr, i, 0);                            // call max heapify on the reduced heap
    }
}
void Heap :: heapify_asc(int arr[], int n, int i){           //Used for Initial creation and further sorting
    int smallest = i;                                        // Initialize smallest as root
    int l = 2 * i + 1;                                      // left  = (2*i + 1)
    int r = 2 * i + 2;                                      // right = (2*i + 2)
                                                            // If left child is larger than root
    if (l < n && arr[l] > arr[smallest])
        smallest = l;                                        // If right child is larger than smallest so far
    if (r < n && arr[r] > arr[smallest])
        smallest = r;
    if (smallest != i) {                                     // If smallest is not root
        swap(arr[i], arr[smallest]);
        heapify_asc(arr, n, smallest);                       // Recursive call for heapify to iterate through subtrees also
    }
}
void Heap :: heapSort_asc(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)                    // Build heap (rearrange array)
        heapify_asc(arr, n, i);
                                                            // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--){
                                                            // Move current root to end
        swap(arr[0], arr[i]);
        heapify_asc(arr, i, 0);                              // call max heapify on the reduced heap
    }
}

void Heap :: printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main(){

    cout<<"\n******************************Heap Sort********************************";
    Heap h;
    int n,ch;
    cout<<"\n1. Ascending Order\n2. Descending Order\n3. Exit";
    cout<<"\nEnter you Choice : ";
    cin>>ch;
    cout<<"\nEnter size of Array : ";
    cin>>n;
    int arr[n];
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" Element -->  ";
        cin>>arr[i];
    }
    switch(ch){
    case 1:
        cout<<"\n--------------Heap Sort Ascending Order-----------------";
       h.heapSort_asc(arr, n);
       break;
    case 2:
        cout<<"\n--------------Heap Sort Descending Order-----------------";
        h.heapSort_desc(arr, n);
        break;
    case 3:
        return 0;
    }
    cout<<"\n\nSorted array --> ";
    h.printArray(arr, n);
}

/*

OUTPUT --> Ascending



******************************Heap Sort********************************
1. Ascending Order
2. Descending Order
3. Exit
Enter you Choice : 1

Enter size of Array : 6

Enter 1 Element -->  77
Enter 2 Element -->  11
Enter 3 Element -->  44
Enter 4 Element -->  22
Enter 5 Element -->  66
Enter 6 Element -->  11

--------------Heap Sort Ascending Order-----------------

Sorted array --> 11 11 22 44 66 77





OUTPUT --> Descending



******************************Heap Sort********************************
1. Ascending Order
2. Descending Order
3. Exit
Enter you Choice : 2

Enter size of Array : 7

Enter 1 Element -->  11
Enter 2 Element -->  99
Enter 3 Element -->  22
Enter 4 Element -->  88
Enter 5 Element -->  33
Enter 6 Element -->  88
Enter 7 Element -->  44

--------------Heap Sort Descending Order-----------------

Sorted array --> 99 88 88 44 33 22 11

*/
