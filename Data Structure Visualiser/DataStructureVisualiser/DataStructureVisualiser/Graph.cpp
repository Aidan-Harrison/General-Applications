#include "Graph.h"

void Graph::Insert(const int key, node* n) {
}

node* Graph::Search(const int key, node* n, const char type) {
	/*
	if (n != nullptr) {
		if (key == n->data)
			return n;
		else if (key < n->data)
			return Search(key, n->lChild, type);
		else
			return Search(key, n->rChild, type);
	}
	*/

	// Standard Graph
	if (n != nullptr) {
		for (unsigned int i = 0; i < children.size(); i++)
			if (key == children[i].data)
				return &children[i]; // Check!
	}
	return nullptr; // Check!
}

// User
void Graph::Insert(const int key) {
	Insert(key, root);
}

void Graph::Search(const int key, const char type) { // SFML interface
	Search(key, root, type);
}

void Graph::DFS(node *n) {
	n->isVisited = true;
}

void Graph::Draw(sf::RenderWindow &window) { // Change
	for (unsigned int i = 0; i < children.size(); i++) {
		window.draw(childrenNodes[i]);
		window.draw(childrenText[i]);
	}
}