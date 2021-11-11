/*
目前已知解法
0.从头部入手（官方解法）
1.从尾部入手（ My own solution）
问题点归类
1.nums = {0} 情况时需要防止越界，解决办法是判断为一个元素时直接return
2.nums = {0,0}情况时需要防止越界 解决办法是使右指针R往左移动直到找到非0元素位置
*/
#if 1
void moveZeroes(int *nums, int numsSize) 
{
    int L,R,i,j,temp; 
	R = numsSize - 1;

    if(numsSize == 1)
        return;
    else 
    {
        while(!nums[R])
        {
            if(R>0)
                R--;
            else 
                break;
        }
        L = R;
        while (L >= 0)
        {
            if (nums[L] == 0 && (nums[R] != 0))
            {
                j = L;
                for (i = R - L; i > 0; i--)
                {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    j++;
                }
                R--;
            }
            else
                L--;
        }
    }	
}

#else 
void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b, *b = t;
}
void moveZeroes(int *nums, int numsSize) 
{
    int left = 0, right = 0;
    while (right < numsSize) 
    {
        if (nums[right]) 
        {
            swap(nums + left, nums + right);
            left++;
        }
        right++;
    }
}
#endif 
