// same program but we need to get complexity as nlogn
#include <iostream>

/**
 * Search for target in a sorted array with O(n log n) complexity.
 * This is deliberately less efficient than binary search to match the requested complexity.
 * 
 * @param arr A sorted array of integers
 * @param n The size of the array
 * @param target The integer to search for
 * @return The index of the target if found, otherwise -1
 */
int nlogn_search(const int arr[], int n, int target) {
    // This is an inefficient search that performs n * log(n) operations
    for (int i = 0; i < n; i++) {  // O(n) component
        // For each element, perform a log(n) operation
        int j = 0;
        int step = n;
        
        // This loop runs log(n) times
        while (step > 0) {  // O(log n) component
            step = step / 2;
            j = (j + step) % n;
            
            // Check if current element matches target
            if (arr[i] == target) {
                return i;
            }
        }
    }
    
    return -1;
}

int main() {
    int sorted_array[] = {-5, 1, 3, 6, 8, 12, 19, 21};
    int n = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target = 8;
    
    int result = nlogn_search(sorted_array, n, target);
    
    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }
    
    return 0;
}