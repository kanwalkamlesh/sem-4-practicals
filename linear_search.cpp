#include<iostream>
using namespace std;
int linear_search(int arr[], int n, int k)
{   int cmp = 0;
    while (cmp != n){
        for(int i=0; i<n; i++)
        {
            if (arr[i] == k)
               {
                cout << "present " << endl;
                return cmp+1;
               }
            cmp++;
        }
    }
    cout << "NOt present" << endl;
    return cmp;

}
int main()
{   
    int test_case;
    cin >> test_case;
    while(test_case!=0)
    {
    int n;
    cin >> n;
    int arr[n];
    for(int i= 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << linear_search(arr, n ,k) << endl;
    test_case--;
    }
    
}