#pragma once


typedef int ElementType;
class Tree
{
private:

    class Node {
    public:

        //------ Node DATA MEMBERS
        ElementType data;
        Node* next;

        //------ Node OPERATIONS
        //-- Default constrctor: initializes next member to Node()
        Node() : next(0)
        {}

        //-- Explicit-value constructor:  initializes data member to dataValue
        //--                             and next member to 0
        Node(ElementType dataValue)
            : data(dataValue), next(0)
        {}
    }; //--- end of Node class

    typedef Node* NodePointer;

public:


};

