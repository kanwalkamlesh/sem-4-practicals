# include<iostream>
using namespace std;
int first_occur(int arr[], int n, int k){
    int low =0, high = n-1, ans=0;
    while(low <=high){
        int mid = (low+high)/2;
        if (arr[mid] == k)
            {
                ans = mid;
                high = mid-1;
            }
        else if(arr[mid] > k)
            high = mid-1;

        else   
            low = mid+1;
    }
    return ans;
}
int last_occur(int arr[], int n, int k)
{
    int low =0, high= n-1, ans =0;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]== k)
            {
                ans = mid;
                low = mid+1;
            }
        else if(arr[mid]>k)
            high = mid-1;
        else 
            low = mid+1;
    }
    return ans;
}
int no_of_duplicates(int arr[], int n, int k){
    if (first_occur(arr, n ,k)==0){
        cout << "Key not present"<<endl;
        return -1;}
    return last_occur(arr,n,k)-first_occur(arr,n,k);
}
int main()

{   int test_case;
    cin >> test_case;
    while(test_case!=0){
     int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k ;
    cin >> k;
    cout << k<<"-" <<no_of_duplicates(arr,n,k)+1<<endl;
    test_case--;
}
    return 0;
}