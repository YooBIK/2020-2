#include "mstree.h"


priority_queue< Edge, vector<Edge>, Compare > PQ;

queue< Edge >* Q; // each vertex has a queue

void MoveIntoPQ_EdgesOfNodes(int v) {
    while (Q[v].empty()==false) {
        PQ.push(Q[v].front());
        Q[v].pop();
    }
    // Move all edges of vertex 'v' in the queue Q into PQ
}

void prim() {
    Sets sets(NNODES);
    int nedges = 0; // #edges found up to now.
    while (nedges < NNODES - 1) {
        if (PQ.empty()) throw "No Spanning Tree Exists.";
        Edge e = PQ.top(); PQ.pop();
        // ���� ���õ� edge e�� �� ��(���)���� ��Ʈ�� ���Ѵ�.
        int v1root1 = sets.Find(e.v1);
        int v2root2 = sets.Find(e.v2);
        // PQ ���� e�� �ڰ��� ������, �� ���� WeightedUnion, nedges �����߰�, e��� 
        if (v1root1 != v2root2) {
            sets.WeightedUnion(v1root1, v2root2);
            nedges++;
            cout << e;
            MoveIntoPQ_EdgesOfNodes(e.v1);
            MoveIntoPQ_EdgesOfNodes(e.v2);
        }
        
        // Ʈ���� ���� ó���� e�� �� ���� ����� edge���� PQ�� �ű��.
    }
}
void ReadEdges4prim(istream& is) {
    Edge e;
    Q = new queue <Edge>[NNODES];

    // NNODES�� �� ��(vertex)�� ���� queue���� �迭�� �����Ѵ�.
    // �� ���� ����� ����(edges)�� ��Ÿ���� ���� 

    while (GetEdge(is, e))
    {

        //�� ��(vertex �Ǵ� ���)�� ť�� ���� e�� �ִ´�. 
        // �� edge�� ����� ���� �� �� (e.v1, e.v2) 
        Q[e.v1].push(e);
        Q[e.v2].push(e);
        

    }
    MoveIntoPQ_EdgesOfNodes(0); // ���� �� 0�� edge���� PQ �� �̵��Ѵ�.
}

int main(int argc, char* argv[]) {
    // �Էºκ��� kruskal ���� �����ϰ�
    // �߰� �� ��
    ifstream is;
    if (argc == 1) is.open("kin.txt");
    else is.open(argv[1]);
    if (!is) { cerr << "No such input file\n"; exit(1); }
    is >> NNODES;
    if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; exit(1); }
    try {
        ReadEdges4prim(is);
        prim();
    }
    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}