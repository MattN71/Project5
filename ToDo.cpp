/*
*  This Class will manage a to-do object
*
*  Programmer: Matt Nicklas
*  Date: April 24, 2017
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include <string>
#include <iostream>
#include "Date.h"
#include "ToDo.h"

//Default constructor, initializes all variables to default
ToDo::ToDo() {
	this->category = "";
	this->title = "";
	this->description = "";
	this->due = Date();
}

//Parameterized constructor, doesn't check any conditions
ToDo::ToDo(std::string category, std::string title, Date dueDate, std::string description) {
	this->category = category;
	this->title = title;
	this->description = description;
	this->due = dueDate;
}

//Sets category field
void ToDo::setCategory(std::string category) {
	this->category = category;
}

//Sets title field		
void ToDo::setTitle(std::string newTitle) {
	this->title = newTitle;
}

//Sets due date 
void ToDo::setDueDate(Date newDueDate) {
	this->due = newDueDate;
}

//Sets description field
void ToDo::setDescription(std::string newDescription) {
	this->description = newDescription;
}

//Returns category field
std::string ToDo::getCategory() const {
	return this->category;
}
	
//Returns title field	
std::string ToDo::getTitle() const {
	return this->title;
}

//Returns description field
std::string ToDo::getDescription() const {
	return this->description;
}

//returns due date object 
Date ToDo::getDueDate() const {
	return this->due;
}

//prints out to do object to ostream with formatting
void ToDo::printToDo(std::ostream &out) const {
	out << "Category:\t" << this->category << std::endl;
	out << "Title:\t" << this->title << std::endl;
	out << "Due Date:\t";
	this->due.printDate(out);
	out << "Description:\t" << this->description << std::endl;
}

