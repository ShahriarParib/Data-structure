#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int linear_search(int a[],int n,int x)
{
    int i;
    for(i=0; i<n; i++)
    {

        if(a[i]==x)
        {
            return i+1;

        }

    }
    return -1;

}
void bubblesorting(int a[],int n)
{

    for(int i=0; i<n; i++)
    {

        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    cout<<"The sorted array by bubble sort is:";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }
    cout<<"The sorted array by selction sort is:";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout<<"The sorted array by insertion sort is:";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binary__search(int a[],int n,int x)
{
    int left=0;
    int right=n-1;

    while(left<=right)
    {
        int mid =(left+right)/2;
        if(a[mid]==x)
        {

            return mid+1;
        }
        if(a[mid]<x)
        {
            left=mid+1;

        }
        if(a[mid]>x)
        {
            right=mid-1;

        }

    }
    return -1;

}
int main()
{
    int n,i,x;
    cout<<"Enter array size:";
    cin>>n;
    int a[n];
    cout<<"Enter array elements:";
    for(i=0; i<n; i++)
    {

        cin>>a[i];
    }
    cout<<"Element to find:";
    cin>>x;
    bubblesorting(a,n);
    insertionSort(a,n);
    selectionSort(a,n);
    cout<<"The position by binary search is: ";
    cout<<binary__search(a,n,x)<<endl;
    cout<<"The position by linear search is: ";
    cout<<linear_search(a,n,x)<<endl;


}

