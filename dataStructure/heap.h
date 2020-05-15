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
        for(int i = _size/2;i >= 0; --i){
            construct_node(i, _size);       
        }    
    }
    
    void heap_sort(){
        for(int i = _size - 1;i>0;--i){
            _data[i] = _data[i] ^ _data[0];
            _data[0] = _data[i] ^ _data[0];
            _data[i] = _data[i] ^ _data[0];
            construct_node(0, i);
        }
        for(int i = 0;i<_size;++i){
            std::cout<<_data[i]<<" ";   
        }
        std::cout<<std::endl;
    }
private:
    void construct_node(int idx, int size){
        if(idx < 0 || idx >= size)return;
        int max_idx = idx;
        if(2*idx + 1 < size && _data[2*idx + 1] > _data[max_idx]){
            max_idx = 2 * idx + 1;   
        }
        if(2*idx + 2 < size && _data[2*idx + 2] > _data[max_idx]){
            max_idx = 2 * idx + 2;   
        }
        if(max_idx != idx){
            _data[max_idx] = _data[max_idx] ^ _data[idx];
            _data[_idx] = _data[max_idx] ^ _data[idx];
            _data[max_idx] = _data[max_idx] ^ _data[idx];   
            construct_node(max_idx, size);
        }           
    }
private:    
    T* _data;
    int _size;
};




