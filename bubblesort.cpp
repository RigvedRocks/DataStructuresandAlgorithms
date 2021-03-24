#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<vector<float>> res;
void bubble_sort(int arr[],int n)
{
        int flag = 0;
        cout<<"Array before sorting - "<<"\n";
        for(int i = 0;i < n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        for(int i = 0; i < n - 1;i++)
        {
            for(int j = 0;j < n-i-1;j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    swap(arr[j],arr[j+1]);
                    flag = 1;
                }
                else
                    flag = 0;
            }

            if(!flag)
               break;
        }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        
        cout<<"Bubble Sort took "<< time_span.count() <<" seconds to sort the array."<<"\n";
        cout<<"Array after sorting - "<<"\n";
        for(int i = 0; i < n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        vector<float> vect;
        vect.push_back(n);
        vect.push_back(time_span.count());
        res.push_back(vect);
    
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
        bubble_sort(&arr[0],n);
        cout<<"Want to try another time with an array of different size(Y/N): ";
        cin>>option;
        ch = option;
        delete[] arr; 
    }
    cout<<"Analysis of bubble sort algorithm"<<"\n";
    cout<<"Size of the array "<<"\t\t"<<" Execution time"<<"\n";
    for(int i = 0;i < res.size();i++)
    {
        cout<<"\t"<<res[i][0]<<"\t\t"<<res[i][1]<<"\n";
    }

    return 0;
}