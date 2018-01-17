//Header file for ToDo class

#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <string>

class ToDo {
	private:
		std::string category; //Category of to-do
		std::string title; //Name of to-do object
		std::string description; //Description of object
		Date due; //Due date for to-do
	public:
		ToDo();
		ToDo(std::string category, std::string title, Date dueDate, std::string description);
		void setCategory(std::string category);
		void setTitle(std::string newTitle);
		void setDueDate(Date newDueDate);
		void setDescription(std::string newDescription);
		std::string getCategory() const;
		std::string getTitle() const;
		std::string getDescription() const;
		Date getDueDate() const;
		void printToDo(std::ostream &out) const;
};

#endif /* TODO_H */