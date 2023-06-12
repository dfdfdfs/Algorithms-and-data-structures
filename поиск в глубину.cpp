#include <iostream>
#include <vector>
#include <stack> // необходим для использования стека

using namespace std;

// Определение структуры вершины графа
struct Vertex {
    int id; // идентификатор вершины
    bool visited; // флаг, показывающий, была ли вершина посещена
    vector<int> adjacentVertices; // список идентификаторов смежных вершин
};

// Функция рекурсивного обхода графа в глубину
void dfsVisit(vector<Vertex>& graph, int vertexId) {
    graph[vertexId].visited = true; // помечаем вершину, как посещенную
    cout << "Посещенная вершина: " << vertexId << endl; // выводим идентификатор посещенной вершины в консоль

    for (int adjacentVertexId : graph[vertexId].adjacentVertices) { // перебираем идентификаторы смежных вершин текущей вершины
        if (!graph[adjacentVertexId].visited) { // если смежная вершина не была посещена
            dfsVisit(graph, adjacentVertexId); // рекурсивно вызываем функцию обхода графа для смежной вершины
        }
    }
}

// Функция поиска в глубину
void dfs(vector<Vertex>& graph, int startVertexId) {
    // Сброс флагов посещения вершин
    for (Vertex& vertex : graph) { // перебираем все вершины графа
        vertex.visited = false; // сбрасываем флаг посещения у каждой вершины
    }

    // Обход графа в глубину начиная с заданной вершины
    dfsVisit(graph, startVertexId);
}

int main() {
    // Создание графа
	setlocale(0,"Russian");
    int numVertices;
    cout << "Введите количество вершин: ";
    cin >> numVertices;
    
    vector<Vertex> graph(numVertices);

    for(int i=0; i<numVertices; i++) {
        graph[i].id = i+1;
        graph[i].visited = false;
        int numAdjacent;
        cout << "Введите количество смежных вершин для вершины " << i+1 << ": ";
        cin >> numAdjacent;
        
        for(int j=0; j<numAdjacent; j++) {
            int adjacentVertexId;
            cout << "Введите идентификатор соседней вершины " << j+1 << ": ";
            cin >> adjacentVertexId;
            graph[i].adjacentVertices.push_back(adjacentVertexId);
        }
    }
     
    // Вывод графа
    cout << "Граф:" << endl;
    for (Vertex vertex : graph) { // перебираем все вершины графа
        cout << "Вершина " << vertex.id << " -> "; // выводим идентификатор текущей вершины в консоль
        for (int adjacentVertexId : vertex.adjacentVertices) { // перебираем идентификаторы смежных вершин текущей вершины
            cout << adjacentVertexId << " "; // выводим идентификаторы смежных вершин текущей вершины в консоль
        }
        cout << endl; // переходим на следующую строку
    }

    // Обход графа в глубину, начиная с вершины 0
    cout << endl << "Поиск в глубину:" << endl;
    dfs(graph, 0); // запускаем поиск в глубину, начиная с вершины с идентификатором 0
    
    cin.get();
    return 0;
}
