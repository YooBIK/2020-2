//B811115 ������
#include <iostream>
using namespace std;
#include "bagstack.h"
int main() {
	Bag b(3);
	Stack s(3);

	b.Push(1); b.Push(2);
	b.Push(3);
	cout << "Bag: " << b;
	s.Push(1); s.Push(2);
	s.Push(3);
	cout << "Stack: " << s << endl;
	b.Pop(); s.Pop();
	cout << "Bag: " << b;
	cout << "Stack: " << s << endl << endl;
	int j = s.Size(); //Stack�� �θ�Ŭ���� Bag�� Size()�� �ҷ�����
	cout << "Stack ũ��: " << j << endl;
	j = s.Top(); //Stack�� Top()�� �ҷ�����.
	cout << "Stack Top() ���: " << j << endl;
	j = s.Element(); //Stack�� �θ�Ŭ���� Bag�� Element()�� �ҷ�����.
	cout << "Stack Element() ���: " << j << endl << endl;
}