#include <iostream>
#include <vector>
#include <stack> // ��������� ��� ������������� �����

using namespace std;

// ����������� ��������� ������� �����
struct Vertex {
    int id; // ������������� �������
    bool visited; // ����, ������������, ���� �� ������� ��������
    vector<int> adjacentVertices; // ������ ��������������� ������� ������
};

// ������� ������������ ������ ����� � �������
void dfsVisit(vector<Vertex>& graph, int vertexId) {
    graph[vertexId].visited = true; // �������� �������, ��� ����������
    cout << "���������� �������: " << vertexId << endl; // ������� ������������� ���������� ������� � �������

    for (int adjacentVertexId : graph[vertexId].adjacentVertices) { // ���������� �������������� ������� ������ ������� �������
        if (!graph[adjacentVertexId].visited) { // ���� ������� ������� �� ���� ��������
            dfsVisit(graph, adjacentVertexId); // ���������� �������� ������� ������ ����� ��� ������� �������
        }
    }
}

// ������� ������ � �������
void dfs(vector<Vertex>& graph, int startVertexId) {
    // ����� ������ ��������� ������
    for (Vertex& vertex : graph) { // ���������� ��� ������� �����
        vertex.visited = false; // ���������� ���� ��������� � ������ �������
    }

    // ����� ����� � ������� ������� � �������� �������
    dfsVisit(graph, startVertexId);
}

int main() {
    // �������� �����
	setlocale(0,"Russian");
    int numVertices;
    cout << "������� ���������� ������: ";
    cin >> numVertices;
    
    vector<Vertex> graph(numVertices);

    for(int i=0; i<numVertices; i++) {
        graph[i].id = i+1;
        graph[i].visited = false;
        int numAdjacent;
        cout << "������� ���������� ������� ������ ��� ������� " << i+1 << ": ";
        cin >> numAdjacent;
        
        for(int j=0; j<numAdjacent; j++) {
            int adjacentVertexId;
            cout << "������� ������������� �������� ������� " << j+1 << ": ";
            cin >> adjacentVertexId;
            graph[i].adjacentVertices.push_back(adjacentVertexId);
        }
    }
     
    // ����� �����
    cout << "����:" << endl;
    for (Vertex vertex : graph) { // ���������� ��� ������� �����
        cout << "������� " << vertex.id << " -> "; // ������� ������������� ������� ������� � �������
        for (int adjacentVertexId : vertex.adjacentVertices) { // ���������� �������������� ������� ������ ������� �������
            cout << adjacentVertexId << " "; // ������� �������������� ������� ������ ������� ������� � �������
        }
        cout << endl; // ��������� �� ��������� ������
    }

    // ����� ����� � �������, ������� � ������� 0
    cout << endl << "����� � �������:" << endl;
    dfs(graph, 0); // ��������� ����� � �������, ������� � ������� � ��������������� 0
    
    cin.get();
    return 0;
}
