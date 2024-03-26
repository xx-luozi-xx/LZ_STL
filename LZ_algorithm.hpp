template<class T>
void swap(T& a, T&b){
    T tmp = a;
    a = b;
    b = tmp;
}
template <class T>
void nth_element(T *begin, T *right, T *end){//尚未支持迭代器
    int k = right - begin;
    int l = 0, r = end-begin-1;
    int i = 0, j = r;

    T mid = begin[(r+l)/2];

    while(1){
        while(begin[i]<mid)++i;
        while(begin[j]>mid)--j;

        if(i<=j){
            swap(begin[i], begin[j]);
            ++i,--j;
        }
        if(i>j){
            break;
        }
    }

    if(j<k&&k<i){
        return ;
    }else if(k<=j){
        return nth_element(begin, right, begin+j+1);
    }else{
        return nth_element(begin+i,right,end);
    }
}
template<class T>
void sort(T* begin, T* end){//[begin, end)//尚未支持迭代器
    T*a = begin;
    int l=0, i=0;
    int r=end-begin-1, j=end-begin-1;

    T mid = a[(l+r)/2];

    while(1){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;

        if(i<=j){//等于时也做一遍，使得控制区间错开，方便递归取区间和防止同一值递归死循环
            swap(a[i],a[j]);
            i++,j--;
        }
        if(i>j){
            break;
        }   
    }
    if(l<j) sort(begin, begin+j+1);
    if(i<r) sort(begin+i, end);
}