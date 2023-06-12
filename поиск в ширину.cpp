#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    int id; // идентификатор вершины
    bool visited; // флаг посещени€
    vector<int> adjacentVertices; // список идентификаторов смежных вершин
};

void bfs(vector<Vertex>& graph, int startVertexId) {
    queue<int> vertexQueue; // очередь дл€ посещени€ вершин
    vertexQueue.push(startVertexId); // добавл€ем стартовую вершину в очередь
    graph[startVertexId].visited = true; // помечаем стартовую вершину, как посещенную

    while (!vertexQueue.empty()) { // пока очередь не пуста
        int vertexId = vertexQueue.front(); // берем вершину из очереди
        vertexQueue.pop(); // удал€ем вершину из очереди
        cout << "ѕосещенна€ вершина: " << vertexId << endl; // выводим идентификатор посещенной вершины

        for (int adjacentVertexId : graph[vertexId].adjacentVertices) { // перебираем смежные вершины
            if (!graph[adjacentVertexId].visited) { // если смежна€ вершина не была посещена
                vertexQueue.push(adjacentVertexId); // добавл€ем смежную вершину в очередь
                graph[adjacentVertexId].visited = true; // помечаем смежную вершину, как посещенную
            }
        }
    }
}

int main() {
    // создаем граф
	setlocale(0,"Russian");
    int numVertices;
    cout << "¬ведите количество вершин: ";
    cin >> numVertices;
    
    vector<Vertex> graph(numVertices);

    for(int i=0; i<numVertices; i++) {
        graph[i].id = i+1;
        graph[i].visited = false;
        int numAdjacent;
        cout << "¬ведите количество смежных вершин дл€ вершины " << i+1 << ": ";
        cin >> numAdjacent;
        
        for(int j=0; j<numAdjacent; j++) {
            int adjacentVertexId;
            cout << "¬ведите идентификатор соседней вершины " << j+1 << ": ";
            cin >> adjacentVertexId;
            graph[i].adjacentVertices.push_back(adjacentVertexId);
        }
    }
    
    // ¬ывод графа
    cout << "√раф:" << endl;
    for (Vertex vertex : graph) { // перебираем все вершины графа
        cout << "¬ершина " << vertex.id << " -> "; // выводим идентификатор текущей вершины в консоль
        for (int adjacentVertexId : vertex.adjacentVertices) { // перебираем идентификаторы смежных вершин текущей вершины
            cout << adjacentVertexId << " "; // выводим идентификаторы смежных вершин текущей вершины в консоль
        }
        cout << endl; // переходим на следующую строку
    }

    cout << endl << "ѕоиск в ширину:" << endl;
    bfs(graph, 0); // запускаем поиск в ширину, начина€ с вершины с идентификатором 0

    cin.get();
    return 0;
}























