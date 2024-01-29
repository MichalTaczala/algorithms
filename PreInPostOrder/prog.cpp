#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

class Node
{
	public:
		Node *left;
		Node *right;
		int val;
};


class BinaryTree
{
	public:
		Node* root;
		BinaryTree()
		{
			root = NULL;
		};
		BinaryTree(string fO, string sO, vector<int>* firstOrder, vector<int>* secondOrder, int n);
		void inOrderSeq();	
		void postOrderSeq();
		void preOrderSeq();
		~BinaryTree();
	private:
		void inOrder(Node *);
		void postOrder(Node *);
		void preOrder(Node *);
		void deleteNode(Node*);
		Node* prein(vector<int>* firstOrder, vector<int>* secondOrder, int preOrderL, int inOrderL, int size);
		Node* inpost(vector<int>* firstOrder, vector<int>* secondOrder, int inOrderL, int postOrderL, int size);
		Node* prepost(vector<int>* preOrder, vector<int>* postOrder, int preOrderL, int postOrderL, int size);
};

BinaryTree::~BinaryTree()
{
	deleteNode(root);
}

void BinaryTree::deleteNode(Node* curr)
{
	if (curr!=NULL)
	{
		deleteNode(curr->left);
		deleteNode(curr->right);
		//cout << "Usuwanie noda z kluczem:" << curr ->val << "\n" ;
		delete curr;
	}
}


BinaryTree::BinaryTree(string firstOrderName, string secondOrderName, vector<int>* firstOrder, vector<int>* secondOrder, int n)
{
	if ((firstOrderName=="PREORDER") && (secondOrderName=="INORDER"))
	{
		root = prein(firstOrder, secondOrder,0,0,n);
		return;
	}
	if ((firstOrderName=="INORDER") && (secondOrderName=="POSTORDER"))
	{
		root = inpost(firstOrder, secondOrder,0,0,n);
		return;
	}
	if ((firstOrderName=="PREORDER") && (secondOrderName=="POSTORDER"))
	{
		root = prepost(firstOrder, secondOrder,0,0,n);
		return;
	}
}

Node* BinaryTree::prepost(vector<int>* preOrder, vector<int>* postOrder, int preOrderL, int postOrderL, int size)
{
	Node* root = new Node();
	root->val = preOrder->at(preOrderL);
	if (root->val==0){
		return NULL;
	}
	int left_child_val = preOrder->at(preOrderL+1); 

	int index;
	for (int i=0;i<size; i++){
		if (postOrder->at(i+postOrderL)==left_child_val){
			index=i;
			break;
		}
	}
	Node* leftSubtreeRoot = prepost(preOrder, postOrder, preOrderL+1, postOrderL,index+1);
	root->left = leftSubtreeRoot;
	Node* rightSubtreeRoot = prepost(preOrder, postOrder, preOrderL+2+index, postOrderL+1+index, size-index-2);
	root->right = rightSubtreeRoot;
	return root;
	/* write all the necessary code here */
}


Node* BinaryTree::prein(vector<int>* preOrder, vector<int>* inOrder, int preOrderL, int inOrderL, int size)
{
	Node* root = new Node();

	root->val = preOrder->at(preOrderL);
	if (root->val == 0) {
		return NULL;
	}
	int index;
	for (int i=0;i<size; i++){
		if (inOrder->at(i+inOrderL)==root->val){
			index=i;
			break;
		}
	}

	Node* leftSubtreeRoot = prein(preOrder, inOrder, preOrderL+1, inOrderL,index);
	root->left = leftSubtreeRoot;
	Node* rightSubtreeRoot = prein(preOrder, inOrder, preOrderL+1+index, inOrderL+1+index, size-index-1);
	root->right = rightSubtreeRoot;
	return root;
	/* write all the necessary code here */
}

Node* BinaryTree::inpost(vector<int>* inOrder, vector<int>* postOrder, int inOrderL, int postOrderL, int size)
{
	Node* root = new Node();

	root->val = postOrder->at(postOrderL+size-1);
	if (root->val == 0) {
		return NULL;
	}
	int index;
	for (int i=0;i<size; i++){
		if (inOrder->at(i+inOrderL)==root->val){
			index=i;
			break;
		}
	}

	Node* leftSubtreeRoot = inpost(inOrder, postOrder, inOrderL, postOrderL,index);
	root->left = leftSubtreeRoot;
	Node* rightSubtreeRoot = inpost(inOrder, postOrder, inOrderL+index+1, postOrderL+index, size-index-1);
	root->right = rightSubtreeRoot;
	return root;
	/* write all the necessary code here */
}


void BinaryTree::preOrderSeq()
{
	preOrder(root);
}

void BinaryTree::preOrder(Node * curr)
{
	if (curr == NULL) 
	{
		cout <<"0 ";
		return;
	}
	cout << curr->val <<" ";
	preOrder(curr->left);
	preOrder(curr->right);
}

void BinaryTree::inOrderSeq()
{
	inOrder(root);
}

void BinaryTree::inOrder(Node * curr)
{
	if (curr == NULL) 
	{
		cout << "0 ";
		return;
	}
	inOrder(curr->left);
	cout << curr->val <<" ";
	inOrder(curr->right);
}

void BinaryTree::postOrderSeq()
{
	postOrder(root);
}

void BinaryTree::postOrder(Node * curr)
{
	if (curr == NULL) 
	{
		cout << "0 ";
		return;
	}
	postOrder(curr->left);
	postOrder(curr->right);
	cout << curr->val <<" ";
}

int main()
{
	vector<int> firstOrder; 
	vector<int> secondOrder; 
	int z;
	string line;
	getline(cin, line);
	istringstream(line) >> z;
	while(z)
	{
		getline(cin, line);
		string firstOrderName,secondOrderName;
		int n;
		istringstream(line) >> firstOrderName >> secondOrderName >> n;
		firstOrder.clear();
		secondOrder.clear();
		getline(cin, line);
		istringstream firstString(line);
		getline(cin, line);
		istringstream secondString(line);
		for(int i =0; i<n; i++)
		{
			int val;
			firstString >> val;
			firstOrder.push_back(val);
			secondString >> val;
			secondOrder.push_back(val);
		}
		
		BinaryTree binTree = BinaryTree(firstOrderName, secondOrderName, &firstOrder, &secondOrder, n);	
		//cout << firstOrderName << " " << secondOrderName <<"\n";

		if ((firstOrderName == "PREORDER") && (secondOrderName == "INORDER"))
		{
			binTree.postOrderSeq();
			cout << "\n";
		} else
		if ((firstOrderName == "INORDER") && (secondOrderName == "POSTORDER"))
		{
			binTree.preOrderSeq();
			cout << "\n";
		} else
		if ((firstOrderName == "PREORDER") && (secondOrderName == "POSTORDER"))
		{
			binTree.inOrderSeq();
			cout << "\n";			
		}
		z--;
	}
}




