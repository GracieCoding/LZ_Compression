/**
	Purpose: Container for the data 
	
	@author: Grace Liang
*/

#pragma once

#include <iostream>
#include <string>

using namespace std; 

class Node{
private:
	string compressed; 
	Node * next; 
	friend class CompressionList;

public:
	/**
		A constructor that takes in a string.
		@param compressed A string to put into the node.
	*/
	Node(string compressed);

	/**
		Prints the contents in the Node.
	*/
	void print();

	/**
		Destructor
	*/
	~Node(); 
};

