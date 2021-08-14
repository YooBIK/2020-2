#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare > PQ;

void kruskal() {
    Sets sets(NNODES);
    int nedges = 0; // #edges found up to now.
    while ((nedges < NNODES - 1) && !PQ.empty()) {
        // �ּҺ�� ����e ���� 
        Edge e = PQ.top();
        // e�� PQ���� ����
        PQ.pop();
        // ����e�� �� ��v1 �� v2�� ��� ���տ� ���ߴ��� Find.
        int v1root1 = sets.Find(e.v1);
        int v2root2 = sets.Find(e.v2);
        // e�� ����Ŭ�� ������ �ʴ´ٸ�
        if (v1root1 != v2root2) {
            sets.WeightedUnion(v1root1, v2root2);
            nedges++;
            cout << e;
        }
       // �� ������WeightedUnion, nedges ���� �߰�, ����e ��� 
    }
}

void ReadEdges4kruskal(istream& is) {
    Edge e;
    while (GetEdge(is, e))
        PQ.push(e);
}

int main(int argc, char* argv[]) {
    ifstream is;
    if (argc == 1) is.open("kin.txt");
    else is.open(argv[1]);
    if (!is) { cerr << "No such input file\n"; exit(1); }
    is >> NNODES;
    if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; exit(1); }
    try {
        ReadEdges4kruskal(is);
        kruskal();
    }
    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}