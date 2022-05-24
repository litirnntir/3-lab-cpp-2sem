#include <iostream>
#include <cmath>
#include "vector"

using namespace std;

class Figure {

public:

    Figure() = default;

    virtual double square() const {
        return 0;
    }

    virtual double volume() const {
        return 0;
    }

    virtual void print() const {
        return;
    }
};

class Parallelepiped : public Figure {

private:
    double length{};
    double width{};
    double height{};

public:
    Parallelepiped(double length, double width, double height) : Figure() {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    Parallelepiped() = default;

    double square() const override {
        return 2 * (length + height + width);
    }

    double volume() const override {
        return width * length * height;
    }

    void print() const override {
        cout << "Класс параллелипипед. Длина: " << this->length << ".Ширина : " << this->width << ".Высота : " << this->height << ".\n";
    }
};

class Cylinder : public Figure {

private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) : Figure() {
        this->radius = radius;
        this->height = height;
    }

    double square() const override {
        return 2 * acos(-1) * radius * (radius + height);
    }

    double volume() const override {
        return acos(-1) * height * radius * radius;
    }

    void print() const override {
        cout << "Класс цилиндр. Радиус: " << this->radius << ". Высота: " << this->height << ".\n";
    }
};

class Pyramid : public Figure {

private:
    double height;
    double apopheme;
    double side;

public:
    Pyramid(double height, double apopheme, double side) : Figure() {
        this->height = height;
        this->apopheme = apopheme;
        this->side = side;
    }

    double volume() const override {
        return side * side / 2 * height * sqrt(3);
    }

    double square() const override {
        return 3.0 / 2 * side * (side * sqrt(3) * 2 * apopheme);
    }

    void print() const override {
        cout << "Класс пирамида. Высота: " << this->height << ". Апофема: " << this->apopheme << ". Боковая сторона: " << this->side << ".\n";
    }
};

void _getchar() {
    int a = getchar();
}

void print_array2(Figure** array, int size) {
    if (size == 0) {
        printf("Список пуст\n");
    }
    for (int i = 0; i < size; i++) {
        printf("\n");
        printf("%d. ", i + 1);
        array[i]->print();
        printf("Объем: %lf\n", array[i]->volume());
        printf("Площадь: %lf\n", array[i]->square());
    }
}

void print_array(Figure** array, int size) {
    if (size == 0) {
        printf("Список пуст\n");
    }
    for (int i = 0; i < size; i++) {
        printf("%d. ", i + 1);
        array[i]->print();
    }
}

void print_element(Figure** array, int i) {
    array[i - 1]->print();
    cout << "Объем: " << array[i - 1]->volume() << endl;
    cout << "Площадь поверхности: " << array[i - 1]->square() << endl;
}

Figure* element_input1(int type, double a, double d, double c) {
    if (type == 1) {
        return new Parallelepiped(a, d, c);
    }
    else if (type == 2) {
        return new Pyramid(a, d, c);
    }
    else if (type == 3) {
        return new Cylinder(a, d);
    }

}

void element_input(int* size, Figure*** array, Figure* newElem) {
    if (newElem) {
        auto** temp = new Figure * [*size + 1];
        for (int i = 0; i < *size; i++) {
            temp[i] = (*array)[i];
        }
        if ((*size) != 0) {
            delete[] * array;
        }
        *array = temp;
        (*array)[*size] = newElem;
        (*size)++;
    }
}

void delete_element(int* index, int* size, Figure*** array) {
    delete (*array)[*index - 1];
    for (*index; *index < *size; (*index)++) {
        (*array)[*index - 1] = (*array)[*index];
    }
    (*size)--;
    auto** temp = new Figure * [*size];
    for (int i = 0; i < *size; i++) {
        temp[i] = (*array)[i];
    }
    if ((*size) != 0) {
        delete[] * array;
    }
    *array = temp;
}

void _delete(Figure** array, int size) {
    for (int i = 0; i < size; i++) {
        delete array[i];
        array[i] = nullptr;
    }
    delete[] array;
}

int main() {
    setlocale(LC_ALL, "ru");
    bool f = true;
    int choose, choose1;
    int size = 0;
    double a = 0.0, d = 0.0, c = 0.0;
    Figure** array = nullptr;
    while (f) {
        printf("Фигуры\n\n");
        printf("1.Создать объект\n");
        printf("2.Вставка в конец случайно сгенерированного объекта\n");
        printf("3.Удаление объекта по индексу\n");
        printf("4.Удаление всех объектов\n");
        printf("5.Площадь поверхности и объем i-ого элемента\n");
        printf("6.Вывод на экран\n\n");
        printf("0.Завершение работы\n\n");
        printf("Выберите действие: ");
        scanf("%d", &choose);
        _getchar();
        switch (choose) {
            case 1: {
                printf("Выберите объект:\n");
                printf("1.Параллепипед\n");
                printf("2.Пирамида\n");
                printf("3.Цилиндр\n");
                printf("4.Вернуться в меню\n");
                scanf("%d", &choose1);
                _getchar();
                switch (choose1) {
                    case 1: {
                        printf("Введите длину: ");
                        scanf("%lf", &a);
                        printf("Введите ширину: ");
                        scanf("%lf", &d);
                        printf("Введите высоту: ");
                        scanf("%lf", &c);

                        element_input(&size, &array, element_input1(1, a, d, c));
                        printf("\n");
                        print_array(array, size);
                        _getchar();
                        _getchar();
                    }
                        break;
                    case 2: {
                        printf("Введите высоту: ");
                        scanf("%lf", &a);
                        printf("Введите апофему: ");
                        scanf("%lf", &d);
                        printf("Введите боковую сторону: ");
                        scanf("%lf", &c);

                        element_input(&size, &array, element_input1(2, a, d, c));
                        printf("\n");
                        print_array(array, size);
                        _getchar();
                        _getchar();
                    }
                        break;
                    case 3: {
                        printf("Введите радиус: ");
                        scanf("%lf", &a);
                        printf("Введите высоту: ");
                        scanf("%lf", &d);

                        element_input(&size, &array, element_input1(3, a, d, c));
                        printf("\n");
                        print_array(array, size);
                        _getchar();
                        _getchar();
                    }
                        break;
                    case 4:
                        continue;
                    default:
                        break;
                }
            }
                break;
            case 2: {
                srand(time(nullptr));
                int a = rand() % 3 + 1;
                double c = abs(rand() % 2000 - 1000) / 10.0;
                double f = abs(rand() % 2000 - 1000) / 10.0;
                double d = abs(rand() & 2000 - 1000) / 10.0;
                if (a == 1)
                    element_input(&size, &array, element_input1(1, c, f, d));
                if (a == 2)
                    element_input(&size, &array, element_input1(2, c, f, d));
                if (a == 3)
                    element_input(&size, &array, element_input1(3, c, f, d));
                printf("\n");
                print_array(array, size);
                _getchar();
            }
                break;
            case 3: {
                int index;
                if (array == nullptr || size == 0) {
                    printf("Массив пуст");
                    _getchar();
                    break;
                }
                else {
                    print_array(array, size);
                    printf("\nВведите индекс, по которому хотите удалить элемент: ");
                    scanf("%d", &index);
                    while (index > size || index < 0) {
                        printf("Элемента с таким индексом не существует!");
                        printf("\nВведите индекс, по которому хотите удалить элемент: ");
                        scanf("%d", &index);
                    }
                    delete_element(&index, &size, &array);
                    printf("\n");
                    print_array(array, size);
                    _getchar();
                }
                _getchar();
            }
                break;
            case 4: {
                if (array == nullptr || size == 0)
                    printf("Массив пуст");
                else {
                    _delete(array, size);
                    printf("Удаление успешно");
                    array = nullptr;
                    size = 0;
                }
                _getchar();
            }
                break;
            case 5: {
                int j;
                if (array == nullptr || size == 0) {
                    printf("Массив пуст");
                    _getchar();
                    break;
                }
                else {

                    printf("\nВведите номер элемента : ");
                    scanf("%d", &j);
                    while (j < 1) {
                        printf("Элемент не может быть отрицательным!");
                        printf("\nВведите номер элемента, который нужно найти : ");
                        scanf("%d", &j);
                    } while (j > size) {
                        printf("Элемент не может быть больше размера массива");
                        printf("\nВведите номер элемента, который нужно найти : ");
                        scanf("%d", &j);
                    }
                    print_element(array, j);
                    _getchar();
                    _getchar();
                }

            }
                break;
            case 6: {
                print_array2(array, size);
                _getchar();
            }
                break;
            case 0: {
                _delete(array, size);
                printf("Программа завершена");
                f = false;
            }
                break;
            default:
                break;
        }
    }
}