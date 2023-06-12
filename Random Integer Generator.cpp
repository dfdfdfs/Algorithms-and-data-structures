#include <iostream>
#include <cstdlib> // для функции rand()
#include <ctime> // для функции time()
#include <algorithm> // для функции sort()

using namespace std;

struct RandomIntGenerator {
  int min_value, max_value;
  
  RandomIntGenerator(int min_val, int max_val) {
    min_value = min_val;
    max_value = max_val;
    srand(time(nullptr)); // инициализация генератора случайных чисел
  }
  
  int generate() {
    return rand() % (max_value - min_value + 1) + min_value; // генерация случайного числа в заданном диапазоне
  }
};

int main() {
	setlocale(0,"Russian");
  const int SIZE = 10; // размер массива
  RandomIntGenerator rng(1, 100); // создание генератора случайных чисел с диапазоном от 1 до 100
  
  int arr[SIZE];
  
  // заполнение массива случайными числами
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rng.generate();
  }
  
  // вывод неотсортированного массива
  cout << "Неотсортированный массив: ";
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  // сортировка массива любым методом
  sort(arr, arr + SIZE); // здесь используется метод sort() из библиотеки algorithm
  
  // вывод отсортированного массива
  cout << "Отсортированный массив: ";
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  return 0;
}