class Solution {
public: 
// int partition(int pi,vector<int>& arr, int low, int high) {
//     int pivot = pi;   // choose last element as pivot
//     int i = low - 1;
//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort(int pi,vector<int>& arr, int low, int high) {
//     if (low < high) {
//         int p = partition(pi,arr, low, high);
//         quickSort(pi,arr, low, p - 1);
//         quickSort(pi,arr, p + 1, high);
//     }
// }

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot) ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot) ans.push_back(nums[i]);
        }
        return ans;
    }
};