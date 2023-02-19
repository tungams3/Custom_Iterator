#pragma once
using namespace std;
template<typename vector>
class VectorIterator
{
    public:
        typedef typename vector::ValueType_V ValueType;
        using PointerType=ValueType*;
        using RefereceType=ValueType&;

    public:
        VectorIterator(){}
        VectorIterator(PointerType ptr)
            : m_ptr(ptr){}
        VectorIterator& operator++(){
            m_ptr++;
            return *this;
        }
        VectorIterator operator++(int)
        {
            VectorIterator iterator=*this;
            ++(*this);
            return iterator;
        }
        VectorIterator& operator--(){
            m_ptr--;
            return *this;
        }
        VectorIterator operator--(int)
        {
            VectorIterator iterator=*this;
            --(*this);
            return iterator;
        }
        RefereceType operator[](int index)
        {
            return *(m_ptr+index);
        }
        PointerType operator->()
        {
            return m_ptr;
        }
        ValueType operator*()
        {
            return *m_ptr;
        }
        bool operator==(const VectorIterator& other)const
        {
            return m_ptr==other.m_ptr;
        }
         bool operator!=(const VectorIterator& other)const
        {
            return !(*this==other);
        }
    private:
    PointerType m_ptr;
};

template<typename T>
class Vector
{
public:
    using ValueType_V=T;
    using Iterator= VectorIterator<Vector<T>>; 
public:
    Vector()
    {
        ReAlloc(2);
    }
    void pushback(const T& value)
    {
        if(m_Size>=m_Capacity)
        {
            ReAlloc(m_Capacity+m_Capacity/2);
        }
        m_Data[m_Size]=value;
        m_Size++;
    }
    void pushback(T&& value)
    {
        if(m_Size>=m_Capacity)
        {
            ReAlloc(m_Capacity+m_Capacity/2);
        }
        m_Data[m_Size]=move(value);
        m_Size++;
    }
    void popback()
    {
        if (m_Size==0)
            return;
        m_Size--;
        m_Data[m_Size].~T();
    }
    void Clear()
    {
        for(int i=0;i<m_Size;i++)
        {
            m_Data[i].~T();
        }
        m_Size=0;
    }
    const T& operator[] (size_t index) const
    {
        if(index>=m_Size)
        {
            throw "Error";
        }
        return m_Data[index];
    }
    T& operator[](size_t index)
    {
        if(index>=m_Size)
        {
            throw "Error";
        }
        return m_Data[index];
    }
    size_t Size() const{return m_Size;}
    Iterator begin()
    {
        return Iterator(m_Data);
    }
    Iterator end()
    {
        return Iterator(m_Data+m_Size);
    }
private:
    void ReAlloc(size_t newCapacity)
    {
        //1. allocate a new block of memory 
        //2. copy
        //3. delete
        T *newBlock=new T[newCapacity];
        if(newCapacity<m_Size)
            m_Size=newCapacity; 

        for (size_t i=0;i<m_Size;i++)
        {
            newBlock[i]=move(m_Data[i]); 
        }
        delete[] m_Data;
        m_Data= newBlock;
        m_Capacity=newCapacity;
    }
private:
    T* m_Data=nullptr;
    
    size_t m_Size=0;
    size_t m_Capacity=0;
}; 