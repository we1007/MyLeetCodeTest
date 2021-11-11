
void reverseString(char* s, int sSize)
{
    int left,right,temp;
    left = 0;
    right = sSize-1;
    if(sSize > 1)
    {
        while(left != right)
        {
            if(left > right)
                return;
            else 
            {
                temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
    }
}