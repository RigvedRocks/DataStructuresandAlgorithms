#include<bits/stdc++.h>
using namespace std;
vector<vector<float>> res;
void linear_search(int arr[],int n)
{
    char ch = 'Y',option;
    while(ch=='Y')
    {
        using namespace std::chrono;
        int target,flag = 0;
        cout<<"Enter the element you want to search for";
        cin>>target;
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int i = 0;i < n;i++)
        {
            if(arr[i] == target)
            {
                cout<<target<<" is at position "<<i<<"\n";
                flag = 1;
                break;
            }

        }
        high_resolution_clock::time_point stop = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(stop - start);
        if(!flag)
          cout<<"Sorry the element was not in the array"<<"\n";
        cout<<"Linear Search took "<< time_span.count() <<" seconds to search for the element in the array."<<"\n";
        cout<<"Want to search another element(Y/N): ";
        cin>>option;
        ch = option;
        cout<<"\n";
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
        linear_search(&arr[0],n);
        cout<<"Want to try another time with an array of different size(Y/N): ";
        cin>>option;
        ch = option;
        delete[] arr; 
    }
    cout<<"Analysis of linear search algorithm"<<"\n";
    cout<<"Size of the array "<<"\t"<<"Success"<<"\t"<<" Execution time"<<"\n";
    for(int i = 0;i < res.size();i++)
    {
        cout<<"\t"<<res[i][0]<<"\t\t"<<res[i][1]<<"\t"<<res[i][2]<<"\n";
    }

    return 0;
}