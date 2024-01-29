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
		int bstSearch(int _val); // returns 1 if _val is in the bstTree and 0 otherwise
		~BstTree();
	private:
		void inOrder(Node *);
		void postOrder(Node *);
		void preOrder(Node *);
		void deleteNode(Node*);
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
		//cout << "Usuwanie noda z kluczem:" << curr ->val << "\n" ;
		delete curr;
	}
}

int BstTree::bstInsert(int _val)
{
	if (root == NULL) {
		root = new Node();
		root->val = _val;
		return 1;
	}
	Node* currentNode = root;
	
	while (true) {
		if (_val > currentNode->val){
			if (currentNode->right==NULL){
				currentNode->right = new Node();
				currentNode->right->val = _val;
				return 1;
			}
			currentNode = currentNode->right;
		}
		else if (_val < currentNode->val) {
			if (currentNode->left == NULL) 
			{
				currentNode->left = new Node();
				currentNode->left->val=_val;
				return 1;
			}
			currentNode = currentNode->left;
		}
		else{
			return 0;
		}
	}
}


int BstTree::bstSearch(int _val)
{
	if (root == NULL){
		return 0;
	}
	Node* currentNode = root;
	while (currentNode != NULL) {
		if (_val > currentNode->val){
			currentNode = currentNode->right;
		}
		else if (_val < currentNode->val) {
			currentNode = currentNode->left;
		}
		else if (currentNode == NULL){
			return 0;
		}
		else {
			return 1;
		}
	}
	return 0;
}



void BstTree::preOrderSeq()
{
	preOrder(root);
}

void BstTree::preOrder(Node * curr)
{
	/* write all the necessary code here */
	cout << curr->val << " ";
	if (curr->left != NULL) {
		preOrder(curr->left);
	
	}
	if (curr-> right != NULL) {
		preOrder(curr-> right);
	}
}

void BstTree::inOrderSeq()
{
	inOrder(root);
}

void BstTree::inOrder(Node * curr)
{
	/* write all the necessary code here */
	if (curr-> left != NULL) inOrder(curr->left);
	cout << curr->val << " ";
	if (curr->right != NULL ) inOrder(curr->right);
}

void BstTree::postOrderSeq()
{
	postOrder(root);
}

void BstTree::postOrder(Node * curr)
{
	if (curr-> left != NULL){
	postOrder(curr->left);
	}
	if (curr -> right != NULL){
	postOrder(curr->right);
	}
	cout << curr-> val << " ";
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
		}
		z--;
	}	
}




//preorder: root, and max to the left
//inorder: from minimum to maximum
//postorder: 