
int search(int* nums, int numsSize, int target)
{
    int low,mid,high;
    low = 0;
    high = numsSize-1;

    while(low <= high)
    {
        mid = (low + high)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target) //查找前部
            high = mid-1;
        else //查找后部
            low = mid+1;
    }
    return -1;
}