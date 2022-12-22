//
//  JYVector.hpp
//  Assignment-3
//
//  Created by John Ayman on 09/12/2022.
//

#ifndef JYVector_hpp
#define JYVector_hpp

#include <iostream>
using namespace std;

template <typename T> class JYVector{
private:

    T* arr;     //pointer that points to the first element of the vector
    int SIZE;  //the size of the vector
    int used=0; //number of used ite ms in the vector


public:

    //Constructors and destructor
    JYVector (int s = 1);           // Initialize by specific capacity
    JYVector(T arr[], int s);      // Initialize by n items from array
    JYVector (const JYVector&);    // Initialize with a copy
    ~JYVector();                 // Delete allocated memory

//======================================================================================================================

    JYVector<T>& operator=(const JYVector<T>& other);   // Copy assignment
    JYVector<T>& operator=(JYVector<T>&& other); // Move assignment

//======================================================================================================================

    // Access operations
    T& operator[](int) ;

//======================================================================================================================

    // Modifying operations
    void push_back(T item);  // Add item to end of vec & return # of item  &  Increase capacity of needed
    void pop_back(); //remove the last element in the vector
    void erase(int index); // Remove item at index & Throw exception if invalid index
    void erase(int index1,int index2); // Remove items between index1 and index2
    void clear(); //Delete all vector element

//======================================================================================================================

    //-------------------------NOT DONE YET----------------------------

    // Iterators
    // Supports *, + and ++ operations at least
    // Can use: typedef T* iterator
    // Or u can use std::iterator so you can
    // apply STL algorithms on JYVector

    T*  begin();    // Return an iterator (T*)
    T*  end();    // Return an iterator (T*)


//======================================================================================================================
    //-------------------------NOT DONE YET----------------------------

    // Comparison operations
    bool operator==(const JYVector<T>&other); // Return true if they are equal
    bool operator< (const JYVector<T>&other); // Compares item by item return true if first different item in this is < in other

//======================================================================================================================

    // Capacity operations
    const int Size() ;     // Return current size of vec
    const int capacity(); // Return size of current allocated array
    int resize(int n);        // Relocate to bigger space
    bool empty();         // Return true if size is 0

//======================================================================================================================
    //-------------------------NOT DONE YET----------------------------
    friend ostream& operator<<(ostream& out, JYVector<T> const &vec);

    void print();
};

#endif /* JYVector_hpp */




