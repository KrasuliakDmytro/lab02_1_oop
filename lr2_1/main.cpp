#include "Progression.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Клас із таким самим розташуванням полів для перевірки pack(1)
#pragma pack(push, 1)
class PackedProgressionLayout
{
public:
    double first;
    double second;
};
#pragma pack(pop)

int main()
{
    try
    {
        cout << "===== CONSTRUCTORS =====\n";

        // Конструктор без аргументів
        Progression p1;
        cout << "p1: " << p1 << endl;

        // Конструктор ініціалізації
        Progression p2(2, 3);
        cout << "p2: " << p2 << endl;

        // Конструктор копіювання
        Progression p3(p2);
        cout << "p3 (copy): " << p3 << endl;

        // Функція створення об'єкта
        Progression p4 = makeProgression(5, 2);
        cout << "p4: " << p4 << endl;

        cout << "\n===== GETTERS AND SETTERS =====\n";
        cout << "first = " << p2.getFirst() << endl;
        cout << "second = " << p2.getSecond() << endl;

        p2.setFirst(4);
        p2.setSecond(2);
        cout << "After setters: " << p2 << endl;

        cout << "\n===== ELEMENT J =====\n";
        cout << "elementJ(0) = " << p2.elementJ(0) << endl;
        cout << "elementJ(1) = " << p2.elementJ(1) << endl;
        cout << "elementJ(3) = " << p2.elementJ(3) << endl;

        cout << "\n===== INIT =====\n";
        p1.Init(3, 2);
        cout << p1 << endl;


        cout << "\n===== KEYBOARD INPUT =====\n";

        Progression p5;
        cin >> p5;

        if (!cin)
        {
            cout << "Incorrect input!\n";
            return 1;
        }

        cout << "Entered progression: " << p5 << endl;

        // Введення номера елемента
        int j;
        cout << "Enter j: ";
        cin >> j;

        if (!cin || j < 0)
        {
            cout << "Incorrect j! Enter a non-negative integer.\n";
            return 1;
        }

        // Обчислення та виведення елемента
        cout << "elementJ(" << j << ") = "
            << p5.elementJ(j) << endl;


        cout << "Entered progression: " << p5 << endl;

        cout << "\n===== UNARY OPERATIONS =====\n";
        cout << "+p2 = " << +p2 << endl;
        cout << "-p2 = " << -p2 << endl;
        cout << "!p2 = " << (!p2) << endl;

        cout << "\n===== INCREMENT AND DECREMENT =====\n";
        Progression p6(2, 3);

        cout << "Original: " << p6 << endl;
        cout << "++p6: " << ++p6 << endl;
        cout << "p6++ returns: " << p6++ << endl;
        cout << "After p6++: " << p6 << endl;

        cout << "--p6: " << --p6 << endl;
        cout << "p6-- returns: " << p6-- << endl;
        cout << "After p6--: " << p6 << endl;

        cout << "\n===== BINARY OPERATIONS =====\n";
        Progression a(8, 4);
        Progression b(2, 2);

        cout << "a + b = " << a + b << endl;
        cout << "a - b = " << a - b << endl;
        cout << "a * b = " << a * b << endl;
        cout << "a / b = " << a / b << endl;

        cout << "\n===== COMPOUND OPERATIONS =====\n";
        Progression c(8, 4);

        c += b;
        cout << "c += b: " << c << endl;

        c -= b;
        cout << "c -= b: " << c << endl;

        c *= b;
        cout << "c *= b: " << c << endl;

        c /= b;
        cout << "c /= b: " << c << endl;

        cout << "\n===== ASSIGNMENT AND COMPARISON =====\n";
        Progression d;
        d = a;

        cout << "d = a: " << d << endl;
        cout << "a == d: " << (a == d) << endl;
        cout << "a != b: " << (a != b) << endl;

        cout << "\n===== STRING CONVERSION =====\n";
        string text = static_cast<string>(a);
        cout << text << endl;

        cout << "\n===== ARRAY OF OBJECTS =====\n";
        Progression arr[3] = {
            Progression(1, 2),
            Progression(2, 3),
            Progression(3, 4)
        };

        for (int i = 0; i < 3; i++)
        {
            cout << "arr[" << i << "]: " << arr[i] << endl;
        }

        cout << "\n===== CLASS SIZE =====\n";
        cout << "sizeof(Progression) = "
            << sizeof(Progression) << " bytes\n";

        cout << "sizeof(PackedProgressionLayout) = "
            << sizeof(PackedProgressionLayout) << " bytes\n";

        cout << "\n===== toString =====\n";
        cout << p5.toString() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
