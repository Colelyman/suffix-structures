#ifndef TREE_H
#define TREE_H

#include <string.h>
#include <string>

class tree {
private:
	struct Node {
		Node* firstChild;
		Node* nextSibling;
		Node* link;
		char* begin; // the index of the reference where the substring begins
		int size; // the length of the substring in the node

		Node(char* begin, int size) {
			this->begin = begin;
			this->size = size;
			firstChild = NULL;
			nextSibling = NULL;
		}
	};
	char* reference;
	char delimiter;
	int length;
	Node* root; 
public:
	tree(string reference, string delimiter) {
		reference.append(delimiter);
		this->reference = (char*) reference.c_str();
		length = reference.length();
		root = new Node(this->reference, reference.length());
	}
	void deallocate(Node* n) {
		if(n == NULL)
			return;
		deallocate(n->firstChild);
		deallocate(n->nextSibling);
		delete n;
		return;
	}
	~tree() {
		deallocate(root);
	}
	void generate() {
		Node* t = new Node(reference, 0);
		root->firstChild = t;
		for(int i = 0; i < length; i++) { // i represents the character in the reference

		}
		return;
	}
	string index(int position) const {
		return "need to implement";
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
