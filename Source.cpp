/**
	Purpose: Compresses a file 

	@author: Grace Liang
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Node.h"
#include "CompressionList.h"

using namespace std;

/**
	Compares two parts of a string to see if they are identical 

	@param str the string to be partitioned 
	@param beginPartition1 the beginning of the first partition of the string 
	@param endPartition1 the end of the first partition of the string
	@param beginPartition2 the start of the second partition of the string
	@param endPartition2 the end of the second partition of the string
*/
int compare(string * str, int beginPartition1, int endPartition1, int beginPartition2, int endPartition2);

int main(int argc, char *argv[]){

	string * data = NULL;
	string info; 
	ifstream line; 
	string temp;
	line.open("test.txt");
	if (line.is_open()){
		while (!line.eof()){
			getline(line, temp);
			info += temp; 
		}
	}
	else {
		cout << "The file you are attempting to open does not exist" << endl; 
	}
	
	line.close(); 

	data = &info; 

	CompressionList compressionList; 

	int beginPartition1 = 0;

	int endPartition1 = 0;

	int beginPartition2 = 1; 

	int endPartition2 = 1; 

	int result, next, next2, counter; 

	temp = (*data)[beginPartition1];
	compressionList.insert(temp);

	while (endPartition2 < (*data).size()){
		result = compare(data, beginPartition1, endPartition1, beginPartition2, endPartition2);
		int index = beginPartition2 - beginPartition1;
		counter = 1;
		while (result == 0 && counter != index){
			result = compare(data, beginPartition1 + counter, endPartition1 + counter, beginPartition2, endPartition2);
			counter++;
		}
		if (result == 0){
			temp = (*data)[beginPartition2];
			compressionList.insert(temp);
			beginPartition2++;
			endPartition2++;
		}
		else if (result == 1){
			next = endPartition1 + (counter-1);
			index= counter-1;
			next2 = endPartition2;
			counter = (beginPartition2-1) - beginPartition1;
			while (endPartition2 < (*data).size() && counter > 0){
				next++;
				next2++;
				result = compare(data, next, next, next2, next2);
				if (result == 0){
					next--;
					next2--;
					break; 
				}
				counter--;
			}

		
			beginPartition2 = next2 + 1; 
			endPartition2 = beginPartition2; 

			ostringstream convert, convert2;
			convert << beginPartition1 + index;
			temp = "(";
			temp += convert.str(); 
			temp += " , ";
			convert2 << next;
			temp += convert2.str();
			temp += ")";
			compressionList.insert(temp);
		}
	}

	compressionList.print();

	system("PAUSE");
}

int compare(string * str, int beginPartition1, int endPartition1, int beginPartition2, int endPartition2){
	if (beginPartition1 < 0 || endPartition1 < 0 || beginPartition2 < 0 || endPartition2 < 0){
		cout << "Invalid input." << endl; 
		return -1;
	}
	if (endPartition1 - beginPartition1 != endPartition2 - beginPartition2){
		return 0; 
	}
	for (int i = beginPartition1; i < endPartition1 + 1; i++){
		if ((*str)[i] != (*str)[beginPartition2]){
			return 0; 
		}
		beginPartition2++; 
	}
	return 1; 
}
