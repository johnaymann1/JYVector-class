#include "JYVector.hpp"

//
//  JYVector.cpp
//  Assignment-3
//
//  Created by John Ayman on 09/12/2022.
//
#include <iostream>
#include "JYVector.h"

using namespace std;


//Initialize by specific capacity
template <typename T>
JYVector<T>::JYVector (int s)
{
    used = 0;
    SIZE = s;
    arr = new T[s];
    for(int i = 0 ; i < SIZE; i++)
    {
        arr[i] = NULL;
    }
}



// Initialize by n items from array
template <typename T> JYVector<T>::JYVector(T a[], int s)
{
    arr = new T[s];
    SIZE = s;
    used = s;
    for (int i = 0; i < SIZE; i++)
        arr[i] = a[i];
}


// Initialize with a copy (copy constructor)
template <typename T>
JYVector<T>::JYVector (const JYVector& other)
{
//    cout<<"COPY CONSTRUCTOR"<<endl;
    arr = new T[other.SIZE];
    SIZE = other.SIZE;
    used = other.used;

    for(int i = 0; i<SIZE; i++)
    {
        arr[i] = (other.arr)[i];
    }
}


//destructor
template <typename T>
JYVector<T>::~JYVector<T>()
{
//    cout<<"DLETED"<<endl;
    delete arr;
}

//======================================================================================================================
//Copy assgnment
template <typename T>
JYVector<T>& JYVector<T>::operator=(const JYVector<T> &other)
{
//    cout<<"COPY ASSIGNMENT"<<endl;

    SIZE = other.SIZE;
    used = other.used;
    for(int i = 0; i<SIZE; i++)
    {
        arr[i] = (other.arr)[i];
    }
    return *this;
}





//move assignment
template <typename T>
JYVector<T>& JYVector<T>::operator=(JYVector<T>&& other)
{
//    SIZE = move(other.SIZE);
//    arr = move(other.arr);
//
//    other.SIZE = NULL;
//    other.arr = nullptr;
    if (this != &other)
    {
        if (arr != nullptr)
        {
            delete arr;
        }

        used = move(other.used);
        SIZE = move(other.SIZE);
        arr = move(other.arr);
        other.SIZE = 0;
        other.arr = nullptr;
    }


    return *this;
}

//======================================================================================================================

// Access operations
template <typename T>
T& JYVector<T>:: operator[](int index)
{
    try
        {
             if (index > SIZE)
             {
                 throw("OUT OF RANGE");
             }
        }
        catch(char const* error)
        {
            cout<<"Out of range !!"<<endl;
        }

        return arr[index];
}


//======================================================================================================================

// Modifying operations
template <typename T>
void JYVector<T>::push_back(T item)
{
    //INCREASING THE SIZE OF THE VECTOR IF NEEDED
    if (used == SIZE) //if the number of used is equal to the size of the vector
    {
        T* temp = new T[SIZE + 1]; //increase the size by 1

        //copying the items from the smaller vector to the bigger one
        for (int i = 0; i < SIZE; i++)
        {
            temp[i] = arr[i];
        }


        delete[] arr;
        arr = temp;
        SIZE = SIZE + 1;

    }

    arr[used] = item;
    used++;
}




template <typename T>
void JYVector<T>::pop_back()
{
    SIZE--;
    used--;
}





template <typename T>
void JYVector<T>::erase(int index)
{
    try
        {
             if (index > SIZE-1)
             {
                 throw("OUT OF RANGE");
             }
        }
        catch(char const* error)
        {
            cout<<"Out of range !!"<<endl;
        }

    arr[index]=NULL;
    for(int i = index; i <=SIZE; i++)
    {
        arr[i]=arr[i+1];
    }
    SIZE--;
    used--;
}




template <typename T>
void JYVector<T>::erase(int index1,int index2)
{
    for(int i = index1; i <=index2; i++)
    {
        erase(i);
    }
}



template <typename T>
void JYVector<T>::clear()
{
    for(int i = 0; i < SIZE; i++)
    {
        arr[i]= NULL;
    }

}

//======================================================================================================================

// Iterators

template <typename T>
T* begin() {

return arr;

}


template <typename T>
T* end() {

return &arr [SIZE];

}


//======================================================================================================================

// Comparison operations

template <typename T>
bool JYVector<T>::operator==(const JYVector<T>&other) {

if (other.size != SIZE) return 0;
for (int i=0; i<SIZE; i++) {

    if (arr [i] != (other.arr) [i]) return 0;

}
return 1;
}

template <typename T>
bool JYVector<T>::operator< (const JYVector<T>&other) {


for (int i=0; i<SIZE; i++) {

    if (arr [i] < (other.arr) [i]) return 1;
    else if (arr [i] > (other.arr) [i]) return 0;

}
}







//======================================================================================================================

// Capacity operations
template <typename T>
const int JYVector<T>::Size()
{
    return SIZE;
}

template <typename T>
const int JYVector<T>::capacity()
{
    return used;
}

template <typename T>
int JYVector<T>::resize(int n)
{
    if(n>SIZE)
    {
        int temp = SIZE;
        SIZE = n;
        for(int i = temp; i<SIZE; i++)
        {
            arr[i]=NULL;
        }

    }
    else
    {
        for(int i = n;i<SIZE;i++)
        {
            erase(i);
        }
    }
}

template <typename T>
bool JYVector<T>::empty()
{
    for(int i = 0; i<SIZE ;i++)
    {
        if (arr[i]==0)
        {
            continue;
        }
        else
        {
            return false;
        }

    }

    return true;
}

//======================================================================================================================
// operator <<
template <typename T>
     ostream& operator<<(ostream& out, JYVector<T> &vec)
{
    out<<"[";
    for (int i = 0; i < vec.SIZE; i++)
    {
        if (i != (vec.SIZE)-1 )
        {
             out<<(vec.arr)[i]<<',';
        }

          out<<(vec.arr)[i];
    }
    out<<"]";

    return out;
}



//print function
template <typename T> void JYVector<T>::print()
{
    cout<<"[";
        for (int i = 0; i < SIZE; i++)
        {
            if (i != SIZE-1 )
            {
                 cout<<arr[i]<<',';
            }
            else
            {
                cout<<arr[i];
            }


        }
        cout<<"]";
        cout<<endl;
}



