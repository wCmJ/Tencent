
template<typename T>
void setIndex(T *data, int len, int index)
{
    while(true)
    {
        //get max value from index and its children
        int maxValueIndex = index;
        if((2 * index + 1 < len) && data[2 * index + 1] > data[maxValueIndex])
            maxValueIndex = 2 * index + 1;
        if((2 * index + 2 < len) && data[2 * index + 2] > data[maxValueIndex])
            maxValueIndex = 2 * index + 2;
            
        //max in children            
        if(maxValueIndex != index)
        {
            T tmp = data[maxValueIndex];
            data[maxValueIndex] = data[index];
            data[index] = tmp;
            index = maxValueIndex;
        }
        else//index is the max
            break;    
    }
}

template<typename T>
void construct(T *data, int len)
{
    if(data == NULL || len < 1)
        return;
    int index = len / 2;
    while(index >= 0)
    {
        setIndex(data, len, index--);
    }
}

template<typename T>
void insert(T *data, int index, T value)
{
    //assert element can be inserted to heap
    //assert(index < len);
    data[index] = value;
    while(index)
    {
        int parent = (index - 1)/2;
        if(data[parent] < data[index])
        {
            T tmp = data[parent];
            data[parent] = data[index];
            data[index] = tmp;
            index = parent;        
        }
        else
            break;
    }
}

template<typename T>
void remove(T *data, int len)
{
    T tmp = data[0];
    data[0] = data[len - 1];
    data[len - 1] = tmp;
    setIndex(data, --len, 0);
}

//heap sort
template<typename T>
void heapSort(T *data, int len)
{
    construct(data, len);
    while(len)
        remove(data, len--);
}
