#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>
#include <sstream>
#include <map>

using std::endl;
using std::cout;
using std::string;
using std::stringstream;
using std::map;

class tree {
private:
	string reference;
	char delimiter;
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

		bool Explicit() {
			if(this->firstChild != NULL && this->firstChild->nextSibling != NULL)
				return true;
			return false;
		}
	};
	Node* root; 
	struct triple {
		Node* node;
		int edge; // the first character of an edge is the unique id represented here
		int length; // represents how many characters in the specified edge
	};
	triple active;
public:
	tree(string reference, string delimiter) {
		reference.append(delimiter);
		this->reference = reference;
		root = new Node(0, 0);
		active.node = root;
		active.edge = 0;
		active.length = 0;
	}
	void deleteSubtree(Node* n) {
		if(n == NULL) {
			delete n;
			return;
		}
		deleteSubtree(n->nextSibling);
		deleteSubtree(n->firstChild);
		delete n;
		return;
	}
	~tree() {
		deleteSubtree(root->firstChild);
		delete root;
	}
	void canon() {

	}
	Node* addChild(Node* parent, Node* child) {
		Node* n;
		if(parent->firstChild == NULL) {
			cout << "parent->firstChild == NULL" << endl;
			parent->firstChild = child;
			n = parent->firstChild;
		}
		else {
			cout << "parent->firstChild != NULL" << endl;
			Node* temp = parent->firstChild;
			while(temp->nextSibling != NULL)
				temp = temp->nextSibling;
			temp->nextSibling = child; 
			n = temp->nextSibling;
		}
		cout << "Exit addChild" << endl;
		return n;
	}
	Node* split(Node* parent) {
		Node* n = new Node(parent->begin + 1, parent->size - 1); // new
		cout << "After new in split" << endl;
		return addChild(parent, n);
	}
	Node* findEdge(Node* n, int edge) {
		if(n->firstChild == NULL)
			return n;
		if(n->firstChild->begin == edge)
			return n->firstChild;
		n = n->firstChild->nextSibling;
		while(n->begin != edge ) {
			if(n == NULL)
				return NULL;
			n = n->nextSibling;
		}
		return n;
	}
	void addPrefix(int index) {
		cout << "addPrefix for index: " << index << " which is: " << reference[index] << endl;
		Node* n;
		Node* parent = active.node;
		Node* last = NULL;
		while(1) {
			cout << "Enter while(1)" << endl;
			if(active.node->Explicit()) { // check to see if this is an explicit node (a node with no children)
				cout << "active.node->Explicit() == true" << endl;
				n = findEdge(active.node, index); // check to see if the edge exists
				if(n != NULL)
					break; // the edge exists at this node so no new nodes need to be created
			}
			else { // the active.edge is an implicit node, meaning that a node may need to be split
				cout << "active.node->Explicit() == false" << endl;
				n = findEdge(active.node, active.edge);
				cout << "After findEdge()" << endl;
				cout << "n->begin: " << n->begin << " n->size: " << n->size << endl;
				if(reference[index] == reference[n->begin + n->size /* + 1*/])
					break;
				cout << "After if" << endl;
				parent = split(n);
				cout << "After split(n)" << endl;
			}

			Node* new_n = new Node(index, 1); // no matching edge in the tree so create a new node
			addChild(parent, new_n);
			if(last != NULL)
				last->link = parent;
			last = parent;

			if(active.node == root)
				active.edge++; 
			else
				active.node =  active.node->link;
			canon();
		}
		if(last != NULL)
			last->link = parent;
		active.edge++;
		canon();
	}
	void generate() {
		for(unsigned int i = 0; i < reference.length(); i++)
			addPrefix(i);
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
