#include "List.h"

// Single
void List::AddNode(node *n, int data) {
	node* newNode = new node(data);
	newNode->next = n->next;
	n->next = newNode;
}

void List::DelNode(node* n) { // Change
	n->next = n->next->next;
}

void List::Delete(node *n) {
	while (n != nullptr) { // For visualisation purposes
		n->data = 0;
		n = n->next;
	}
	delete this; // Check!
}

void List::Draw(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < list.size(); i++) {
		window.draw(list[i].rect);
		window.draw(list[i].text);
		list[i].xOffset += list[i].rect.getSize().x - 15.0f; // Check!
	}
}

void List::Interface(sf::RenderWindow& window) {
	operationText.setPosition(100.0f, 50.0f);
	std::cout << "Pick an operation:\n";
	std::cin >> choice;
	if (choice == 1) {
		operationText.setFont(font);
		operationText.setString("Push\nAdd a new item to the list");
		window.draw(operationText);
	}
	else if (choice == 2) {
		operationText.setFont(font);
		operationText.setString("Pop");
		window.draw(operationText);
	}
}

// Double
void dList::AddNode(dNode *n, int data) {
	dNode* newNode = new dNode(data);
	newNode->prev = n;
	newNode->next = n->next;
	n->next = newNode;
}

void dList::DelNode(dNode* n) {
	n->prev->next = n->next;
}

void dList::Delete(dNode *n) {
	while (n != nullptr) {
		n->data = 0;
		n = n->prev;
	}
	delete this; // Check!
}

void dList::Draw(sf::RenderWindow &window) {
	float x_Offset = 0.0f;
	for (unsigned int i = 0; i < list.size(); i++) {
		window.draw(list[i]->rect); // Set offset
		window.draw(list[i]->text);
		x_Offset += list[i]->rect.getSize().x + 15.0f;
	}
}

void dList::Interface(sf::RenderWindow& window) {
	std::cout << "Pick an operation:\n";
	std::cin >> choice;
	if (choice == 1) {
		operationText.setFont(font);
		operationText.setString("Push\nAdd a new item to the list");
		window.draw(operationText);
	}
	else if (choice == 2) {
		operationText.setFont(font);
		operationText.setString("Pop");
		window.draw(operationText);
	}
}