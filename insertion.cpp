#include<iostream>
#include<stdlib.h>
using namespace std;

int main() 
{
    int n, pos, val, i;

    cout<<"Enter number of elements in an array: \n";
    cin>>n;

    int a[n];

    cout<<"Enter array elements: \n";
    for (i=0;i<n;i++) 
    {
        cin >> a[i];
    }

    cout<<"Enter the position to insert an element: \n";
    cin>>pos;
    if(pos>n+1)
    {
        cout<<"Cannot insert element to this position as the position is greater than array size\n";
        exit(0);
    }

    cout<<"Enter the element to be inserted: \n";
    cin>>val;

    cout<<"Array before inserting: ";
    for (i=0;i<n;i++) 
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n";
    
    n = n + 1;

    for(i=n-1;i>=pos-1;i--) 
    {
        a[i] = a[i - 1];
    }

    a[pos-1] = val;

    cout<< "After Inserting Array Is: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout<<"\n";

    return 0;
}
