#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
// Класс "Кот"
using namespace std;
class Cat
{
public:
    std::string name;
    int miceCaught;
    // Конструктор с параметрами
	// После двоеточия инициализируем переменные
    Cat(std::string n, int m) : name(n), miceCaught(m) { }
};


// Функция для сортировки методом вставок
void insertionSort(std::vector<Cat>& cats)
{
    for (size_t i = 1; i < cats.size(); ++i)
    {
        Cat key = cats[i];
        int j = i - 1;
        // Сортировка по количеству пойманных мышей
        while (j >= 0 && cats[j].miceCaught > key.miceCaught)
        {
            cats[j + 1] = cats[j];
            j--;
        }
        cats[j + 1] = key;
    }
}
int main()
{
    setlocale(0,"Russian");
    int numVertices;

    cout << "Введите количество котов: ";
    cin >> numVertices;
    // Создание очереди котов с помощью вектора
    std::vector<Cat> catQueue;
   for(int i=0; i<numVertices; i++) {
        string s;
        int f;
        cout << "Введите имя кота" << i+1 << ": ";
        cin >> s;
        cout << "Введите возраст кота" << i+1 << ": ";
        cin >> f;
       catQueue.push_back(Cat(s, f));
    }

    insertionSort(catQueue);
    // Вывод отсортированных котов
	// auto - автоматически определяем тип переменной cat
	// В переменную cat заносим все что есть в переменной catQueue
    for (auto cat : catQueue)
    {
        std::cout << "Cat name: " << cat.name << ", mice caught: " << cat.miceCaught << std::endl;
    }
    return 0;
}