#include <iostream>
#include "List.h"

using namespace std;

List::List() : mySize(0), first(0) {}

List::List(const List& origList)  : mySize (origList.mySize) , first (0) {

	first = new Node(origList.first->data);
	NodePointer origPtr, myPtr ; //pointers to traverse ; 
	origPtr = origList.first -> next;
	myPtr = first;
	
	if (mySize == 0) {
		cerr << "Cannot create an object due to no size of original List"; exit(5);
	}

	while (origPtr != NULL) {
		
		myPtr -> next = new Node (origPtr -> data);
		origPtr = origPtr->next;
		myPtr = myPtr ->next;

	}
	

}
 
List:: ~List() { // one deletes and one traverse
	NodePointer ptr =first;
	while (ptr != NULL)
	{
		ptr = first->next;
		delete first;
		first = ptr;
	}
}

const List& List::operator=(const List & rightSide) {

	if (rightSide.mySize == 0) {
		this->~List(); //delete all elements of this object
		mySize = rightSide.mySize;
		first = 0;
		return *this;
	}

	if (this != &rightSide) {

		mySize = rightSide.mySize;
		first = new Node(rightSide.first->data);
		NodePointer origPtr, myPtr;
		origPtr = rightSide.first->next;
		myPtr = first;
		
		while (origPtr != NULL) {
			
			myPtr -> next = new Node(origPtr->data);
			origPtr = origPtr->next;
			myPtr = myPtr->next;

		}
	}

	return *this;

}

bool List :: empty() {return (mySize);}

void List::insert (ElementType dataVal, int index) {
	
	if (index > mySize || index < 0)
	{
		cerr << " Cannot insert : index out of boundary or undefined index : " << index << endl;
		return;
	}

	mySize++;
	 
	NodePointer newptr = new Node(dataVal) , origPtr = first;

	if (index != 0) {

		for (int i = 1; i < index; i++)  //traverse loop
			origPtr = origPtr->next;
		
		newptr->next = origPtr->next;
		origPtr->next=newptr ;
		
		
	}

	else {
		newptr->next = first;
		first = newptr;
	}

	
}

void List::erase(int index) {

	List :: NodePointer origptr = first , delptr; 

	if (index < 0 || index >= mySize)
	{
		cerr << " cannot delete element : index out of boundary or undefined index : " << index << endl;
		return;
	}
	mySize--; //understand 
	if (index == 0) {

		delete first;
		first = origptr;
	}

	else {

		for (int i = 1; i < index; i++) { //traverse loop to index-1
			
			origptr = origptr->next;

		}

		delptr = origptr->next;
		origptr ->next = delptr->next;
		delete delptr;

	}

	
	
}

int List::search(ElementType dataVal) {

	int idx=-1;
	NodePointer origPtr = first;

	for (int i = 0; i < mySize; i++) 
	{
		
		idx++;

		if (origPtr->data == dataVal) {
			return idx;
		}

		origPtr = origPtr->next;
			
	}
	return -1;
}

void List::display(ostream& out) const {

	NodePointer origPtr = first;

	while (origPtr != NULL) {
		out << origPtr->data << " " ;
		origPtr = origPtr->next;
	}
	
}

ostream& operator << (ostream& out, const List& aList) {
	
	aList.display(out);
	return out;
}

istream& operator >> (istream& in, List& aList) {
	int element_number;
	ElementType item;
	cout << "Enter number of elements : " << endl;

	in >> element_number;
	for (int i = 0; i < element_number; i++) {
		in >> item;
		aList.insert(item, i);
		
	}

	return in;

}


int List::nodeCount() { return mySize; }

//void List::reverse() {
//
//	NodePointer preptr , ptr , old_nxtptr;
//	preptr = first;
//	ptr = preptr->next;
//
//	while (old_nxtptr->next != NULL)
//	{
//		old_nxtptr = ptr->next;
//		ptr->next = preptr;
//		preptr = ptr;
//		ptr = old_nxtptr;
//		
//	}
//
//	first = old_nxtptr;
//	
//}

bool List::ascendingOrder() {

	NodePointer ptr = first;
	if (mySize <= 1)
		//empty or one element list
		return true;
	bool flag = true;
	int temp;
	do {
		temp = ptr->data;
		ptr = ptr->next;
		if (temp > (ptr->data)) {
			flag = false;	
		}
	} while (ptr -> next != 0 && flag);
	return flag;
}

	


