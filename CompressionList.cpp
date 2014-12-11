#include "CompressionList.h"

CompressionList::CompressionList(){
	root = NULL;
}

void CompressionList::insert(string compressed){
	Node * it; 
	if (root == NULL){
		root = new Node(compressed);
	}
	else {
		it = root; 
		while (it->next != NULL){
			it=it->next; 
		}
		it->next = new Node(compressed);
	}
}

void CompressionList::print(){
	Node * it = root; 
	while (it != NULL){
		it->print();
		it = it->next;
	}
}

CompressionList::~CompressionList(){
	delete root; 
}
