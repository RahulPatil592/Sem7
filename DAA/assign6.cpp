#include<bits/stdc++.h>
using namespace std;

int partition(int low, int high, vector<int> &arr){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(i<high && arr[i]<=pivot){
            i++;
        }
        while(j>low && arr[j]>pivot){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

int partition_rand(int low, int high, vector<int> &arr){
    int ind=low+rand()%(high-low+1);
    swap(arr[low],arr[ind]);
    return partition(low,high,arr);
}

void quickSort(int i, int j, vector<int>&arr){
    if(i<j){
        int p=partition_rand(i,j,arr);
        quickSort(i,p-1,arr);
        quickSort(p+1,j,arr);
    }
}

int main(){
    vector<int> arr={4,1,8,9,6,7};
    quickSort(0,5,arr);
    for(int i=0; i<6; i++) cout<<arr[i]<<" ";
    cout<<endl;

    
    return 0;
}