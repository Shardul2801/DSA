#include"bits/stdc++.h"
using namespace std;

//complexity => O(N) O(1)

int maxProfit(int arr[], int n){
    int maxProfit = 0;
    int minSoFar = arr[0];

    for(int i=0;i<n;i++){
        minSoFar = min(minSoFar, arr[i]);
        int profit = arr[i] - minSoFar;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}


int main() {

    int arr[] = {5,2,6,1,4};
    cout<<maxProfit(arr, 5);
    return 0;
}