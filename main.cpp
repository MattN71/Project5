#include "Date.h"
#include "ToDo.h"
#include "ToDoList.h"

#include <string>
#include <iostream>
#include <cctype>
#include <fstream>

using std::string;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;

Date readDate( istream &in );
ToDo readToDo( istream &in );
void eatWhiteSpace( istream &in );

int main()
{
	ToDoList stuffToDo = ToDoList();

	ifstream in("commands.txt");
	ofstream out("results.txt");
	
	string command;
	in >> command;
	while( !in.fail() )
	{
		//Breakpoint here
		out << "Command: " << command;
		if ( command == "add" )
		{
			ToDo doThis  = readToDo( in );
			doThis.printToDo(std::cout);
			stuffToDo.addToDo( doThis );
			out << endl;
		}
		else if ( command == "display" )
		{
			if ( in.peek() == '\n' )// || in.peek() == '\r' )
			{
				out << endl;
				stuffToDo.printWhatIHaveToDo( out );
			}
			else
			{
				int number;
				in >> number;
				out << " " << number;
				out << endl;
				ToDo showMe = stuffToDo.getToDo(number);
				if ( showMe.getTitle() != "" )
					showMe.printToDo(out);
				else
					out << "Invalid number: " << number << endl;
			}
			out << endl;
		}
		else if ( command == "save" )
		{
			string file;
			in >> file;
			out << " " << file << endl;
			ofstream out2(file);
			stuffToDo.printWhatIHaveToDo(out2);
			out2.close();
		}
		else if ( command == "load" )
		{
			string file;
			in >> file;
			out << " " << file << endl;
			ifstream in2(file);
			int count = 0;
			in2.ignore(5000, '\n' );
			ToDo doThis = readToDo( in2 );
			while( !in2.fail() )
			{
				count++;
				stuffToDo.addToDo( doThis );
				doThis = readToDo( in2 );
			}
			out << count << " To Dos Loaded" << endl;
			in2.close();
		}
		else if ( command == "remove" )
		{
			int number;
			in >> number;
			out << " " << number << endl;
			ToDo showMe = stuffToDo.removeToDo(number);
			if ( showMe.getTitle() != "" )
				showMe.printToDo(out);
			else
				out << "Invalid number: " << number << endl;
		}
		else
		{
			out << "unknown command: " << command << endl;
		}
		in >> command;
	}
}
void eatWhiteSpace( istream &in )
{
	while( isspace( in.peek() ) ) in.get();
}
ToDo readToDo( istream &in )
{	
	string junk;
	string category, title, description;
	Date due;
	in >> junk; //Category:
	eatWhiteSpace( in );
	getline( in, category );
	in >> junk;//Title:
	eatWhiteSpace( in );
	getline( in, title );
	in.ignore( 500, ':' );//Date
	eatWhiteSpace( in ) ;
	due = readDate( in );
	eatWhiteSpace( in ) ;
	in >> junk;//Description
	eatWhiteSpace( in );
	getline( in, description );
	ToDo doThis( category, title, due, description );
	return doThis;
}

Date readDate( istream &in )
{
	eatWhiteSpace( in );
	int month, day, year;
	char slash;
	in >> month >> slash >> day >> slash >> year;
	Date d( month, day, year );
	return d;
}
