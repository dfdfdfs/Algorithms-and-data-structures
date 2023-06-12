#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    int id; // ������������� �������
    bool visited; // ���� ���������
    vector<int> adjacentVertices; // ������ ��������������� ������� ������
};

void bfs(vector<Vertex>& graph, int startVertexId) {
    queue<int> vertexQueue; // ������� ��� ��������� ������
    vertexQueue.push(startVertexId); // ��������� ��������� ������� � �������
    graph[startVertexId].visited = true; // �������� ��������� �������, ��� ����������

    while (!vertexQueue.empty()) { // ���� ������� �� �����
        int vertexId = vertexQueue.front(); // ����� ������� �� �������
        vertexQueue.pop(); // ������� ������� �� �������
        cout << "���������� �������: " << vertexId << endl; // ������� ������������� ���������� �������

        for (int adjacentVertexId : graph[vertexId].adjacentVertices) { // ���������� ������� �������
            if (!graph[adjacentVertexId].visited) { // ���� ������� ������� �� ���� ��������
                vertexQueue.push(adjacentVertexId); // ��������� ������� ������� � �������
                graph[adjacentVertexId].visited = true; // �������� ������� �������, ��� ����������
            }
        }
    }
}

int main() {
    // ������� ����
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

    cout << endl << "����� � ������:" << endl;
    bfs(graph, 0); // ��������� ����� � ������, ������� � ������� � ��������������� 0

    cin.get();
    return 0;
}























