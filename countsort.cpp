#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i = 0;i < n;i++)
int arr[] = {7, 6, 3, 4, 16, 5, 7, 13, 8, 12, 6, 6};
int size_array = sizeof(arr)/sizeof(arr[0]);
void display(int arr[],int n)
{
    loop(i,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void countSort()
{
    int* maxElement = std::max_element(arr,arr+size_array);
    int size = *maxElement + 1;
    int countArray[size] = {0};
    loop(i,size_array)
    {
        countArray[arr[i]]++;
    }
    cout<<"Count Array "<<"\n";
    display(countArray,size);
    int sum = 0;
    loop(i,size)
    {
        sum += countArray[i];
        countArray[i] = sum;
    }
    cout<<"Cumulative Count Array "<<"\n";
    display(countArray,size);
    int output[size_array];
    loop(i,size_array)
    {
        output[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }
    
}

int main()
{
    cout<<"Array before sorting"<<"\n";
    display(arr,size_array);
    countSort();
    cout<<"Array after sorting"<<"\n";
    display(arr,size_array);
    return 0;

}