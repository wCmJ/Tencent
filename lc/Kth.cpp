//find the kth number in array
int partition(int *data, int start, int end)
{
	int val = data[end - 1];
	int index = start - 1;
	for(int i = start;i<end - 1;++i)
	{
		#ifdef MIN_TO_MAX
		if(data[i] < val)
		#else //MAX_TO_MIN
		if(data[i] > val)
		#endif
		{
			++index;
			int tmp = data[index];
			data[index] = data[i];
			data[i] = tmp;
		}
	}
	++index;
	int tmp = data[index];
	data[index] = data[end - 1];
	data[end - 1] = tmp;
	return index;

}

int findKth(int *data, int len, int k)//non-repeat
{
	int index;
	int start = 0, end = len;
	while(true)
	{
		index = partition(data,start,end);
		if(index == k - 1)
			break;
		else if(index < k-1)
		{
			start = index+1;
		}
		else
		{
			end = index;
		}
		
	}
	return data[index];
}
