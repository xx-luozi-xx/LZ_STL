template<class T>
class Lforward_list{
public:
    template<class Y>
    struct node{
        node(const Y& val= Y(), node<Y>* next = nullptr):element(val), next(next){}

        Y element;
        node* next;
    };
    class iterator{
        public:        
        iterator(node<T>* node = nullptr):_node(node){}
        T& operator*()const { return _node->element;}
        T* operator->()const {return &_node->element;}
        iterator& operator++(){ _node = _node -> next; return *this;}
        iterator operator++(int){iterator old = *this; _node = _node -> next; return old;}
        bool operator==(const iterator& rhs)const {return _node==rhs._node;}
        bool operator!=(const iterator& rhs)const {return _node!=rhs._node;}

        node<T>* _node;
    };

public:

    Lforward_list();
    Lforward_list(unsigned long long n, const T& val = T());
    Lforward_list(Lforward_list<T>::iterator begin, Lforward_list<T>::iterator end);
    Lforward_list(const Lforward_list<T>&);
    Lforward_list<T>& operator=(const Lforward_list<T>&);
    ~Lforward_list();

    iterator begin()const {return iterator(first);}
    iterator end()const {return iterator();}
   
    bool empty() const;

    const T& front()const;
    T& front();
    
    void assign(Lforward_list<T>::iterator begin, Lforward_list<T>::iterator end);
    void assign(unsigned long long n, const T& val = T());
    void push_front(const T& val);
    void pop_front();
    iterator insert_after(iterator pos, const T& val = T());
    iterator insert_after(iterator pos, unsigned long long n, const T& val = T());
    iterator insert_after(iterator pos, Lforward_list<T>::iterator begin, Lforward_list<T>::iterator end);
    iterator erase_after(iterator pos);
    iterator erase_after(iterator pos, Lforward_list<T>::iterator last);
    void resize(unsigned long long n, const T& val = T());
    void clear();
    void swap(Lforward_list<T>& fwdlst);
    void reverse();
    void sort();
    void merge(Lforward_list<T>& fwlst);
    
protected:
    node<T>* first;
   
};//实现在下
template<class T>
void Lforward_list<T>::merge(Lforward_list<T>& fwlst){
    Lforward_list<T> tmp;
    while(!empty()&&!fwlst.empty()){
        if(front()<fwlst.front()){
            tmp.push_front(*begin());
            pop_front();
        }else{
            tmp.push_front(*fwlst.begin());
            fwlst.pop_front();
        }
    }
    while(!empty()){
        tmp.push_front(*begin());
        pop_front();        
    }
    while(!fwlst.empty()){
        tmp.push_front(*fwlst.begin());
        fwlst.pop_front();
    }
    tmp.reverse();
    *this = tmp;
}
template<class T>
void Lforward_list<T>::sort(){
    unsigned long long size = 0;
    for(auto i = begin(); i!=end(); ++i, ++size);
    for(unsigned long long i = size; i > 1; --i){
        unsigned long long cnt = i-1;
        bool out = true;
        for(auto j = begin();cnt--; ++j){
            auto k = j; ++k;
            if(!(*j<*k)){
                out = false;
                T box = *j;
                *j = *k;
                *k = box;
            }
        }
        if(out){
            return;
        }
    }
}
template<class T>
void Lforward_list<T>::reverse(){
    if(!(first&&first->next)){//0或1个元素不需要
        return;
    }
    node<T>* oldFirstNode = first;
    node<T>* last = first;
    node<T>* now = first->next;
    node<T>* next = first->next->next;

    while(next){
        now->next = last;
        last = now;
        now = next;
        next = next->next;
    }
    now->next = last;
    //存头去尾
    first = now;
    oldFirstNode->next = nullptr;
}
template<class T>
void Lforward_list<T>::clear(){
    while(first){
        pop_front();
    }
}
template<class T>
void Lforward_list<T>::resize(unsigned long long n, const T& val){
    unsigned long long size = 0;
    auto isrt = begin();
    for(auto i = begin(); i!=end(); ++i){
        i==begin()?0:isrt++;
        size++;
        if(size==n){
            while(erase_after(i)!=end());
            return;
        }
    }
    insert_after(isrt, n-size, val);
}
template<class T>
typename Lforward_list<T>::iterator Lforward_list<T>::erase_after(iterator pos, Lforward_list<T>::iterator last){
    while(pos.node->next!=last.node){
        erase_after(pos);
    }
    return last;
}
template<class T>
typename Lforward_list<T>::iterator Lforward_list<T>::erase_after(Lforward_list<T>::iterator pos){
    if(pos._node->next){
        node<T>* del = pos._node->next;
        pos._node->next = pos._node->next->next;
        delete del;
    }
    return pos._node?++pos:pos;

}
template<class T>
typename Lforward_list<T>::iterator Lforward_list<T>::insert_after(Lforward_list<T>::iterator pos, Lforward_list<T>::iterator begin, Lforward_list<T>::iterator end){
    while(begin!=end){
        pos = insert_after(pos, *(begin++));
    }
    return ++pos;
}
template<class T>
typename Lforward_list<T>::iterator Lforward_list<T>::insert_after(Lforward_list<T>::iterator pos, unsigned long long n, const T& val){
    while(n--){
        pos = insert_after(pos, val);
    }
    return ++pos;
}
template<class T>
typename Lforward_list<T>::iterator Lforward_list<T>::insert_after(iterator pos, const T& val){
    node<T>* tmp = pos._node->next;
    pos._node->next = new node<T>(val,tmp);
    return ++pos;
}
template<class T>
inline void Lforward_list<T>::assign(unsigned long long n, const T& val){
        *this = Lforward_list(n, val);
}
template<class T>
inline void Lforward_list<T>::assign(Lforward_list<T>::iterator begin, Lforward_list<T>::iterator end){
    *this = Lforward_list(begin, end);
}
template<class T>
inline const T& Lforward_list<T>::front()const{
    return first->element;
} 
template<class T>
inline T& Lforward_list<T>::front(){
    return first->element;
} 
template<class T>
inline Lforward_list<T>& Lforward_list<T>::operator=(const Lforward_list<T>& rhs){
    Lforward_list<T> tmp(rhs);
    swap(tmp);
    return *this;
}
template<class T>
inline void Lforward_list<T>::swap(Lforward_list<T>& fwdlst){
    node<T>* box = first;
    first = fwdlst.first;
    fwdlst.first = box;
}
template<class T>
inline bool Lforward_list<T>::empty()const {
    return !first;
}
template<class T>
inline Lforward_list<T>::~Lforward_list(){
    clear();
}
template<class T>
inline void Lforward_list<T>::pop_front(){
    if(first){
        node<T>* delet = first;
        first = first->next;
        delete delet;
    }
}
template<class T>
Lforward_list<T>::Lforward_list(Lforward_list<T>::iterator begin, Lforward_list<T>::iterator end):first(nullptr){
    if(begin == end){return;}
    node<T>* getNode = begin.node;
    first = new node<T>(getNode->element); 
    node<T>* putNode = first;
    getNode = getNode->next;
    while(getNode!=end.node){
        putNode->next = new node<T>(getNode->element);
        getNode = getNode->next;
        putNode = putNode->next;
    }
}
template<class T>
Lforward_list<T>::Lforward_list(const Lforward_list& list):first(nullptr){
    if(!list.first){return;}
    node<T>* getNode = list.first;
    first = new node<T>(getNode->element); 
    node<T>* putNode = first;
    getNode = getNode->next;
    while(getNode){
        putNode->next = new node<T>(getNode->element);
        getNode = getNode->next;
        putNode = putNode->next;
    }
}
template<class T>
inline Lforward_list<T>::Lforward_list(unsigned long long n, const T& val):first(nullptr){
    while(n--){
        push_front(val);
    }
}
template<class T>
inline void Lforward_list<T>::push_front(const T& val){
    first = new node<T>(val, first);
}
template<class T>
inline Lforward_list<T>::Lforward_list():first(nullptr){}