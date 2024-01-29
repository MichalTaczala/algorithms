#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node
{
	public:
		Node *left;
		Node *right;
		int val;
};


class BstTree
{
	public:
		Node* root;
		BstTree()
		{
			root = NULL;
		};
		void inOrderSeq();
		void postOrderSeq();
		void preOrderSeq();
		int bstInsert(int _val); // inserts _val to bstTree; returns 1 is _val is added (which may happen only when _val is not in bstTree) and 0 otherwise
		int bstDelete(int _val); // deletes _val from bstTree; returns 1 if _val gets deleted and 0 otherwise
		int bstSearch(int _val); // returns 1 if _val is in the bstTree and 0 otherwise
		~BstTree();
	private:
		void inOrder(Node *);
		void postOrder(Node *);
		void preOrder(Node *);
		void deleteNode(Node*);
		int bstDeleteWithNoChildren(Node*, Node*);
		int bstDeleteWithOneChild(Node*, Node*);
		int bstDeleteWithTwoChildren(Node*, Node*);
};

BstTree::~BstTree()
{
	deleteNode(root);
}

void BstTree::deleteNode(Node* curr)
{
	if (curr!=NULL)
	{
		deleteNode(curr->left);
		deleteNode(curr->right);
		delete curr;
	}
}

int BstTree::bstInsert(int _val)
{
	if (bstSearch(_val)) return 0; //if _val is in the tree

	Node* curr = new Node();
	curr->val = _val;
	curr->left = NULL;
	curr->right = NULL;
	if (root == NULL)
	{
		root = curr;
		return 1;
	}
	else
	{
		Node * prev = NULL;
		Node* temp = root;
		bool leftChild = false;
		while( temp != NULL)
		{
			if (_val <= temp->val)
			{
				prev = temp;
				temp = temp->left;
				leftChild = true;
			}
			else
			{
				prev = temp;
				temp = temp->right;
				leftChild = false;
			}
		}

		if (leftChild)
			prev -> left = curr;
		else
			prev -> right = curr;
		return 1;
	}
}


int BstTree::bstSearch(int _val)
{
	Node* curr = root;
	while(curr != NULL)
	{
		if (curr-> val == _val)
			return 1;
		if (_val < curr->val)
			curr = curr -> left;
		else
			curr = curr -> right;
	}
	return 0;
}


int BstTree::bstDeleteWithNoChildren(Node* currNode, Node* prevNode)
{
	if (prevNode == NULL) {
		root = NULL;
		delete currNode;
		return 1;
	}
	if (prevNode->left == currNode) {
		prevNode->left = NULL;
	}
	else{
		prevNode->right = NULL;
	}
	delete currNode;
	return 1;
}

int BstTree::bstDeleteWithOneChild(Node* currNode, Node* prevNode)
{
	if (prevNode == NULL) {
		if (currNode->left != NULL) {
			root = currNode->left;
		}
		else{
			root = currNode->right;
		}
		delete currNode;
		return 1;
	}
	if (prevNode->left == currNode) {
		if (currNode->left != NULL) {
			prevNode->left = currNode->left;
		}
		else{
			prevNode->left = currNode->right;
		}
	}
	else{
		if (currNode->left != NULL) {
			prevNode->right = currNode->left;
		}
		else{
			prevNode->right = currNode->right;
		}
	}
	delete currNode;
	return 1;
}


int BstTree::bstDeleteWithTwoChildren(Node* currNode, Node* prevNode)
{
	if (prevNode == NULL) {
		Node* temp = currNode->right;
		Node* tempPrev = currNode;
		while (temp->left != NULL) {
			tempPrev = temp;
			temp = temp->left;
		}
		currNode->val = temp->val;
		if (tempPrev->left == temp) {
			tempPrev->left = temp->right;
		}
		else{
			tempPrev->right = temp->right;
		}
		delete temp;
		return 1;
	}
	if (prevNode->left == currNode) {
		Node* temp = currNode->right;
		Node* tempPrev = currNode;
		while (temp->left != NULL) {
			tempPrev = temp;
			temp = temp->left;
		}
		currNode->val = temp->val;
		if (tempPrev->left == temp) {
			tempPrev->left = temp->right;
		}
		else{
			tempPrev->right = temp->right;
		}
		delete temp;
		return 1;
	}
	else{
		Node* temp = currNode->right;
		Node* tempPrev = currNode;
		while (temp->left != NULL) {
			tempPrev = temp;
			temp = temp->left;
		}
		currNode->val = temp->val;
		if (tempPrev->left == temp) {
			tempPrev->left = temp->right;
		}
		else{
			tempPrev->right = temp->right;
		}
		delete temp;
		return 1;
	}
}

int BstTree::bstDelete(int _val)
{
	Node* previousNode = NULL;
	Node* currentNode = root;

	//find the value
	while (currentNode->val != _val){
		if (currentNode->val<_val){
			if (currentNode->right ==  NULL) return 0;
			previousNode = currentNode;
			currentNode = currentNode->right;
		}
		else if (currentNode->val >_val){
			if (currentNode->left == NULL) return 0;
			previousNode = currentNode;
			currentNode = currentNode->left;
		}
	}
	if (currentNode->left == NULL && currentNode->right == NULL) {
		return bstDeleteWithNoChildren(currentNode, previousNode);
	}
	else if (currentNode->left == NULL || currentNode->right == NULL) {
		return bstDeleteWithOneChild(currentNode, previousNode);
	}
	else{
		return bstDeleteWithTwoChildren(currentNode, previousNode);
	}



}

void BstTree::preOrderSeq()
{
	preOrder(root);
}

void BstTree::preOrder(Node * curr)
{
	cout << curr->val << " ";
	if (curr->left != NULL)
		preOrder(curr->left);
	if (curr->right != NULL)
		preOrder(curr->right);
}

void BstTree::inOrderSeq()
{
	inOrder(root);
}

void BstTree::inOrder(Node * curr)
{
	if (curr->left != NULL)
		inOrder(curr->left);
	cout << curr->val <<" ";
	if (curr->right != NULL)
		inOrder(curr->right);
}

void BstTree::postOrderSeq()
{
	postOrder(root);
}

void BstTree::postOrder(Node * curr)
{
	if (curr->left != NULL)
		postOrder(curr->left);
	if (curr->right != NULL)
		postOrder(curr->right);
	cout << curr->val <<" ";
}


int main()
{
	int z,n;
	string zstr,nstr;
	getline(cin, zstr);
	istringstream(zstr) >> z;
	while(z)
	{
		getline(cin, nstr);
		istringstream(nstr) >> n;
		BstTree bstTree = BstTree();
		for (int i=0; i<n;i++)
		{
			string line;
			getline(cin, line);
			string instr;
			int num;
			istringstream(line) >> instr >> num;
			if (instr == "INSERT")
				cout << bstTree.bstInsert(num) << "\n";
			else if (instr == "SEARCH")
				cout << bstTree.bstSearch(num)<<"\n";
            else if (instr == "DELETE")
                cout << bstTree.bstDelete(num)<<"\n";
			else if (instr == "PREORDER")
			{
				bstTree.preOrderSeq();
				cout <<"\n";
			}
			else if (instr == "INORDER")
			{
				bstTree.inOrderSeq();
				cout <<"\n";
			}
			else if (instr == "POSTORDER")
			{
				bstTree.postOrderSeq();
				cout <<"\n";
			}
			else if (instr == "DELETE")
			{
				bstTree.bstDelete(num);
				cout <<"\n";
			}
		}
		z--;
	}
}
