#include <iostream>
#include "sortedArr.h"
using namespace std;
void testSet_Get(sortedArr&);
sortedArr testConstructors(sortedArr&);
sortedArr coppy(sortedArr&);
void testOperators(sortedArr&,sortedArr&);
void testConst(sortedArr&);

    
    
int main()
{
    int inc = 0;    //for keeping track of the test outputs:
    cout << ++inc << ": ";
    cout << "Int Constructor test with exception handling: \n";
    
    try{
        sortedArr A(15);

        cout << ++inc << ": ";
        cout << "Testing setat and getat with exception handling: \n";
        testSet_Get(A);
        cout << ++inc << ": ";
        cout << "Testing Move Constructor and Copy Constructor: \n";
        try{   
            sortedArr B = testConstructors(A);
            cout << "\n\n\nConstructors tested: copy constructor inside the function, move constructor was tested in the return and the initialzation of B...\n\n\n";
            
            cout << ++inc << ": ";
            cout << "Testing Operators <<,=, ==, []: \n";   
            cout << B << endl;
            testOperators(A,B);
            
            cout << ++inc << ": ";
            cout << "Testing Operators <<, ==, [] and getat on const objs: \n";   
            testConst(A);

            cout << "\n\n\n Testing ALL class functions, constructors, operators done\n\n\nGet Ready because the Destructor is about to run now!\n";
        }catch(int& err){
            cout << "Exception caught: " << A.help(err) << endl;
        }
    } catch(int& err)
    {
        cout << "Exception caught construction failed\n";
    }
    
}


void testSet_Get(sortedArr& A)
{
    cout << "inserting elements...\n";
    try{
        A.setat(0,1);
        A.setat(1,3);
        A.setat(2,5);
        A.setat(6,7);
        A.setat(4,10);
        A.setat(5,25);
        cout << "getting insterted elements in order...\n";
        for (int i =0; i< A.getSize(); i++)
        {
            cout<<A.getat(i) << " ";
        }
        cout << endl;
        cout << "inserting a large element 8 at index 1...\n";
        A.setat(1,8);
        cout << "getting elements in order...\n";
        for (int i =0; i< A.getSize(); i++)
        {
            cout<<A.getat(i) << " ";
        }
        cout << endl;

        cout << "inserting a small element 5 at index 4...\n";
        A.setat(4,5);
        cout << "getting elements in order...\n";
        for (int i =0; i< A.getSize(); i++)
        {
            cout<<A.getat(i) << " ";
        }
        cout << endl;
        
        cout << "inserting a large element away from the ordered elements but still in the bounds of the array, 101 at index 10\n";
        
        A.setat(10, 101);

        cout << "getting elements in order...\n";
        for (int i =0; i< A.getSize(); i++)
        {
            cout<<A.getat(i) << " ";
        }
        cout << endl;

        cout << "inserting a Small element away from the ordered elements but still in the bounds of the array, 6 at index 10...\n";
        A.setat(10,6);    

        cout << "getting elements in order...\n";
        for (int i =0; i< A.getSize(); i++)
        {
            cout<<A.getat(i) << " ";
        }
        cout << endl;
    }catch(int& err)
    {
        cout << "Exception caught: " << A.help(err) << endl;
    }

    cout << "Show casing an exception error for index out of bounds: inserting value 5 at index 50...\n";
    try{
        A.setat(50, 5);
    }catch(int& err)
    {
        cout << "Exception caught: " << A.help(err) << endl;
    }
    cout << "Show casing an exception error for index out of bounds: inserting value 5 at index -10...\n";
    try{
        A.setat(-10, 5);
    }catch(int& err)
    {
        cout << "Exception caught: " << A.help(err) << endl;
    }

    cout << "\n\n\nTest completed: setat(),getat(),getSize(), and the array is kept sorted at all times\n\n\n";
}

sortedArr testConstructors(sortedArr& A)
{
    cout << "Show casing exception handling in the int constructor by inserting a negative Size...\n";
    try{
        sortedArr C(-1);
    }catch(int& err)
    {
        cout << "Exception caught: " << A.help(err) << endl;
    }

    cout << "Testing the copy constructor...\n";   
    try{
        sortedArr B(A);
        cout << "Getting items copied...\n";
        for (int i =0; i< B.getSize(); i++)
        {
            cout<<B.getat(i) << " ";
        }
        cout << endl;
        return B;
    }catch(int& err)
    {
        cout << "Exception caught: " << A.help(err) << endl;
        return sortedArr(1);
    }
}


sortedArr coppy(sortedArr& a)
{
    sortedArr tmp = a; 
    return tmp;
}

void testOperators(sortedArr& A, sortedArr& B)
{
    cout << "Changing some of the contents of B using the [] operator...\n";
    B[1] = 17;
    B[2] = 10;
    B[8] = 27;
    
    cout << "Testing << operator...\n";
    cout << A << " ** " <<B << endl;
    
    cout << "Testing the == operator, by evaluating A == B...\n";
    cout << (A==B) << endl;

    cout << "Testing the = operator, by making B = A...\n";
    B = A;

    cout << "Testing the == operator, by evaluating A == B...\n";
    cout << (A==B) << endl;



    cout << "Changing some of the contents of B using the [] operator...\n";
    B[1] = 17;
    B[2] = 10;
    B[14] = 27;

    cout << "Testing the move assignment = operator, by making B = coppy(A) where coppy is a function that copies the values of A into tmp and then returns tmp...\n";
    B = coppy(A);
    
    cout << "Printing contents of B using the [] operator...\n";
    for(int i =0; i < B.getTop(); i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << B << endl;
    cout << A << endl;
    cout << "Show casing exception handling in index [] operator by going out of bounds...\n";
    try{
        cout << A[50];
    }catch(int& err)
    {
        cout << "Exception caught: " << A.help(err) << endl;
    }


    cout << "\n\n\nOperator testing complete: <<, = copy, = move, [] for getting, [] for setting, ==\n\n\n";
}



void testConst(sortedArr& A)
{
    for (int i =0; i< A.getSize();i++)
    {
        cout << A.getat(i) << " ";
    }
    cout << "Creating a constant object that is a copy of A...\n";
    const sortedArr C(A);
    cout << "Testing the << operator on C...\n";
    cout << C << endl;
    
    cout << endl;
    cout << "Testing the == operator on C == A...\n";
    cout << (C == A) << endl;
    cout << "Changing one of the contents of A...\n";
    A[1] = 10;
    cout << "Testing the == operator on C == A...\n";
    cout << (C == A) << endl;
    cout << "getting the content of C by using [] operator and the getTop function...\n";
    for (int i =0; i< C.getTop();i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
    
    cout << "getting the content of C by using getat function and the getSize function...\n";
    for (int i =0; i< C.getSize();i++)
    {
        cout << C.getat(i) << " ";
    }
    cout << endl;

    cout << "Copying the content of C into a non-const obj D...\n";
    sortedArr D(C);
    cout << "printing the content of D...\n";
    cout << D << endl;
    cout << "using the = operator on A = C...\n";
    A = C;
    cout << "printing the content of A...\n";
    cout << A << endl;
    
    cout << "\n\n\nTesting Constant objects operators and functions done...\n\n\n";
}