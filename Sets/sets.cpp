//B811115 유병익 
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
	//parent[i] 값을 출력하기 
		//for (int i = ...
	return os;
}
void Sets::SimpleUnion(int i, int j)
{
	parent[i] = j;
	// 교재 참조 작성
}

int Sets::SimpleFind(int i)
{
	while (parent[i] >= 0) {
		i = parent[i];
	}
	return i;
	// 교재 참조 작성
}

void Sets::WeightedUnion(int i, int j)
{
	// 가중규칙을 이용하여 루트가 i와 j(i≠j)인 집합의 합을 구함
// parent[i] = -count[i] 이며 parent[j] = -count[j] 임. 
	{
		int temp = parent[i] + parent[j];
		if (parent[i] > parent[j]) { // i의 노드 수가 적으면
			parent[i] = j; // j를 새 루트로 만든다
			parent[j] = temp;
		}
		else { // j의 노드 수가 적거나 같으면
			parent[j] = i; // i를 새 루트로 만든다
			parent[i] = temp;
		}
		// 교재참조 작성
	}
}