

int maxsumofSubarray(int* arr, int arrLen ) {
    // write code here
    int sum = 0;
    int max = 0;
    for (int i = 0; i < arrLen; i++) {
        if (arr[i] >= 0)
            sum += arr[i];
        else
            sum = 0;
        if (sum > max)
            max = sum;
    }
    return max;
}

int maxSubArray(int* nums, int numsSize){

    int max = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        nums[i] += fmax(nums[i - 1], 0);
        max = fmax(max, nums[i]);
    }
    return max;
}