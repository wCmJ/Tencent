

void oddBeforeEven(int *data, int len)
{
    if(data == NULL || len < 2)
        return;
    int left = 0, right = len - 1;
    while(left < right)
    {
        while(left < right && data[left] % 2 != 0)++left;
        while(left < right && data[right] % 2 == 0)--right;
        if(left != right)
        {
            int tmp = data[left];
            data[left] = data[right];
            data[right] = tmp;            
        }
    }
}
