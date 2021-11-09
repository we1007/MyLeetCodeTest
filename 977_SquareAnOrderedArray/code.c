/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
解题思路
双指针+归并排序
步骤：1.找到负数和正数的分界位置
*/
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int PMbound,i,j;
    int *returnnum = NULL;
    PMbound = -1;
    for(i = 0;i<numsSize;i++)
    {
        if(nums[i] < 0)
            PMbound = i; //分界下标 = 负数下标
        else 
            break;
    }
    
    returnnum=(int *)malloc(sizeof(int)*numsSize);
    i = PMbound; j = PMbound+1; 
    *returnSize  = 0;
    while(i >= 0 || j < numsSize)
    {
        if(i < 0)//全是正数
        {
            returnnum[(*returnSize)++] = nums[j]*nums[j];
            ++j;
        }
        else if(j == numsSize) //全是负数
        {
            returnnum[(*returnSize)++] = nums[i]*nums[i];
            --i;
        }
        else if(nums[i]*nums[i] < nums[j]*nums[j])
        {
            returnnum[(*returnSize)++] = nums[i]*nums[i];
            --i;
        }
        else 
        {
            returnnum[(*returnSize)++] = nums[j]*nums[j];
            ++j;
        }
    }
    return returnnum;
}