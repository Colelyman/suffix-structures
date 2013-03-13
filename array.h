#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;
using std::sort;

class array {
public:
	array(string ref, string del);
	void generate();
	string index(int position) const;
	string print();
	bool boolFind(string query);
	bool boolFind(unsigned int start, unsigned int end, string query); // searches the suffix array and returns a bool
	int intFind(string query); // searches the suffix array and returns an int of the index of the match in the reference; returns -1 if not found
private:
	vector<int> sarray;
	string reference;
	string delimiter;
};

array::array(string ref, string del) {
	this->reference = ref.append(del);
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

string array::index(int position) const {
	return reference.substr(position);
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
	temp.append("\n");

	return temp;
}

bool array::boolFind(string query) {
	return boolFind(0, sarray.size() - 1, query);
}

bool array::boolFind(unsigned int start, unsigned int end, string query) { // end is intially equivalent to the size
	int mid = (end - start) / 2;
	if(query == index(sarray.at(mid)))
		return true;
	else if(mid <= 1)
		return false;
	else if(query > index(sarray.at(mid)))
		boolFind(mid + 1, end, query);
	else if(query < index(sarray.at(mid)))
		boolFind(start, mid - 1, query);
	else
		return false;
}
#endif
