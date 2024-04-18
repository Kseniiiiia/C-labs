
#ifndef PROGRAMMINGC_2STACK_H
#define PROGRAMMINGC_2STACK_H

class Stack {
private:
    int capacity; // размер
    int *stackArray;
    int top ; //  верхушка

public:

    Stack(); // конструктор по умолчанию
    Stack(int ); // Конструктор максимальной глубины
    Stack( std::stack<int> );
    Stack(Stack& ); // конструктор копирования
    ~Stack(); // Деструктор

    void push(int ); // Добавление
    int pop(); // Удаление
    bool isEmpty(); // Проверка на пустоту
    int peek(); // Возвращает верхний элемент
    int stack_size();  // Кол-во элементов
    void display(); // Вывод стека на экран

};
#endif //PROGRAMMINGC_2STACK_H
