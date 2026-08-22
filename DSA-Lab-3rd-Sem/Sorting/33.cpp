class Solution {
public:
    void merge(vector<pair<int, int>>& arr, int low, int mid, int high, vector<int>& count) {
        vector<pair<int, int>> temp(high - low + 1);
        int left = low;
        int right = mid + 1;
        int k = 0;
        int rightCount = 0;

        while (left <= mid && right <= high) {
            if (arr[right].first < arr[left].first) {
                rightCount++;
                temp[k++] = arr[right++];
            } else {
                count[arr[left].second] += rightCount;
                temp[k++] = arr[left++];
            }
        }

        while (left <= mid) {
            count[arr[left].second] += rightCount;
            temp[k++] = arr[left++];
        }

        while (right <= high) {
            temp[k++] = arr[right++];
        }

        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int low, int high, vector<int>& count) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, count);
        mergeSort(arr, mid + 1, high, count);
        merge(arr, low, mid, high, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        vector<int> count(n, 0);
        mergeSort(arr, 0, n - 1, count);
        return count;
    }
};
