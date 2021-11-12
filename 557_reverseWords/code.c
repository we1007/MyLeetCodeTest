/*
分析：出现以空格字符为界限划分单词
*/
char * reverseWords(char * s)
{
    int left = 0;
    int right = 0;
    char temp;
	int R;
    int length = strlen(s);

    while(s[right] != '\0')
    {
        if (s[right] != ' ')
		{
			if (right == length - 1)
			{
				R = right;
				while (left != R)
				{
					if (left > R)
						break;
					else
					{
						temp = s[left];
						s[left] = s[R];
						s[R] = temp;
						left++;
						R--;
					}
				}
			}
			right++;
		}
        else 
        {
            R = right-1;
            while(left != R)
            {
                if(left > R)
                    break;
                else 
                {
                    temp = s[left];
                    s[left] = s[R];
                    s[R] = temp;
                    left++;
                    R--;
                }
            }
            right++;
            left = right;
        }    
    }
    return s;
}