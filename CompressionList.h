/**
	Purpose: Link the compressed data together

	@author: Grace Liang
*/

#pragma once
#include "Node.h"
class CompressionList{
private: 
	Node * root; 
public:
	/**
		Constructor
	*/
	CompressionList();

	/**
		Takes a string and add it to the linked list.
		@param compresed 
	*/
	void insert(string compressed);

	/**
		Prints the contents in the linked list.
	*/
	void print(); 

	/**
		Destructor 
	*/
	~CompressionList();
};

