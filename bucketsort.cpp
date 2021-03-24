#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i = 0;i < n;i++)
float arr[] = { 71, 10, 31, 41, 16, 46, 51, 21, 13, 8};
int n = sizeof(arr)/sizeof(arr[0]);
void display(float arr[],int n)
{
    loop(i,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void bucketSort()
{
    vector<float> b[n];
    
    loop(i,n)
    {
       int x = n*arr[i];
       b[x].push_back(arr[i]);
    }
 
    loop(i,n)
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    loop(i,n)
    {
        loop(j,b[i].size())
           arr[index++] = b[i][j];

    }
}

int main()
{
    cout<<"Array before sorting"<<"\n";
    display(arr,n);
    bucketSort();
    cout<<"Array after sorting"<<"\n";
    display(arr,n);
    return 0;

}