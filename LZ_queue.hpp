#define QUEUE_FIRST_SIZE 16
#define max(a,b) (((a)>(b))?(a):(b))
#include <stddef.h>

template<class T>
class Lqueue{
public:

    Lqueue();
    Lqueue(const Lqueue<T>& queue);
    Lqueue<T>& operator=(const Lqueue<T>& queue);
    ~Lqueue();

    void clear();

    bool empty()const;
    int size()const;
    const T& front()const;
    const T& back()const;
    void push(const T& element);
    void pop();
    void swap(Lqueue<T>& queue);

protected:

    T* _arr;
    int _size;
    int _allSize;
    int _front;
    int _back;

    void _resize();
};
template<class T>
void Lqueue<T>::clear(){
    *this = Lqueue<T>();
}
template<class T>
void Lqueue<T>::_resize(){
    int allSize;
    if(_size == _allSize){//满
        allSize = 2*_allSize;
    }else if(_size*4<=_allSize&&_allSize > QUEUE_FIRST_SIZE){//缩小
        allSize = max(_allSize/2, QUEUE_FIRST_SIZE);
    }else{//其他情况无需分配
        return;
    }

    T* arr = new T[allSize]{};
    for(int i = 0; i <_size; ++i){
        arr[i] = _arr[_front];
        _front = (_front+1)%_allSize;
    }
    T* del = _arr; _arr = arr; delete[] del;
    _front = 0;
    _back = _size;
    _allSize = allSize;
}
template<class T>
void Lqueue<T>::pop(){
    if(empty()){
        throw "queue empty";
    }
    _front = (_front+1)%_allSize;
    _size--;

    _resize();
}
template<class T>
void Lqueue<T>::push(const T& element){
    _arr[_back] = element;
    _back = (_back+1)%_allSize;
    _size++;

    _resize();
}
template<class T>
inline const T& Lqueue<T>::back()const{
    if(empty()){
        throw "queue empty";
    }
    return _arr[(_back-1+_allSize)%_allSize];
}
template<class T>
inline const T& Lqueue<T>::front()const{
    if(empty()){
        throw "queue empty";
    }
    return _arr[_front];
}
template<class T>
inline int Lqueue<T>::size()const{
    return _size;
}
template<class T>
inline bool Lqueue<T>::empty()const{
    return !_size;
}
template<class T>
inline Lqueue<T>::~Lqueue(){
    delete[] _arr;
}
template<class T>
inline Lqueue<T>& Lqueue<T>::operator=(const Lqueue<T>& queue){
    Lqueue<T> tmp(queue);
    swap(tmp);
    return *this;
}
template<class T>
inline Lqueue<T>::Lqueue():_arr(new T[QUEUE_FIRST_SIZE]{}), _size(0), _allSize(QUEUE_FIRST_SIZE), _front(0), _back(0){}
template<class T>
Lqueue<T>::Lqueue(const Lqueue<T>& queue):_arr(new T[queue._allSize]{}), _size(queue._size), _allSize(queue._allsize), _front(0), _back(0){
    for(int i = queue._front; i!=queue._back; i = (i+1)%queue._allSize){
        _arr[_back++] = queue._arr[i];
    }
}
template<class T>
inline void Lqueue<T>::swap(Lqueue<T>& queue){
    T* arr = _arr; _arr = queue._arr; queue._arr = arr;
    int size = _size; _size = queue._size; queue._size = size;
    int allSize = _allSize; _allSize = queue._allSize; queue._allSize = allSize;
    int front = _front; _front = queue._front; queue._front = front;
    int back = _back; _back = queue._back; queue._back = back;
}
//! need #include <LZ_vector>
template<class T>
class Lpriority_queue{
public:
    Lpriority_queue();
    Lpriority_queue(const Lpriority_queue<T>&) = default;
    Lpriority_queue<T>& operator=(const Lpriority_queue<T>&) = default;
    ~Lpriority_queue() = default;

    void clear();

    T top()const;
    bool empty()const;
    size_t size()const;
    void push(const T& element);
    void pop();
    void swap(Lpriority_queue<T>& pri_queue);

protected:
    Lvector<T> data_;
};
template<class T>
inline void Lpriority_queue<T>::clear(){
    data_.clear();
    data_.push_back(T());
}
template<class T>
Lpriority_queue<T>:: Lpriority_queue():data_(1, T()){}
template<class T>
inline T Lpriority_queue<T>::top()const{
    if(empty())
        throw "priority queue empty!";

    return data_[1];
}
template<class T>
inline bool Lpriority_queue<T>::empty()const{
    return data_.size()==1;
}
template<class T>
inline size_t Lpriority_queue<T>::size()const{
    return data_.size()-1;
}
template<class T>
inline void Lpriority_queue<T>::swap(Lpriority_queue<T>& pri_queue){
    Lvector<T> tmp(data_);
    data_ = pri_queue.data_;
    pri_queue.data_ = tmp;
}
template<class T>
void Lpriority_queue<T>::push(const T& element){
    data_.push_back(element);
    size_t itr = size();
    while(itr>1){
        if(data_[itr/2]<data_[itr]){
            T tmp = data_[itr];
            data_[itr] = data_[itr/2];
            data_[itr/2] = tmp;

            itr/=2;
            continue;
        }else{// done
            break;
        }
    }
}
template<class T>
void Lpriority_queue<T>::pop(){
    if(empty())
        throw "priori queue empty";
    data_[1] = data_[size()];
    data_.pop_back();
    size_t itr = 1;
    while(itr*2 <= size()){// itr还有孩子的情况才继续
        if(itr*2+1>size()){//快到底了，只有左子树
            if(data_[itr]<data_[itr*2]){
                T tmp = data_[itr];
                data_[itr] = data_[itr*2];
                data_[itr*2] = tmp;

                break;
            }else{//done
                break;
            }
        }else{//看不到底
            if(data_[itr*2]<data_[itr*2+1]){//右孩子大
                if(data_[itr]<data_[itr*2+1]){
                    T tmp = data_[itr];
                    data_[itr] = data_[itr*2+1];
                    data_[itr*2+1] = tmp;

                    itr = itr*2+1;
                    continue;
                }else{//done
                    break;
                }
            }else{//左孩子大
                if(data_[itr]<data_[itr*2]){
                    T tmp = data_[itr];
                    data_[itr] = data_[itr*2];
                    data_[itr*2] = tmp;

                    itr = itr*2;
                    continue; 
                }else{//done
                    break;
                }
            }
        }
    }
}
