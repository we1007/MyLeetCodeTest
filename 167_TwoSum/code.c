/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /*
 解题分析
 0.(官方解法): 双指针，一个指针在前，一个指针在后，前后协调逼近target
 1.(My own solution):双指针，指针在同一端，右指针向前遍历，左指针被动前移
注意在移动右指针时防止出现越界情况
 */
 #if 0
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int sum;
    int left = 0, right = 1;
    *returnSize = 2;
    int *answer = (int*)malloc(sizeof(int)*2);
	if (numbersSize > 1)
	{
		while (left != numbersSize - 1)
		{
			if ((numbers[left] + numbers[right]) == target)
			{
				answer[0] = left + 1;
				answer[1] = right + 1;				
				return answer;
			}
			else
			{
                right++;	

				if (right == numbersSize)
				{
					left++;
					right = left + 1;
				}								
			}
		}	
	}
    answer[0] = -1;
	answer[1] = -1;
    return answer;
}
#else
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int low = 0, high = numbersSize - 1;
    while (low < high) 
    {
        int sum = numbers[low] + numbers[high];
        if (sum == target) 
        {
            ret[0] = low + 1, ret[1] = high + 1;
            return ret;
        } 
        else if (sum < target) 
        {
            ++low;
        } 
        else 
        {
            --high;
        }
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}
#endif