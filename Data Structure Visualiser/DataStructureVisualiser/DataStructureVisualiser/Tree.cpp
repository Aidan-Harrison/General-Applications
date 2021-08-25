#include "Tree.h"

void Tree::DFS(tNode *n) {
	n->isVisited = true;
	n->circle.setFillColor(sf::Color::Red);
	if (n->lChild != nullptr && !n->lChild->isVisited)
		DFS(n->lChild);
	if (n->rChild != nullptr && !n->rChild->isVisited)
		DFS(n->rChild);
}

void Tree::Draw(sf::RenderWindow& window) {
	window.draw(root->circle);
	if(root->lChild != nullptr)
		window.draw(root->lChild->circle);
	if(root->rChild != nullptr)
		window.draw(root->rChild->circle);
}