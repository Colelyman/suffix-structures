#define ARRAY_H
#ifdef ARRAY_H

#include "suffix.h"

class array: public suffix {
public:
	array();
	void generate();
	string get();
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

string array::get() {
	string temp;
	for(unsigned int i = 0; i < reference.length(); i++) {
		if(i == 0) {
			temp.append(index(sarray[i]));
			continue;
		}
		temp.append("\n" + index(sarray[i]));
	}

	return temp;
};
#endif
