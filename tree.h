#ifndef TREE_H
#define TREE_H

#include <string>

class tree {
private:
	struct Node {
		Node* firstChild;
		Node* nextSibling;
		int begin; // the index of the reference where the substring begins
		int end; // the index of the reference where the substring ends

		Node(int begin, int end) {
			this->begin = begin;
			this->end = end;
			firstChild = NULL;
			nextSiblint = NULL;
		}
	};
	string reference;
	string delimiter;
public:
	tree(string reference, string delimiter) {
		this->reference = reference.append(delimiter);
		this->delimiter = delimiter;
	}
	void generate() {

		return;
	}
	string index(int position) const {
		return reference.substr(position);
	}
	string print() const {
		string temp;


		return temp;
	}
	int intFind(string query) const {
		return 0;
	}
	bool boolFind(string query) const {
		if(intFind(query) >= 0)
			return true;
		else
			return false;
	}
};
#endif
