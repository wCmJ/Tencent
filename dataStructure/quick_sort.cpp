void swap(int arr[], int x, int y){
	//method1
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
	//method2
	if(x != y){
		arr[x] = arr[x] ^ arr[y];
		arr[y] = arr[x] ^ arr[y];
		arr[x] = arr[x] ^ arr[y];	
	}
}


void quickSort(int arr[], int start, int end){
	if(arr == NULL || start >= end)return;
	int idx = end, i = start;
	int less = start - 1;
	while(i < idx){
		if(arr[i] < arr[idx]){
			swap(arr, ++less, i);
		}
		++i;
	}
	swap(arr, ++less, idx);
	quickSort(arr, start, less - 1);
	quickSort(arr, less + 1, end);
}

void quickSortAdv(int arr[], int start, int end){
	if(arr == NULL || start >= end)return;
	int less = start - 1, more = end;
	int i = start, idx = end;
	while(i < more){
		if(arr[i] < arr[idx]){
			swap(arr, ++less, i++);
		}
		else if(arr[i] > arr[idx]){
			swap(arr, --more, i);
		}
		else{
			++i;
		}
	}
	swap(arr, more++, idx);
	quickSortAdv(arr, start, less);
	quickSortAdv(arr, more, end);
}
