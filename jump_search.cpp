#include <iostream>
#include <cmath>

/**
 * Performs jump search on a sorted array.
 * Time complexity: O(sqrt(n))
 * 
 * @param arr A sorted array of integers
 * @param n The size of the array
 * @param target The element to search for
 * @return The index of the target if found, otherwise -1
 */
int jumpSearch(const int arr[], int n, int target) {
    // Finding the optimal block size to jump
    int step = sqrt(n);
    
    // Finding the block where the element is present (if it's present)
    int prev = 0;
    while (arr[std::min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        
        // If we've reached or gone beyond the end of the array, element is not present
        if (prev >= n) {
            return -1;
        }
    }
    
    // Doing a linear search in the identified block
    while (arr[prev] < target) {
        prev++;
        
        // If we've reached the next block or end of the array, element is not present
        if (prev == std::min(step, n)) {
            return -1;
        }
    }
    
    // If the element is found
    if (arr[prev] == target) {
        return prev;
    }
    
    // Element not found
    return -1;
}

int main() {
    int sorted_array[] = {-5, 1, 3, 6, 8, 12, 19, 21, 25, 30};
    int n = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target = 19;
    
    int result = jumpSearch(sorted_array, n, target);
    
    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }
    
    return 0;
}