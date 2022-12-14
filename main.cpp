//
//  main.cpp
//  Assignment-3
//
//  Created by John Ayman on 09/12/2022.
//

#include <iostream>
#include "JYVector.hpp"
#include "JYVector.cpp"

using namespace std;

int main()
{
    // Initialize by specific capacity
    JYVector<double> a0(9);
    

    // Initialize by n items from array
    char arr[9] = { 'j', 'o', 'h', 'n', 'a' , 'y', 'm' ,'a','n'};
    JYVector<char> a1(arr, 9);

    //Copy constructor
    JYVector<char> a2(a1);
    
    // Copy assignment operator
    JYVector<char> a3;
    a3 = a1;
    
    //Move assignent operator
    char arr1[6] = { 'H', 'E', 'L', 'L', 'O' };
    JYVector<char> a4(arr1, 5);
    JYVector<char> a5;
    a5 = move(a4);
    
    
    //[] operator
    a5[2]='l';
    a5[10]='3';//out of range
    
    //push_back
    a0.push_back(1);
    a0.push_back(2);
    a5.push_back('M');
    
    //pop_back
    a2.pop_back();
    
    //erase
    a3.erase(2);
    a3.erase(100);//out of range
    a1.erase(2,4);
    
    //clear
    //a0.clear(); //WORKING
    
    //empty
    cout<<a0.empty()<<endl;
    
    
    
    a0.print();
    a1.print();
    a2.print();
    a3.print();
    a4.print();
    a5.print();
}


