#define STACK_FIRST_SIZE 16
#define max(a,b) (((a)>(b))?(a):(b))

template<typename T>
class Lstack {//异常返回值皆为-1
public:
public:
    Lstack();
    Lstack(const Lstack<T>& arr);
    ~Lstack();

    Lstack<T>& operator=(const Lstack<T>& arr);

    int size()const;
    bool empty()const;
    void clear();
    const T& top()const {return *(_arr+_size-1);}
    T& top(){return *(_arr+_size-1);}
    int push(const T& element);
    int pop();

private:
    Lstack(int size, T ans = T());
    const T& operator[](int index)const;
    T& operator[](int index);
    int insert(int index, const T& element);
    int add_head(const T& element);
    int erase(int index);
    int pop_head();
    int find(const T& element)const;

protected:
    T* _arr;
    int _size;
    int _allsize;

    void _resize();

};
//xx 实现 xx    //我寻思着，如果把下面的代码*稍微*压缩一下，会不会产生各种血压高？【滑稽】

template<typename T>
void Lstack<T>::_resize() {
    if (_size * 2 > _allsize) {//_size*4
        _allsize = _size * 4;
    }
    else if (_size * 4 < _allsize && (_allsize > STACK_FIRST_SIZE)) {//std::max(_size*2,STACK_FIRST_SIZE)
        _allsize = max(_size * 2, STACK_FIRST_SIZE);
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
inline Lstack<T>::Lstack() :_size(0), _allsize(STACK_FIRST_SIZE), _arr(nullptr) {
    _arr = new T[_allsize];
}
template<typename T>
Lstack<T>::Lstack(int size, T ans) : _size(size), _allsize(max(4 * size, STACK_FIRST_SIZE)), _arr(nullptr) {
    _arr = new T[_allsize];
    for (int i = 0; i < size; ++i) {
        _arr[i] = ans;
    }
}
template<typename T>
Lstack<T>::Lstack(const Lstack<T>& arr) :_size(arr._size), _allsize(arr._allsize), _arr(nullptr) {
    _arr = new T[_allsize];
    for (int i = 0; i < _size; ++i) {
        _arr[i] = arr._arr[i];
    }
}
template<typename T>
inline int Lstack<T>::size()const {
    return _size;
}
template<typename T>
inline bool Lstack<T>::empty()const {
    return _size == 0;
}
template<typename T>
inline void Lstack<T>::clear() {
    _size = 0, _resize();
}
template<typename T>
inline Lstack<T>::~Lstack() {
    delete[] _arr;
}
template<typename T>
Lstack<T>& Lstack<T>::operator = (const Lstack<T>& arr) {
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
inline T& Lstack<T>::operator[](int index) {
    return _arr[index];
}
template<typename T>
inline const T& Lstack<T>::operator[](int index) const{
    return _arr[index];
}
template<typename T>
int Lstack<T>::insert(int index, const T& element) {
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
inline int Lstack<T>::add_head(const T& element) {
    return insert(0, element);
}
template<typename T>
inline int Lstack<T>::push(const T& element) {
    return insert(_size, element);
}
template<typename T>
int Lstack<T>::erase(int index) {
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
inline int Lstack<T>::pop_head() {
    return erase(0);
}
template<typename T>
inline int Lstack<T>::pop() {
    return erase(_size - 1);
}
template<typename T>
int Lstack<T>::find(const T& element)const {
    for (int i = 0; i < _size; ++i) {
        if (element == _arr[i]) {
            return i;
        }
    }
    return -1;
}