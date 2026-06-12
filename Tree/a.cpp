// You are given an infinite sorted array of distinct integers arranged in ascending order. 
// The task is to find the index of a given target number, x, in the array. If the target number does not exist in the array, return -1.
// Since the array is infinite, the length of the array cannot be determined directly, and accessing elements beyond the actual size of the
// array will result in an out-of-bounds error. 
// You must design an algorithm to efficiently locate the target number without knowing the size of the array.

// Input:
// arr = [1, 3, 5, 7, 9, ...] (infinite)
// x = 7

// Output:
// 3

// Input:
// arr = [2, 4, 6, 8, ...] (infinite)
// x = 50

// Output:
// -1
/*
l = 0, h =1 
 if arr[h] < target 
 l = h
 h = h*2 // infinite array 

 else if arr[h] >= target
        -- binary search on achieved range
       --- binarysearch(l , h) 
    
     1 , 2 ,4 
*/

#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>&arr, int target, int low, int high){

    while(low<=high){

        int mid = low + (high -low)/2;


        if(arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            low = mid +1 ;
        }
        else 
            high = mid -1;
        }
        return -1;
    }

int infinite_search(vector<int>&arr, int target){

    int low = 0;
    int high = 1;

    while(arr.at(high) < target){
        low = high;
        high = high*2;
        
        
    // binary search on range
    int res = binary_search(arr,target,low,high);
    return res;
}
int main(){

    // int n;
    cout<<"taking input size of array"<<endl;

    // cin>>n;
    // n = 10;
    int target;

    cout<<"taking target element"<<endl;
    // cin>>target;
    target = 1234323242;
    vector<int>arr = {1,888,99999, 12121213,12121214,1234323242};
    // for(int i =0;i<n;i++){
    //     cin>>arr[i];
    // }
    int res = infinite_search(arr,target);
    cout<<"the index "<<res<<endl;
    return 0;
}
