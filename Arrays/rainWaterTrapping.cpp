#include"bits/stdc++.h"
using namespace std;
//Rainwater Tapping prob

int rainwaterTapping(int arr[], int n){

    // int left[n];
    // int right[n];
    // int val = 0;
    // left[0] = arr[0];
    // right[n-1] = arr[n-1];

    // for(int i=1;i<n;i++){
       
    //     left[i] = min(left[i-1], arr[i]);
    // }

    // for(int i=n-2;i>=0; i--){
    //     right[i] = max(right[i+1], arr[i]);
    // }

    // for(int i=0;i<n;i++){
    //     val = val + (min(left[i], right[i]) - arr[i]);
    // }
    // return val;
    int res = 0;

     for (int i = 1; i < n-1; i++) {

         int left = arr[i];
        for (int j=0; j<i; j++)
           left = max(left, arr[j]);

            int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = max(right, arr[j]);

            res = res + (min(left, right) - arr[i]);  
     }
     return res;

}



int main() {

    int arr[] = {3, 0, 2, 0, 4};
    cout<<rainwaterTapping(arr,5);
    return 0;
}