int searchInsert(int* nums, int numsSize, int target)
{
    int low,mid,high;
    low = 0;
    high = numsSize-1;

    while(low <= high)
    {
        mid = low + (high - low)/2;
        if(nums[mid] >= target)
            high = mid - 1;        
        else 
            low = mid + 1;            
    }
    return low;
}