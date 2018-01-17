//Header file for ToDoList Class

#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>

class ToDoList {
	private:
		int count; //Number of items in array
		int size; //Size of array
		ToDo* whatIGotToDo; //Pointer to array
		
		void grow(); 
		void makeAHoleHere(int location);
		void coverUpThisLocation(int location);
	
	public:
		ToDoList();
		~ToDoList();
		int getToDoCount() const;
		void addToDo (ToDo addMe);
		void addToDo (ToDo addMe, int atThisLocation);
		ToDo getToDo(int fromThisLocation) const;
		ToDo removeToDo(int fromThisLocation);
		void printWhatIHaveToDo(std::ostream &out) const;
};

#endif /* TODOLIST_H */