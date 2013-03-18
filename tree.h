#ifndef TREE_H
#define TREE_H

#include <string.h>
#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::string;

class tree {
private:
	struct Node {
		Node* firstChild;
		Node* nextSibling;
		Node* link;
		int begin; // the index of the reference where the substring begins
		int size; // the length of the substring in the node

		Node(int begin, int size) {
			this->begin = begin;
			this->size = size;
			firstChild = NULL;
			nextSibling = NULL;
		}
	};
	string reference;
	char delimiter;
	Node* root; 
public:
	tree(string reference, string delimiter) {
		reference.append(delimiter);
		this->reference = reference;
		root = new Node(0, reference.length());
	}
	void deallocate(Node* n) {
		if(n == NULL) {
			delete n;
			return;
		}
		deallocate(n->nextSibling);
		deallocate(n->firstChild);
		delete n;
		return;
	}
	~tree() {
		deallocate(root->firstChild);
		delete root;
	}
	void changeSize(Node* n) {
		if(n == NULL)
			return;
		changeSize(n->nextSibling);
		changeSize(n->firstChild);
		n->size++;
		return;
	}
	void generate() {
		Node* t;
		Node* previous = root;
		for(unsigned int i = 0; i < reference.length(); i++) { // i represents the character in the reference
			t = new Node(i, 1);
			if(previous->firstChild == NULL)
				previous->firstChild = t;
			else
				previous->nextSibling = t;
			changeSize(previous);
			previous = t;
		}
		return;
	}
	string index(Node* n) const {
		return reference.substr(n->begin, n->size);
	}
	string traverse(Node* n) const {
		string temp;
		temp.append(index(n) + "->"); // get the item at the node
		if(n->nextSibling != NULL)
			temp.append(traverse(n->nextSibling) + "; \n");
		if(n->firstChild != NULL)
			temp.append(traverse(n->firstChild) + "; \n");
		return temp;
	}
	void print() const {
		cout << "digraph Suffix_Tree {" << endl;
		cout << traverse(root->firstChild);
		cout << "}" << endl;
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
