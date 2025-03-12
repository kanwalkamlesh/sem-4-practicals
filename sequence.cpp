#include<iostream>
using namespace std;
int sequence(int arr[], int n, int target){
    int low =0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if (arr[mid]==target)
            return mid;
        else if (arr[mid] < target)
            low = mid+1;
        else
            high= mid-1;
    }
    return -1;
}
int main(){
    int arr[] = {24,28,48,71,86,89,92,120,194,201};
    int k =0, j=1,i=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {  
             int target = arr[i]+arr[j];
            k = sequence(arr, n ,target); 
            if (k>0) {
                cout << i+1<<"," <<j+1<<"," << k+1<<endl;
                return 0;
            }
        } 
    }
    cout<<"no sequence found"<<endl;
        
    return 0;
}