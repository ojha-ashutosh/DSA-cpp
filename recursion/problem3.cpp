// binary search
#include<iostream>
using namespace std;
int soln(int arr[],int first,int last,int key){
    if (first > last) return -1;
     int mid=(first+last)/2;
     if(arr[mid]==key) return mid;
     else if(arr[mid]>key){
        return soln(arr,first,mid-1,key);
     }else{
        return soln(arr,mid+1,last,key);
     }
}
int bs(int arr[],int n,int key){
    int first=0;
    int last=n-1;
    return soln(arr,first,last,key);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = bs(arr,size, key);
    cout << "Element found at index: " << result << endl;
    return 0;
}