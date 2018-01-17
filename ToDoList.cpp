/*
*  This Class will manage a to-do list. 
*
*  Programmer: Matt Nicklas
*  Date: April 24, 2017
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/


#include <iostream>
#include "Date.h"
#include "ToDo.h"
#include "ToDoList.h"

// **********************************************
// Public
// **********************************************

//Default Constructor
ToDoList::ToDoList() { 
	size = 10; //Initialize size to 10
	count = 0; //Initialize count to 0
	whatIGotToDo = new ToDo[this->size]; //Allocate memory
	
}

//Destructor
ToDoList::~ToDoList() {
	delete [] whatIGotToDo; //Release the old memory
}

//This method returns the number of to-dos in the to-do list
int ToDoList::getToDoCount() const {
	return count;
}

//This method adds a ToDo object to the To-do List
void ToDoList::addToDo(ToDo addMe) { //If array is full, double its size
	if (count == size) {
		grow();
	}
	whatIGotToDo[count] = addMe; //Store ToDo passed into function
	count++; //Increment count 
}

//This method adds a ToDo to a specific location in the toDo list
void ToDoList::addToDo(ToDo addMe, int atThisLocation) {
	if (atThisLocation < 0) { //If negative postion, add to beginning of array
		makeAHoleHere(0); //Make a hole at position 0
		whatIGotToDo[0] = addMe; //Add to position 0
	} else if (atThisLocation >= count) { //If greater than count, add to end
		addToDo(addMe); //Call add method
	} else { //If neither, add at given location
		makeAHoleHere(atThisLocation); //Make a hole at given position
		whatIGotToDo[atThisLocation] = addMe; //Add ToDo to that position
	} 
}

//This method returns a todo from the location, or the default todo if the location is invalid
ToDo ToDoList::getToDo(int fromThisLocation) const {
	if (fromThisLocation >=0 && fromThisLocation < count) {
		return whatIGotToDo[fromThisLocation];
	} else {
		return ToDo();
	}
}

//This method removes a to-do from a specific location and returns it, or return the default to-do if the location is invalid
ToDo ToDoList::removeToDo(int fromThisLocation) {
	if (fromThisLocation >=0 && fromThisLocation < count) {
		ToDo result = whatIGotToDo[fromThisLocation]; //store to-do
		coverUpThisLocation(fromThisLocation); //cover up / delete to-do
		return result; //return to-do
	} else {
		return ToDo(); //return default to-do
	}
}

//This method prints the to-do list 
void ToDoList::printWhatIHaveToDo(std::ostream &out) const {
	out << "Here's what I've got to do: " << std::endl;
	for (int i = 0; i < count; i++) { //loop through entire array
		whatIGotToDo[i].printToDo(out);
	}
}



// **********************************************
// Private 
// **********************************************

//This method doubles the size of the array
void ToDoList::grow() {
	ToDo *temp = whatIGotToDo; //make a temporary pointer to the old array 
	whatIGotToDo = new ToDo[size*2]; //make a new larger array 	
	for (int i = 0; i < size; i++) { //copy the element from the old full array into the new larger array 
		whatIGotToDo[i] = temp[i]; 
	}
	delete [] temp; //release the old memory
	temp = nullptr; //null it out 
	size *= 2; //double the size 
}

//This method shifts all to-dos above a certain position up, to make room for a new one
void ToDoList::makeAHoleHere(int location) {
	if (count >= size) { //Increase size of array if necessary
		grow();
	}
	for (int i = count; i > location; i--) { //Shift ToDo's up one in array
		whatIGotToDo[i] = whatIGotToDo[i-1]; 
	}
	count++; //Increment count
}

//This method shifts all to-dos above a certain position down, to cover up a hole
void ToDoList::coverUpThisLocation(int location) {
	for (int i = location; i < (count - 1); i++) { //Shift down other ToDo's
		whatIGotToDo[i] = whatIGotToDo[i+1];
	}
	count--; //Decrement count
}