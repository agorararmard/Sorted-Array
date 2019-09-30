To run the test.cpp use the following commands:
    g++ test.cpp sortedArr.h -o out
    ./out

FOR TEST PUPRPOSES:

    You can un-comment std::cout in the sortedArr.cpp file to make sure of the execution of all functions;
    However, it was commented for purposes of convenience and because I didn't think it's use to have any couts inside the class code;


The terminal will include a walk through all class functions testing found in test.cpp;

The class source code is in sortedArr.cpp, sortedArr.h

This class is developed to keep a sorted array of size (size).
top is to keep to track of the number of valid, Non-Garbage, items in the array.

The sorting happens in insertion time with a complexity of O(n) making use of the fact that elements will be inputed one by one.
To solve the problem of value assignment using [] operator: fix() funct is used to fix the array if it's not sorted,where:
sorted: indicates whether the array is sorted or not;
cIndex: stores the index last accessed by the [] operator;
fixing: to notify the obj if it's fixing itself to avoid infinite recursion;

The class has a default explicit int constructor + a deep copy constructor; 
The class made use of move semantics with the move constructor + move assignment;

A const version of non-changing operators and functions was written to allow the use of const objs and this is shown in the tests.

Some functions were made inline to increase run-time efficiency.



