#ifndef TREE_H
#define TREE_H

#include <string.h>
#include <string>
#include <iostream>
#include <sstream>

using std::endl;
using std::cout;
using std::string;
using std::stringstream;

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
		struct triple {
			Node* node = root;
			char edge = '\0'; // the first character of an edge is the unique id represented here
			int length = 0; // represents how many characters in the specified edge
		} active;
		int remainder = 1;
		int pos = 0;
		while(remainder > 0 && (unsigned int) pos < reference.length()) { // remainder is the number of explicit suffixes that need to be added to the tree 
			if(active.length == 0) 
				active.edge = reference[pos];
			if(/*the current character is not a child of active node*/) { // in other words, if there is a new character in the string
				/*create new child of active.node;*/ 
				/*add suffix link;*/
			}
			else { // just extend the tree, increase the length of each terminating leaf node

			}
			remainder--;
			if(active.node == root && active.length > 0) {
				active.length--;
				active.edge = reference[pos - remainder + 1];
			}
			else {

			}
			changeSize(active.node); // only add new character to terminating leaf nodes, not internal nodes
			pos++;
		}
	}
	string index(Node* n) const {
		return reference.substr(n->begin, n->size);
	}

	string traverse(Node* n) const {
		stringstream s;
		Node* t = n->firstChild;

		if(t != NULL) {
			while(t != NULL) {
				if(n == root) 
					cout << "root->\"" << index(t) << "\";" << endl;
				else
					cout << "\"" << index(n) << "\"->\"" << index(t) << "\";" << endl;
				traverse(t);
				t = t->nextSibling;
			}
		}
		return s.str();
	}
	void print() const {
		cout << "digraph Suffix_Tree {" << endl;
		cout << traverse(root);
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
