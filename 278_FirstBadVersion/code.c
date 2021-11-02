// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    int low,mid,high;
    low = 1;
    high = n;
    while(low < high)
    {
        mid = (low + high) / 2; 
        //mid = low + (high-low) / 2;  //防止溢出
        if(isBadVersion(mid)) //错误版本
            high = mid;
        else //正确版本
            low = mid+1;
    }
    return (low);
}