#include <iostream>
#include <algorithm>

using namespace std;

int countPairsWithDifferenceK(int arr[], int n, int k) {
    sort(arr, arr + n);  // Sort the array in ascending order
    int count = 0;
    int left = 0, right = 1;

    while (right < n) {
        int diff = arr[right] - arr[left];

        if (diff == k) {
            count++;
            left++;
            right++;  // Move both pointers forward to avoid duplicate pairs
        } 
        else if (diff < k) {
            right++;  // Increase right pointer if difference is less than k
        } 
        else {
            left++;  // Increase left pointer if difference is more than k
        }

        // Ensure left is not ahead of right
        if (left == right) {
            right++;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Number of pairs with difference " << k << " is: " << countPairsWithDifferenceK(arr, n, k) << endl;

    return 0;
}
