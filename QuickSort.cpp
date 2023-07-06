#include<bits/stdc++.h>
using namespace std;

int getPartition(int low,int high,vector<int> &arr){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(i<=high-1 && arr[i]<=pivot) i++;
        while(j>=low+1 && arr[j]>pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int low,int high,vector<int> &arr){
    if(low<high){
        int ind=getPartition(low,high,arr);
        quickSort(low,ind-1,arr);
        quickSort(ind+1,high,arr);
    }
}

int main(){
    vector<int> arr={4,6,2,5,7,9,1,3};
    int n=arr.size();
    quickSort(0,n-1,arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}