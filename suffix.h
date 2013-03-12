#define SUFFIX_H
#ifdef SUFFIX_H

/* 
===== Suffix Structure Implementation ===== 
by Cole Lyman, Brigham Young University Computational Science Lab
==== Purpose ====
The purpose of this implementation is to create an efficient implementation
of various suffix structures (suffix array, suffix tree, and suffix cacts).
==== Input ====
To generate the suffix structure, a reference string is the input.
A query string will need to be provided as well.
==== Output ====
The output will be an index of where the query string is located in the reference.
If the query is not present in the reference, a -1 will be returned. 
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;
using std::cout;
using std::endl;

class suffix {
public:
	suffix();
	suffix(string reference, string delimiter);
	string index(int position) const;

	virtual void generate();
	virtual string print();
	virtual bool boolFind(string query);
	virtual int intFind(string query);
protected:
	string reference;
	string delimiter;
};

suffix::suffix(string reference, string delimiter) {
/*	try {
		for(unsigned int i = 0; i < reference.length(); i++) {
			if(reference[i] == delimiter[0])
				throw "Delimiter is in the reference string. Choose a different delimiter or remove the delimiter from the reference string";
		}
	}
	catch(...) {
		
	}*/
	this->reference = reference.append(delimiter);
}

string suffix::index(int position) const {
	return reference.substr(position);
}
#endif
