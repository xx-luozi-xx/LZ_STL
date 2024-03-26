#define LVECTOR_FIRST_SIZE 16
#define max(a,b) (((a)>(b))?(a):(b))

template<typename T>
class Lvector {//异常返回值皆为-1
public:
    class iterator{
        public:        
        iterator(T* ptr = nullptr):_ptr(ptr){}
        T& operator*()const { return *_ptr;}
        T* operator->()const {return _ptr;}
        iterator& operator++(){ ++_ptr; return *this;}
        iterator operator++(int){iterator old = *this; ++_ptr; return old;}
        bool operator==(const iterator& rhs)const {return _ptr==rhs._ptr;}
        bool operator!=(const iterator& rhs)const {return _ptr!=rhs._ptr;}

        T* _ptr;
    };
public:
    Lvector();
    Lvector(int size, T ans = T());
    Lvector(const Lvector<T>& arr);
    ~Lvector();

    Lvector<T>& operator=(const Lvector<T>& arr);
    T& operator[](int index);
    const T& operator[](int index)const;

    iterator begin()const {return _arr;}
    iterator end()const {return _arr+_size;}

    int size()const;
    bool empty()const;
    void clear();

    int insert(int index, const T& element);
    iterator insert(iterator idx, const T& element);
    int add_head(const T& element);
    int push_back(const T& element);

    int erase(int index);
    iterator erase(const iterator idx);
    int pop_head();
    int pop_back();

    int find(const T& element)const;

protected:
    T* _arr;
    int _size;
    int _allsize;

    void _resize();

};
//xx 实现 xx    //我寻思着，如果把下面的代码*稍微*压缩一下，会不会产生各种血压高？【滑稽】
template<class T>
typename Lvector<T>::iterator Lvector<T>::insert(Lvector<T>::iterator idx, const T& element){
    insert(idx._ptr-_arr, element);
    return idx;
}
template<class T>
typename Lvector<T>::iterator Lvector<T>::erase(Lvector<T>::iterator idx){
    erase(idx._ptr-_arr);
    return idx;
}
template<typename T>
void Lvector<T>::_resize() {
    if (_size * 2 > _allsize) {//_size*4
        _allsize = _size * 4;
    }
    else if (_size * 4 < _allsize && (_allsize > LVECTOR_FIRST_SIZE)) {//std::max(_size*2,LVECTOR_FIRST_SIZE)
        _allsize = max(_size * 2, LVECTOR_FIRST_SIZE);
    }
    else {//其他情况无需分配
        return;
    }
    T* box = new T[_allsize];
    for (int i = 0; i < _size; ++i) {
        box[i] = _arr[i];
    }
    delete[] _arr;
    _arr = box;
}
template<typename T>
inline Lvector<T>::Lvector() :_size(0), _allsize(LVECTOR_FIRST_SIZE), _arr(nullptr) {
    _arr = new T[_allsize];
}
template<typename T>
Lvector<T>::Lvector(int size, T ans) : _size(size), _allsize(max(4 * size, LVECTOR_FIRST_SIZE)), _arr(nullptr) {
    _arr = new T[_allsize];
    for (int i = 0; i < size; ++i) {
        _arr[i] = ans;
    }
}
template<typename T>
Lvector<T>::Lvector(const Lvector<T>& arr) :_size(arr._size), _allsize(arr._allsize), _arr(nullptr) {
    _arr = new T[_allsize];
    for (int i = 0; i < _size; ++i) {
        _arr[i] = arr._arr[i];
    }
}
template<typename T>
inline int Lvector<T>::size()const {
    return _size;
}
template<typename T>
inline bool Lvector<T>::empty()const {
    return _size == 0;
}
template<typename T>
inline void Lvector<T>::clear() {
    _size = 0, _resize();
}
template<typename T>
inline Lvector<T>::~Lvector() {
    delete[] _arr;
}
template<typename T>
Lvector<T>& Lvector<T>::operator = (const Lvector<T>& arr) {
    delete[] _arr;
    _size = arr._size;
    _allsize = arr._allsize;
    _arr = new T[_allsize];
    for (int i = 0; i < _size; ++i) {
        _arr[i] = arr._arr[i];
    }
    return *this;
}
template<typename T>
inline T& Lvector<T>::operator[](int index) {
    return _arr[index];
}
template<typename T>
inline const T& Lvector<T>::operator[](int index) const{
    return _arr[index];
}
template<typename T>
int Lvector<T>::insert(int index, const T& element) {
    if (index<0 || index>_size) {//不合法下标
        return -1;
    }
    for (int i = _size; i > index; --i) {
        _arr[i] = _arr[i - 1];
    }
    _arr[index] = element;
    _size++;
    _resize();
    return 0;
}
template<typename T>
inline int Lvector<T>::add_head(const T& element) {
    return insert(0, element);
}
template<typename T>
inline int Lvector<T>::push_back(const T& element) {
    return insert(_size, element);
}
template<typename T>
int Lvector<T>::erase(int index) {
    if (index < 0 || index >= _size) {//不合法下标
        return -1;
    }
    for (int i = index; i + 1 < _size; ++i) {
        _arr[i] = _arr[i + 1];
    }
    _size--;
    _resize();
    return 0;
}
template<typename T>
inline int Lvector<T>::pop_head() {
    return erase(0);
}
template<typename T>
inline int Lvector<T>::pop_back() {
    return erase(_size - 1);
}
template<typename T>
int Lvector<T>::find(const T& element)const {
    for (int i = 0; i < _size; ++i) {
        if (element == _arr[i]) {
            return i;
        }
    }
    return -1;
}