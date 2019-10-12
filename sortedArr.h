
#ifndef SORTEDARR_H
#define SORTEDARR_H
#include <iostream>

class sortedArr{
    private:
        unsigned int *arr;  //the dynamic array;
        int size;           //size of the array;
        int top;            //# of valid values in the array
        
        //following vars are used to keep track of sorting;
        int sorted; //whether the array is sorted or not
        int cIndex; //What is the index of the element that distrubs the sorted array
        int fixing; //if we are in the fixing mode, to avoid infinite recursion
        //Sorting specific func to keep the array in a sorted form at any invocation;
        inline void fix();
        void shiftRight(int s, int e);
        void shiftLeft(int s, int e);
        void moveRight(int index, unsigned int value);
        void moveLeft(int index, unsigned int value);

    public:
   
        explicit sortedArr(int size);   //int constructor
        sortedArr(const sortedArr& a);  //deep copy constructor
        sortedArr(sortedArr&& a);       //move constructor

        void setat(int index,unsigned int value);   //For setting an index to a value in a non const obj
        
        //Difference between following funcs is for sorting purposes
        inline unsigned int getat(int index);       //Getting a value at index in a non const obj
        inline unsigned int getat(int index) const; // Getting a value at index in a const obj

        inline int getSize() const;         //for getting the size of the array
        
        //Difference between following funcs is for sorting purposes
        inline int getTop();                //for getting the # of valid values in the array in a non const obj
        inline int getTop() const;          //for getting the # of valid values in the array in a const obj

        char* help(int error_code) const;   //for getting the meaning of an error code thrown by exceptions

        const sortedArr& operator=(const sortedArr& a);   //assignment operator
        const sortedArr& operator=(sortedArr&& a);        //move assignment operator
        
        //Difference between following funcs is for sorting purposes
        inline unsigned int& operator[](int index);     //returning a reference to the element at index in a non const obj
        inline unsigned int operator[](int index) const;//returning the value at index in a const obj
        
        //Difference between following funcs is for sorting purposes
        unsigned int operator==(sortedArr& a);          //eq operator between non-const objs
        unsigned int operator==(sortedArr& a) const;    //eq operator between const objs
        

        //Difference between following funcs is for sorting purposes
        friend std::ostream& operator<<(std::ostream&, sortedArr&);         //a friend func to output the elements of a non-const obj
        friend std::ostream& operator<<(std::ostream&, const sortedArr&);   //a friend func to output the elements of a const obj
        
        ~sortedArr();   //Obj Destructor
};
#include "sortedArr.cpp"
#endif