#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <queue>

using namespace std;

template <class K, class E> class BST; //전방선언

template <class K, class E>
class TreeNode {
	friend class BST<K, E>;
	TreeNode(K ky, E el, TreeNode<K, E>* left = 0, TreeNode<K, E>* right = 0)
		: key(ky), element(el), leftChild(left), rightChild(right) { }

private:
	TreeNode<K, E>* leftChild;
	K key;
	E element;
	TreeNode<K, E>* rightChild;
};

template <class K, class E>
class BST {
public:
	BST() { root = 0; } // empty BST
	void Insert(K& newkey, E& el) { Insert(root, newkey, el); }
	void Preorder() { Preorder(root); }
	void Inorder() { Inorder(root); }
	void Postorder() { Postorder(root); }
	void Levelorder();
	bool Find(const K&, E&);
	void Delete(K& oldkey) { Delete(root, oldkey); };
private:  // helper 함수들
	void Visit(TreeNode<K, E>*);
	void Insert(TreeNode<K, E>*&, K&, E&);
	void Preorder(TreeNode<K, E>*);
	void Inorder(TreeNode<K, E>*);
	void Postorder(TreeNode<K, E>*);
	void Delete(TreeNode<K, E>*&, K&);
	TreeNode<K, E>* root;
};

template <class K, class E>
void BST<K, E>::Visit(TreeNode<K, E>* ptr)
{
	cout << ptr->key << ":" << ptr->element << " ";
}
template <class K, class E>
void BST<K, E>::Insert(TreeNode<K, E>*& ptr, K& newkey, E& el) { //Insert의helper함수
	if (ptr == 0) { 
		ptr = new TreeNode<K, E>(newkey, el); 
	}
	else if (newkey < ptr->key) {
		Insert(ptr->leftChild, newkey, el); 
	}
	else if (newkey > ptr->key) { 
		Insert(ptr->rightChild, newkey, el); 
	}
	else { 
		ptr->element = el;
	}// Update element
}
template <class K, class E>
void BST<K, E>::Preorder(TreeNode<K, E>* currentNode) { //Preorder의helper함수
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template <class K, class E>
void BST<K, E>::Inorder(TreeNode<K, E>* currentNode) { //Preorder의helper함수
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}

template <class K, class E>
void BST<K, E>::Postorder(TreeNode<K, E>* currentNode) { //Preorder의helper함수
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

template <class K, class E>
void BST<K, E>::Levelorder()
{//이진 트리의 레벨 순서 순회
	queue<TreeNode <K, E>* >q; // 큐를 사용하자
	TreeNode<K, E>* currentNode = root;
	while (currentNode) {
		Visit(currentNode);
		if (currentNode->leftChild) {
			q.push(currentNode->leftChild);
		}
		if (currentNode->rightChild) {
			q.push(currentNode->rightChild); 
		}
		if (q.empty()) { 
			return;
		}
		currentNode = q.front(); // 큐에서 꺼내자.
		q.pop();
	}
}

template <class K, class E>
bool BST<K, E>::Find(const K& k, E& e)
{
	TreeNode<K, E>* ptr = root;
	while (ptr != 0) {
		if (ptr->key == k) {
			e = ptr->element;
			return true;
		}
		else if (ptr->key < k) {
			ptr = ptr->rightChild;
		}
		else if (ptr->key > k) {
			ptr = ptr->leftChild;
		}
	}
	return false;
	// root부터 시작해서 k와 같은 key를 갖고 있는 노드를 찾아 
	// 찾은 노드의 element를 e로 전달하여 반환한다. 
	// k를 갖고 있는 e를 찾았으면 true, 못 찾았으면 false를 반환한다.
}

template <class K, class E>
void BST<K, E>::Delete(TreeNode<K, E>*& ptr, K& oldkey)
{
	// ptr를 루트로 하는 트리에서 oldkey를 키로 하는 노드를 지우시오.
	TreeNode<K, E>* tmpptr;
	TreeNode<K, E>* tmpparentptr;

	if (ptr == 0) {
		return;
	}// 그런 노드가 없으므로, 그냥 return

	if (oldkey < ptr->key) { //left subtree에서 oldkey를 찾아 지우시오
		Delete(ptr->leftChild, oldkey);
	}
	else if (oldkey > ptr->key) {
		Delete(ptr->rightChild, oldkey);
	} // right subtree에서 지우시오
	  // 코딩하시오

	else { // oldkey를 갖고있는 삭제할 ptr노드를 찾은 경우: 
		 // Children 중 적당한 노드를 찾아 현재노드를 대체한다.
		if (!ptr->leftChild && !ptr->rightChild) // Children이 없다면
		{
			delete ptr;
			ptr = 0;
			return;
		}

		else if (ptr->leftChild && !ptr->rightChild)
			// 그child를 ptr가 가리키게하고 현재 ptr가 가리키는 노드 지움
		{
			tmpptr = ptr;
			ptr = ptr->leftChild;
			delete tmpptr;
			return;
		}
		else if (!ptr->leftChild && ptr->rightChild)
		{
			tmpptr = ptr;
			ptr = ptr->rightChild;
			delete tmpptr;
			return;
		}
		else { //왼쪽 및 오른쪽 child모두 있는 경우:
			   //루트가 rc인 우측트리에서 ‘제일 작은 노드’찾자

			TreeNode<K, E>* rc = ptr->rightChild; // rc가 루트인 subtree

			if (!rc->leftChild) {
				ptr->key = rc->key;
				ptr->element = rc->element;
				if (!rc->rightChild) {
					ptr->rightChild = rc->rightChild;
				}
				delete rc;
				return;
			}// rc가 왼쪽Child가 없으면 rc가 그 노드!
			// { rc노드의 key/element/rightChild 정보를 ptr노드로 옮기고
			//   rc노드 지움(즉 delete rc);}

			else {
				tmpparentptr = rc;
				tmpptr = rc->leftChild;
				while (tmpptr->leftChild) {
					tmpparentptr = tmpptr;
					tmpptr = tmpptr->leftChild;
				}
				ptr->key = tmpptr->key;
				ptr->element = tmpptr->element;
				if (tmpptr->rightChild) {
					tmpparentptr->leftChild = tmpptr->rightChild;

					delete tmpptr;
					return;


				}// rc의 왼쪽Child가 있는 경우, rc의 왼쪽Child의 왼쪽Child
				// { 식으로 왼쪽 Child를 끝까지 쫒아가,가장 작은 키 갖는 노드
				//  를 찾는다. 그 노드의 key/element를  ptr노드로 옮기고, 
				//  그 노드의 rightChild를 그 노드의 parent의 leftChild로 저장
				//  한 다음 그 노드를 삭제; }  
			}
		}
	}
}
#endif 