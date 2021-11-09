void rotate(int* nums, int numsSize, int k)
{
   	int i, q;
    int *pswap = NULL;
    int *swap = (long *)malloc(sizeof(int)*(numsSize * 2));
    pswap = swap;

    if(k > numsSize)
        k = k%numsSize;

	i = numsSize - 1 + k;
	q = numsSize - 1;
	for (q = numsSize - 1; q >= 0; q--)
	{
		pswap[k + q] = nums[q];
	}

	q = numsSize - 1;
	for (i = k-1; i >= 0; i--)
	{
		pswap[i] = pswap[k + q];
		q--;
	}
	for (i = 0; i < numsSize; i++)
	{
		nums[i] = pswap[i];
	}
	free(swap);
}   