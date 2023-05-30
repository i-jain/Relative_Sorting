// RELATIVE SORTING - Sorting an array according to the order defined by another array using Sorting and Binary Search

#include <iostream>
#include <algorithm>
using namespace std;

int bin_search (int arr[], int key, int start, int end){
  while (start<=end){
    int mid = start + (end-start)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) end = mid-1;
    else start = mid+1;
  }
  return -1;
}

void sortRelative (int arr1[], int arr2[], int m, int n){
  int temp[m], visited[m];
  for(int i=0; i<m; i++){
    temp[i] = arr1[i];
    visited[i]=0;
  }
  
  sort(temp, temp+m);
  
  int idx=0;
  for(int i=0; i<n; i++){
    int found = bin_search (temp, arr2[i], 0, m-1);
    if(found==-1) continue;
    for(int j=found; (j<m && temp[j]==arr2[i]); j++){
      arr1[idx++] = temp[j];
      visited[j] = 1;
    }
  }
  
  for(int i=0; i<m; i++){
    if(visited[i]==0) arr1[idx++] = temp[i];
  }
}

void printArr(int arr[], int n){
  cout<<"{";
  for(int i=0; i<n-1; i++){
    cout<<arr[i]<<",";
  }
  cout<<arr[n-1]<<"}"<<endl;
}

int main(){
  int arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
  int arr2[] = {2, 1, 8, 3};
  int m = sizeof(arr1)/sizeof(arr1[0]);
  int n = sizeof(arr2)/sizeof(arr2[0]);
  
  cout<<"Array to be sorted - ";
  printArr(arr1, m);
  cout<<"Relative to array - ";
  printArr(arr2, n);
  cout<<endl;
  sortRelative(arr1, arr2, m, n);
  cout<<"After Sorting - ";
  printArr(arr1, m);
}
