// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    int low,mid,high;
    low = 1;
    high = n;
    while(low < high)
    {
        //mid = (low + high) / 2;  //当low 和 high 相加的时可能超出int 的范围 改进如下
        mid = low + (high-low) / 2;  //防止溢出 
        if(isBadVersion(mid)) //错误版本
            high = mid;
        else //正确版本
            low = mid+1;
    }
    return (low);
}