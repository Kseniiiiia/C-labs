#include "4Figureset.h"
#include "4cycle.h"
#include "4rectangle.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    Figures figs1;

    cout << "Добавить фигуру в множество - 1 " << endl;
    cout << "Отобразить все фигуры - 2 " << endl;
    cout << "Сумма площадей всех фигур - 3 " << endl;
    cout << "Суммарный периметр фигур - 4 " << endl;
    cout << "Центр масс всех фигур - 5 " << endl;
    cout << "Память на все экземпляры классов - 6 " << endl;
    cout << "Выход - 0 " << endl;

    while (true){
        string s;
        cin >> s;
        if (s == "0"){
            break;
        }

        else if (s == "1"){
            figs1.addfigure();
            cout << "Фигура добавлена\n";
        }

        else if (s == "2"){
            figs1.display();
        }

        else if (s == "3"){
            cout << figs1.square_all() << " - Суммарная площадь \n";;
        }

        else if (s == "4"){
            cout << figs1.perimetr_all() << " - Суммарный периметр \n";
        }

        else if (s == "5"){
            cout << figs1.position_all().x << " " << figs1.position_all().y << " - Кординаты центра масс " << endl;
        }

        else if (s == "6"){
            cout << figs1.memory_all() << " байт памяти занимают фигуры\n";
        }
    }

    return 0;
}
