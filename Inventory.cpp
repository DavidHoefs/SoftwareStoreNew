#include "Inventory.h"


Node::Node() {
	this->Name = "";
	this->Version = "";
	this->Quantity = 0;
	this->Price = 0;
	right = 0;
	left = 0;
}



Node::Node(std::string name, std::string version, int quantity, double price) {
	this->Name = name;
	this->Version = version;
	this->Quantity = quantity;
	this->Price = price;
	right = 0;
	left = 0;
}
BST::BST() {
	this->root = nullptr;
}
void BST::insert(Node* insertNode) {

	if (!this->root) {
		this->root = insertNode;
	}
	else {
		Node*  temp;
		temp = this->root;
		while (true) {
			if (insertNode->Name < temp->Name) {
				if (temp->left != NULL) {
					temp = temp->left;
				}
				else {
					temp->left = insertNode;
					break;
				}
			}
			else if (insertNode->Name > temp->Name) {
				if (temp->right != NULL) {
					temp = temp->right;
				}
				else {
					temp->right = insertNode;
					break;
				}
			}
			else {}
			std::cout << "No Duplicates Allowed!" << std::endl;
		}

	}
}
void BST::inorderTraversal(Node* orderNode) {
	// if there are no values, return
	if (orderNode == NULL) {
		return;
	}
	// otherwise, recursively call inorderTraversal() function on left and right sides until you reach the end

	inorderTraversal(orderNode->left);
	std::cout << orderNode->Name << "\t" << orderNode->Version << "\t" << orderNode->Quantity << "\t" << orderNode->Price << std::endl;
	output << orderNode->Name << "\t\t" << orderNode->Version << "\t" << orderNode->Quantity << "\t" << orderNode->Price << std::endl;
	inorderTraversal(orderNode->right);


}
void BST::writeToFile() {
	///std::ofstream output;
	output.open("C:\\Users\\hoefs\\Desktop\\testsoftware.txt", std::ios_base::out | std::ios_base::app);
	if (output.is_open()) {
		
		PromptDataEntry();
		inorderTraversal(root);
		output.close();
	}
}
void BST::PromptDataEntry() {
	std::string name;
	std::string version;
	int quantity;
	double price;
	Node* node[4];

	std::cout << "Enter number of products to add to list\n";
	std::cin >> sizeOfList;
	if (output.eof()) {
		output << "Name:" << "\t\t" << "Ver." << "\t" << "Quan." << "\t" << "Price:\n";
		output << "-------------------------------------------------------------------------\n";
	}
	
	for (int i = 0; i < sizeOfList; i++) {


		std::cout << "Enter Name of Product: \n";
		std::cin >> name;
		std::cout << "Enter Version: \n";
		std::cin >> version;
		std::cout << "Enter Quantity: \n";
		std::cin >> quantity;
		std::cout << "Enter Price: \n";
		std::cin >> price;
		Node* newNode = new Node(name, version, quantity, price);
		insert(newNode);
		node[i] = newNode;

	}
	std::cout << "Node array test/////" << std::endl;
	for (int i = 0; i < sizeOfList; i++) {
		std::cout << node[i] << std::endl;
	}

}
Node* BST::getRoot() {
	return this->root;
}
void BST::readFile() {
	

	input.open("C:\\users\\hoefs\\Desktop\\testsoftware.txt", std::ios_base::in);
	input >> sizeOfList;
	int size = sizeOfList;
	std::string inputLine;
	
	for (int i = 0; i <= sizeOfList; i++) {
		std::getline(input, inputLine);
		std::cout << inputLine << std::endl;
		
		
	}
		
		
		
	
	
	input.close();
	
}