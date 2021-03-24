#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<vector<float>> res;
#define loop(i,n) for(int i = 0;i < n;i++)

void display(int arr[],int n)
{
    loop(i,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;   
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[],int low,int high,int n)
{
    
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
        cout<<"Array undergoing partition"<<"\n";
        display(arr,n);
        quickSort(arr, low, pi - 1,n);
        quickSort(arr, pi + 1, high,n);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    char ch = 'Y',option;
    while(ch == 'Y')
    {
        int n;
        cout<<"Enter size of array - ";
        cin>>n;
        int* arr;
        arr =  new int [n]; 
        for(int i = 0;i < n;i++)
        {
            cout<<"Enter element ";
            cin>>arr[i];
        }
        
        cout<<"\n";
        cout<<"Array before sorting "<<"\n";
        display(arr,n);
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        quickSort(&arr[0],0,n-1,n);

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        
        cout<<"Array after quicksort "<<"\n";
        display(arr,n);
        cout<<"Quick Sort took "<< time_span.count() <<" seconds to sort the array."<<"\n";
        vector<float> vect;
        vect.push_back(n);
        vect.push_back(time_span.count());
        res.push_back(vect);
        cout<<"Want to try another time with an array of different size(Y/N): ";
        cin>>option;
        ch = option;
        delete[] arr; 
    }
    cout<<"Analysis of quick sort algorithm"<<"\n";
    cout<<"Size of array "<<"\t"<<" Execution time"<<"\n";
    for(int i = 0;i < res.size();i++)
    {
        cout<<"\t"<<res[i][0]<<"\t\t"<<res[i][1]<<"\n";
    }

    return 0;
}