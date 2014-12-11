#include "Node.h"

Node::Node(string compressed){
	this->compressed = compressed;
	next = NULL; 
}

void Node::print(){
	if (compressed == " "){
		cout << "black space" << endl;
	}
	else {
		cout << compressed << endl;
	}
}

Node::~Node(){
	delete next;
}

