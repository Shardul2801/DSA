#include "bits/stdc++.h" 
using namespace std;
//Search an ele, insert an ele, delete an ele...

int search(int arr[], int val, int n){
    for(int i=0; i<n; i++) {
        if(arr[i] == val){
            return i;
        }
       
    }
    return false;
}

int insert(int arr[], int num, int y, int n ){
    if(y  >  n){
        return false;
    }
    else{
        for(int i=0;i<=n; i++){
            if(i==y)
            arr[i] == num;
            return true;
        }
        
    }
};




int main() {
   
   int arr[] = {10, 23, 46, 12, 24};
    int n = 5;
    
    
    cout<<search(arr , 46, 5)<<endl;
    cout<<insert(arr, 25, 1, 5);
    
   
    return 0;
}

    