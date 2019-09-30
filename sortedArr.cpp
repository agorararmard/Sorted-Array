#include "sortedArr.h"

inline void sortedArr::fix()
{
    if(fixing)
        return;
    
    if(!sorted)
        {
            fixing = 1;
            setat(cIndex,arr[cIndex]);
            sorted = 1;
            fixing = 0;
        }
}

void sortedArr::shiftRight(int s, int e)
{
    for (int i = e; i>s; i--)
        i[arr] = i[arr-1];
}

void sortedArr::shiftLeft(int s, int e)
{
    for (int i = s; i<e; i++)
        i[arr] = i[arr+1];
}

void sortedArr::moveRight(int index, unsigned int value)
{
    for(int i = index+1; i < top; i++)
        if(i[arr] >= value)
            {
                shiftLeft(index,i-1);
                i[arr-1] = value;
                return;
            }
    shiftLeft(index,top-1);
    top[arr-1] = value;
}
    
void sortedArr::moveLeft(int index, unsigned int value)
{
    for(int i = index-1; i >= 0; i--)
        if(i[arr] <= value)
            {
                shiftRight(i+1,index);
                i[arr+1] = value;
                return;
            }
    shiftRight(0,index);
    0[arr] = value;
}

sortedArr::sortedArr(int size):size(size),top(0),sorted(1), fixing(0){
 
    //std::cout << "Running the int constructor\n";
    if(size <= 0)
        throw(101);
    
    arr = new (std::nothrow) unsigned int[size];
    if(arr == nullptr)
        throw(103);
}

sortedArr::sortedArr(const sortedArr& a):size(a.size),top(a.top),sorted(a.sorted),cIndex(a.cIndex), fixing(a.fixing){
    //std::cout << "Running the copy constructor\n";

    arr = new (std::nothrow) unsigned int[size];
    if(arr == nullptr)
        throw(103);

    for(int i = 0; i < size; i++)
        i[arr] = i[a.arr];
    
    fix();
}

sortedArr::sortedArr(sortedArr&& a):size(a.size),arr(a.arr),top(a.top),sorted(a.sorted),cIndex(a.cIndex),fixing(a.fixing){
    //std::cout << "Running the move constructor\n";
    fix();
    a.arr = nullptr;
    a.size = 0;
    a.top = 0;
}

void sortedArr::setat(int index,unsigned int value){

    //std::cout << "Running the setat funct\n";

    if(index >= size ||index <0)
        throw(102);
    
    fix();  
    
    if(index < top)
            if(index == top-1)
                if(value < arr[index-1])
                    moveLeft(index, value);
                else index[arr] = value;
            else if(index)
                if(value > arr[index-1])
                    moveRight(index, value);
                else if(value < arr[index-1])
                        moveLeft(index,value);
                else index[arr] = value;    
            else if(value > arr[index+1])
                    moveRight(index, value);
            else index[arr] = value;
    else
    {
            if(value < arr[top-1])
                moveLeft(top, value);
            else top[arr] = value;
                top++;               
    }
}

inline unsigned int sortedArr::getat(int index) const{
    //std::cout << "Running the getat const obj\n";

    if(index >= size || index <0)
      throw(102);

    return index[arr];
}

inline unsigned int sortedArr::getat(int index){
    //std::cout << "Running the getat non-const obj\n";
    
    if(index >= size || index <0)
      throw(102);
    
    fix();

    return index[arr];
}

inline int sortedArr::getSize() const{ 
    //std::cout << "Running the getSize funct\n";
    return size; 
}

inline int sortedArr::getTop(){
    //std::cout << "Running the getTop non-const obj\n";
    fix(); 
    return top; 
}

inline int sortedArr::getTop() const{
    //std::cout << "Running the getTop const obj\n"; 
    return top; 
}

sortedArr::~sortedArr(){
    //std::cout << "Running the Destructor\n";
    if(arr != nullptr)
        delete []arr;
}

sortedArr& sortedArr::operator=(const sortedArr& a){
    //std::cout << "Running the = assignment operator copy\n";
    if(&a == this)  //resolving self-assignment
        return *this;

    if(size == a.size)
    {
        size = a.size;
        delete[] arr;
        arr = new (std::nothrow) unsigned int[size];
    }

    top = a.top;
    sorted = a.sorted;
    fixing = a.fixing;
    cIndex = a.cIndex;
   
    if(arr == nullptr)
        throw(103);

    for(int i = 0; i < top; i++)
        i[arr] = i[a.arr];
    
    return *this;
}

sortedArr& sortedArr::operator=(sortedArr&& a){
    //std::cout << "Running the = move assignment operator\n";
    
    size = a.size;
    top = a.top;
    sorted = a.sorted;
    fixing = a.fixing;
    cIndex = a.cIndex;
    //unsigned int* tmp = arr;
    delete[] arr;
    
    arr = a.arr;
    
    a.arr = nullptr;
    a.size = 0;
    a.top = 0;
    
   
    return *this;
}

inline unsigned int& sortedArr::operator[](int index){
    //std::cout << "Running the [] operator non-const obj\n";
    
    if(index >= size || index <0)
        throw(102);
    fix();
    sorted = 0;
    cIndex = index;
  
    return arr[index];
}

inline unsigned int sortedArr::operator[](int index) const{
    //std::cout << "Running the [] operator const obj\n";
    return getat(index);
}

unsigned int sortedArr::operator==(sortedArr& a){
    //std::cout << "Running the == equality operator non-const obj\n";

    fix();
    a.fix();
    if(size != a.size)
        return 0;
    if(top!=a.top)
        return 0;
    for(unsigned int i =0; i < top;i++)
        if(i[arr] != i[a.arr])
            return 0;    
    return 1;
}

unsigned int sortedArr::operator==(sortedArr& a) const{
    //std::cout << "Running the == equality operator const obj\n";

    sortedArr *pnt2;
    sortedArr pnt1(*this);

    int del = 0;

    if(a.sorted)
            pnt2 = &a;
    else
    {
        del = 1;
        pnt2 = new sortedArr(a);
    }
    if(pnt1.size != pnt2->size)
        {
            if(del)
                delete pnt2;
            return 0;
        }
    if(pnt1.top!=pnt2->top)
        {
            if(del)
                delete pnt2;
            return 0;
        }

    for(unsigned int i =0; i < pnt1.top;i++)
        if(i[pnt1.arr] != i[pnt2->arr])
            {
                if(del)
                    delete pnt2;
                return 0; 
            }   

    if(del)
        delete pnt2;
    return 1;
}

std::ostream& operator<<(std::ostream& o ,sortedArr& a){
    //std::cout << "Running the << operator non-const obj\n";
    
    a.fix();
    
    for (unsigned int i =0; i < a.top-1;i++)
        o << a.arr[i] << ' ';
    o << a.arr[a.top-1];
    return o;
}


std::ostream& operator<<(std::ostream& o ,const sortedArr& a){ 
    //std::cout << "Running the << operator const obj\n";   
    
    for (unsigned int i =0; i < a.top-1;i++)
        o << a.arr[i] << ' ';
    o << a.arr[a.top-1];
    return o;
}

char* sortedArr::help(int error_code) const{
    switch(error_code)
    {
        case 101:
            return "Invalid Size";
        case 102:
            return "Index out of bounds";
        case 103:
            return "Memory allocation failure";
        default:
            return "Invalid error code";
    }
}