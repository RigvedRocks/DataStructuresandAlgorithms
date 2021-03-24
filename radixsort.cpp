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



void radixSort()
{
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

int main()
{
    cout<<"Array before sorting"<<"\n";
    display(arr,n);
    radixSort();
    cout<<"Array after sorting"<<"\n";
    display(arr,n);
    return 0;

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