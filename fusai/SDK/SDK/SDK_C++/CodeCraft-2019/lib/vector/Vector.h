#pragma once
#include <iostream>
#define _MyDSAVECTOR_H_
//#include <time.h>

/*
* https://github.com/hungry0/DataStructureOfDeng/blob/master/src/vector/vector.h
*/
namespace MyDSA
{
    typedef int Rank;
    #define DEFAULT_CAPACITY 3000
    template <typename T> 
    class Vector {
        protected:
            Rank _size; int _capacity; T* _elem;
            void copyFrom(T const * A, Rank lo, Rank hi); // copy [lo,hi)
            void expand();
            Rank max ( Rank lo, Rank hi ); //选取最大元素

        public:
        //构造函数
            Vector( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 )
            { _elem = new T[_capacity = c]; for(_size = 0; _size < s; _elem[_size++] = v);  }
            Vector( T* A, int n) {copyFrom(A,0,n); }
            Vector( Vector<T> const&v) {copyFrom(v._elem,0,v._size); }

        //析构函数
            ~Vector() {delete [] _elem; }
        //Read only
            Rank size() const {return _size;}
            int disordered() const; //判断向量是否已排序
            Rank find ( T const& e, Rank lo, Rank hi ) const; //无序向量区间查找
            Rank find ( T const& e) const {return find(e,0,_size);} 

        //Write able
        T& operator[] (Rank r) const;
        Vector<T> & operator= (Vector<T> const& );
        Rank insert(Rank r, T const & e);
        Rank push_back(T const & e) {return insert(_size,e);};
        //void permute(Vector<T> & V );
        int erase(Rank lo, Rank hi);
        T erase(Rank r);
        T pop_back() { return erase(_size-1); };
        void sort ( Rank lo, Rank hi ); //对[lo, hi)排序
        void sort() { sort ( 0, _size ); } //整体排序
    };
}
#include "vector_im.h"
