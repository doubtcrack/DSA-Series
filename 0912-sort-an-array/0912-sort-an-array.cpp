class Solution {
public:
// ---------------- Merge Sort Approach ------------------ //


// void merge(vector<int>& nums, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
    
//     vector<int> leftArr(n1);
//     vector<int> rightArr(n2);
    
//     for (int i = 0; i < n1; ++i)
//         leftArr[i] = nums[left + i];
//     for (int j = 0; j < n2; ++j)
//         rightArr[j] = nums[mid + 1 + j];
    
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (leftArr[i] <= rightArr[j]) {
//             nums[k] = leftArr[i];
//             i++;
//         } else {
//             nums[k] = rightArr[j];
//             j++;
//         }
//         k++;
//     }
    
//     while (i < n1) {
//         nums[k] = leftArr[i];
//         i++;
//         k++;
//     }
    
//     while (j < n2) {
//         nums[k] = rightArr[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(vector<int>& nums, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(nums, left, mid);
//         mergeSort(nums, mid + 1, right);

//         cout<<left<<mid<<right<<" ";
//         merge(nums, left, mid, right);
//     }
// }


// -------------------- Heap Sort Approach ------------------- //


// Function to heapify a subtree rooted with node i
void heapify(vector<int>& nums, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && nums[left] > nums[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && nums[right] > nums[largest])
        largest = right;

    // If the largest is not root
    if (largest != i) {
        swap(nums[i], nums[largest]); 

        // Recursively heapify the affected subtree
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();

    // Build heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(nums[0], nums[i]);

        // Call heapify on the reduced heap
        heapify(nums, i, 0);
    }
}

    vector<int> sortArray(vector<int>& nums) {
        // mergeSort(nums, 0, nums.size() - 1);
       
        heapSort(nums);
        return nums;
    }
};