template<typename T>
class Heap{
public:
    Heap(T* datas, int size):_size(size > 0 ? size : 1){
        _data = new T[_size];
        for(int i = 0;i<size;++i){
            _data[i] = datas[i];
        }
        construct_heap();
    }

    void construct_heap(){
        
    
    
    }

private:
    T* _data;
    int _size;
};




