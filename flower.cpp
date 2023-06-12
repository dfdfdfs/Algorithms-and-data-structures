#include <iostream>
#include <utility>
using namespace std;

class Flower{
private: // поля
    string name;
    double diameter{};
    string family;
    double flower_length{};
    int live_time_days{};

public: // конструкторы
    Flower() = default;

    Flower(string name, double diameter, string family, double flowerLength, int liveTimeDays) : name(std::move(
            name)), diameter(diameter), family(std::move(family)), flower_length(flowerLength), live_time_days(liveTimeDays) {}

            // переопределение вывода
    friend ostream &operator<<(ostream &os, const Flower &flower) {
        os << "name: " << flower.name << " diameter: " << flower.diameter << " family: " << flower.family
           << " flower_length: " << flower.flower_length << " live_time_days: " << flower.live_time_days;
        return os;
    }

    // проверка на принадлежность к семейству
    bool is_part_of_family(const string& f){
        return family.find(f) != std::string::npos;
    }

    // увеличение жизни
    void increase_live_time_by_days(int d){
        this->live_time_days += d;
    }

    // скалирование
    void scale_diameter(double sc){
        this->diameter *= sc;
    }

    // увеличение длины
    void increase_length_by(double l){
        this->flower_length += l;
    }

    // геттеры
    const string &getName() const {
        return name;
    }

    double getDiameter() const {
        return diameter;
    }

    const string &getFamily() const {
        return family;
    }

    double getFlowerLength() const {
        return flower_length;
    }

    int getLiveTimeDays() const {
        return live_time_days;
    }
};

int main() {
    // вывод сообщение и создание массива
    cout << "3 flowers are to be created, enter data: " << endl;
    int size = 3;
    Flower* fl[3];

    // создание каждого цвета в массиве
    for (auto & i : fl) {
        cout << "Enter name, diameter, family, flower length, live time: " << endl;
        string name, fam; double d, l; int lt;
        cin >> name;
        cin >> d;
        cin >> fam;
        cin >> l;
        cin >> lt;
        i = new Flower(name, d, fam, l, lt);
    }

    // вывод каждого цвета из массива
    for (auto & i : fl) {
        cout << *i << endl;
    }

    // удаление цветка
    fl[2] = nullptr;

    //добавление цветка
    cout << "Enter name, diameter, family, flower length, live time: " << endl;
    string name, fam; double d, l; int lt;
    cin >> name;
    cin >> d;
    cin >> fam;
    cin >> l;
    cin >> lt;
    fl[2] = new Flower(name, d, fam, l, lt);

    // вывод каждого цвета из массива
    for (auto & i : fl) {
        cout << *i << endl;
    }

    return 0;
}
