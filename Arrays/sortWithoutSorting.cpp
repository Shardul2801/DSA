#include "bits/stdc++.h"
using namespace std;

void sort012(int arr[], int n){
    //f
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        switch (arr[mid]) {
            case 0: 
                swap(arr[low++],arr[mid++] );
                break;

            case 1: 
                mid++;
                break;

            case 2:
                swap(arr[mid], arr[high--] );
                break;        
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    };
    
}

int main() {

    int arr[] = {0, 2, 1, 2, 0};
    int n = 5; 
    sort012(arr, 5);

    return 0;
}