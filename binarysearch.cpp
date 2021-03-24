#include<bits/stdc++.h>
using namespace std;
vector<vector<float>> res;
void binary_search(int arr[],int n)
{
    char ch = 'Y',option;
    while(ch=='Y')
    {
        using namespace std::chrono;
        int target,flag = 0;
        cout<<"Enter the element you want to search for";
        cin>>target;
        int start = 0,end = n - 1;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        
        while(start<=end)
        {
            int middle = start + (end - start)/2;
            if(arr[middle] == target)
            {
                flag = 1;
                cout<<target<<" is at position "<<middle<<"\n";
                break;
            }
            else if(arr[middle]>target)
            {
                end = middle - 1;
            } 
            else
                start = middle + 1;
        }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        if(!flag)
          cout<<"Sorry the element was not in the array"<<"\n";
        cout<<"Binary Search took "<< time_span.count() <<" seconds to search for the element in the array."<<"\n";
        cout<<"Want to search another element(Y/N): ";
        cin>>option;
        cout<<"\n";
        ch = option;
        vector<float> vect;
        vect.push_back(n);
        vect.push_back(flag);
        vect.push_back(time_span.count());
        res.push_back(vect);
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
            arr[i] = rand();
        }
        binary_search(&arr[0],n);
        cout<<"Want to try another time with an array of different size(Y/N): ";
        cin>>option;
        ch = option;
        delete[] arr; 
    }
    cout<<"Analysis of binary search algorithm"<<"\n";
    cout<<"Size of the array "<<"\t"<<"Success"<<"\t"<<" Execution time"<<"\n";
    for(int i = 0;i < res.size();i++)
    {
        cout<<"\t"<<res[i][0]<<"\t\t"<<res[i][1]<<"\t"<<res[i][2]<<"\n";
    }

    return 0;
}