#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (node->data > data) node->left = insert(node->left, data);
	else if (node->data < data) node->right = insert(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Node* root = NULL;
	int inp;
	while (cin >> inp) root = insert(root, inp);
	postorder(root);

	return 0;
}