#define ARRAY_H
#ifdef ARRAY_H

#include "suffix.h"

class array: public suffix {
public:
	array();
	void generate();
	string print();
	bool boolFind(int start, int end, string query); // searches the suffix array and returns a bool
	int intFind(string query); // searches the suffix array and returns an int of the index of the match in the reference; returns -1 if not found
private:
	vector<int> sarray;
}

struct comp {
	comp(string reference) {
		this->reference = reference;
	}
	bool operator() (int i, int j) {
		return (reference.substr(i, i - reference.length()) < reference.substr(j, j - reference.length()));
	}

	string reference;
};

void array::generate() {
	for(unsigned int i = 0; i < reference.length(); i++)
		sarray.push_back(i);
	std::sort(sarray.begin(), sarray.end(), comp(reference));
}

string array::print() {
	string temp;
	for(unsigned int i = 0; i < reference.length(); i++) {
		if(i == 0) {
			temp.append(index(sarray[i]));
			continue;
		}
		temp.append("\n" + index(sarray[i]));
	}

	return temp;
}

bool suffix::boolFind(int start, int end, string query) { // end is intially equivalent to the size
	int mid = (end - start) / 2;
	if(query == index(sarray.at(mid))
		return true;
	else if(query > index(sarray.at(mid))
		boolFind(mid + 1, end, query);
	else
		boolFind(start, mid - 1, query);

	return false;
}
#endif
