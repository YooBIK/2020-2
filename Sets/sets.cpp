//B811115 ������ 
#include "sets.h"
#include <algorithm>
using namespace std;

Sets::Sets(int numberOfElements)  // constructor
{
	if (numberOfElements < 2) throw "Must have at least 2 elements";
	n = numberOfElements;
	parent = new int[n];
	fill(parent, parent + n, -1);
}

ostream& operator<<(ostream& os, Sets& s)
{
	for (int i = 0; i < s.n; i++) {
		os << i << ":" << s.parent[i] << " ";
	}
	//parent[i] ���� ����ϱ� 
		//for (int i = ...
	return os;
}
void Sets::SimpleUnion(int i, int j)
{
	parent[i] = j;
	// ���� ���� �ۼ�
}

int Sets::SimpleFind(int i)
{
	while (parent[i] >= 0) {
		i = parent[i];
	}
	return i;
	// ���� ���� �ۼ�
}

void Sets::WeightedUnion(int i, int j)
{
	// ���߱�Ģ�� �̿��Ͽ� ��Ʈ�� i�� j(i��j)�� ������ ���� ����
// parent[i] = -count[i] �̸� parent[j] = -count[j] ��. 
	{
		int temp = parent[i] + parent[j];
		if (parent[i] > parent[j]) { // i�� ��� ���� ������
			parent[i] = j; // j�� �� ��Ʈ�� �����
			parent[j] = temp;
		}
		else { // j�� ��� ���� ���ų� ������
			parent[j] = i; // i�� �� ��Ʈ�� �����
			parent[i] = temp;
		}
		// �������� �ۼ�
	}
}