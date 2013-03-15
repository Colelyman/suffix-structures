#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;
using std::sort;

class array {
private:
	vector<int> sarray;
	string reference;
	string delimiter;
	struct comp {
		comp(string reference) {
			this->reference = reference;
		}
		bool operator() (int i, int j) {
			return (reference.substr(i, i - reference.length()) < reference.substr(j, j - reference.length()));
		}	
		string reference;
	};

public:
	array(string reference, string delimiter) {
		this->reference = reference.append(delimiter);
		this->delimiter = delimiter;
	}
	void generate() {
		for(unsigned int i = 0; i < reference.length(); i++)
			sarray.push_back(i);
		sort(sarray.begin(), sarray.end(), comp(reference));
	}
	string index(int position) const {
		return reference.substr(position);
	}
	string print() {
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
	int intFind(string query) { // searches the suffix array and returns an int of the index of the match in the reference; returns -1 if not found
		return intFind(0, sarray.size() - 1, query);
	}
	int intFind(unsigned int start, unsigned int end, string query) {
		int mid = (end - start) / 2;
		if(query == index(sarray.at(mid)))
			return mid;
		else if(mid <= 1)
			return -1;
		else if(query > index(sarray.at(mid)))
			intFind(mid + 1, end, query);
		else if(query < index(sarray.at(mid)))
			intFind(start, mid - 1, query);
		return -1;
	}
	bool boolFind(string query) {
		if(intFind(0, sarray.size() - 1, query) >= 0)
			return true;
		else
			return false;
	}
};
#endif
