#include <stdio.h>
#include <iostream>
using namespace std;
typedef int ElementType;

class List
{
private:

    class Node {
    public:

        //------ Node DATA MEMBERS
        ElementType data;
        Node* next;

        
        Node() : next(0)
        {}

        
        Node(ElementType dataValue)
            : data(dataValue), next(0)
        {}
    }; 


    typedef Node* NodePointer;

public:
    
    List();
    
    List(const List& origList);
    
    ~List();
    
    const List& operator=(const List& rightSide);
   
    bool empty();
    
    void insert(ElementType dataVal, int index);
    
    void erase(int index);
    
    int search(ElementType dataVal);
    
    void display(ostream& out) const;
    
    int nodeCount();
   
    void reverse();

    bool ascendingOrder();

private:
    //------ DATA MEMBERS
    NodePointer first;
    int mySize;
}; //--- end of List class

ostream& operator<<(ostream& out, const List& aList);
istream& operator>>(istream& in, List& aList);

 