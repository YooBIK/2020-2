#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare >* PQ;

// �ʿ��Լ��� ���� �� �����Ͻÿ�
void MovePQ(int smaller ,int bigger) {
    while (!PQ[bigger].empty()) {
        PQ[smaller].push(PQ[bigger].top());
        PQ[bigger].pop();
    }
}
void ReadEdges4sollin(istream& is) {

    //�� ��(tree) ���� ����� �������� minheap�� �ʿ���. 
    // NNODES���� minheap�� ���� �ִ� PQ �迭�� �����Ͻÿ�.  
    PQ = new priority_queue< Edge, vector<Edge>, Compare >[NNODES];

    Edge e;

    while (GetEdge(is, e)) {
        PQ[e.v1].push(e);
        PQ[e.v2].push(e);
    }
}

void sollin() {
    Sets sets(NNODES);
    int nedge = 0;
    while (nedge < NNODES - 1) {
        for (int i = 0; i < NNODES; i++) {
            if (!PQ[i].empty()) {
                Edge e = PQ[i].top();
                PQ[i].pop();
                int root1 = sets.Find(e.v1);
                int root2 = sets.Find(e.v2);
                if (root1 != root2) {
                    sets.WeightedUnion(root1, root2);
                    nedge++;
                    cout << e;
                    MovePQ(e.v1, e.v2);
                }
                else {
               
                }
            }
          
        }
    }
}
    
    // �ڵ� �߰� �ϱ�



int main(int argc, char* argv[]) {
    //���� �Է� �κ��� kruskal���� �����ϰ�
    //�߰� 
    ifstream is;
    if (argc == 1) is.open("kin.txt");
    else is.open(argv[1]);
    if (!is) { cerr << "No such input file\n"; exit(1); }
    is >> NNODES;
    if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; exit(1); }
    try {
        ReadEdges4sollin(is);
        sollin();
    }
    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}