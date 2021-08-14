#ifndef BT_H
#define BT_H
#include <iostream>
#include <queue>


using namespace std;

template <class T> class Tree; //���漱��

template <class T>
class TreeNode {
	friend class Tree<T>;
	TreeNode(T d, TreeNode<T>* left = 0, TreeNode<T>* right = 0)
		: data(d), leftChild(left), rightChild(right) { }
private:
	TreeNode<T>* leftChild;
	T data;
	TreeNode<T>* rightChild;
};

template <class T>
class Tree {
public:
	Tree() { root = 0; } // empty tree
	void Insert(T& value) { Insert(root, value); }
	void Preorder() { Preorder(root); }
	void Inorder() { Inorder(root); }
	void Postorder() { Postorder(root); }
	void Levelorder();
private:  // helper �Լ���
	void Visit(TreeNode<T>*);
	void Insert(TreeNode<T>*&, T&);
	void Preorder(TreeNode<T>*);
	void Inorder(TreeNode<T>*);
	void Postorder(TreeNode<T>*);

	TreeNode<T>* root;
};

template <class T>
void Tree<T>::Visit(TreeNode<T>* ptr) { cout << ptr->data << " "; }

template <class T>
void Tree<T>::Insert(TreeNode<T>*& ptr, T& value) { //Insert��helper�Լ�
	//ptr��root
	if (ptr == 0) ptr = new TreeNode<T>(value);
	else if (value < ptr->data) Insert(ptr->leftChild, value);
	else if (value > ptr->data) Insert(ptr->rightChild, value);
	else cout << endl << "Duplicate value " << value << " ignored\n";
}
template <class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode) { //Preorder��helper�Լ�
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}
template <class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode) { //Preorder��helper�Լ�
	if (currentNode) {

		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
template <class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode) { //Preorder��helper�Լ�
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);

	}
}
template <class T>
void Tree<T>::Levelorder() {
	queue<TreeNode<T>*> q; // ť�� �������
	TreeNode<T>* currentNode = root;
	while (currentNode) {
		Visit(currentNode);
		if (currentNode->leftChild) q.push(currentNode->leftChild);
		if (currentNode->rightChild) q.push(currentNode->rightChild);
		if (q.empty()) return;
		currentNode = q.front(); // ť���� ������.
		q.pop();
	}
}
//..... Inorder, Postorder��helper�Լ��������Ͻÿ�.
//..... Levelorder(����p266 �����ϵ�STL ť���̿�)�������Ͻÿ�.
#endif