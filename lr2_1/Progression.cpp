#include "Progression.h"
#include <cmath>
#include <sstream>
#include <stdexcept>

// Конструктор без аргументів
Progression::Progression()
{
    first = 1;
    second = 2;
}

// Конструктор ініціалізації
Progression::Progression(double first, double second)
{
    if (!std::isfinite(first) || !std::isfinite(second))
        throw invalid_argument("Invalid progression values");

    this->first = first;
    this->second = second;
}

// Конструктор копіювання
Progression::Progression(const Progression& other)
{
    first = other.first;
    second = other.second;
}

// Гетери
double Progression::getFirst() const
{
    return first;
}

double Progression::getSecond() const
{
    return second;
}

// Сетери з перевіркою
bool Progression::setFirst(double value)
{
    if (!std::isfinite(value))
        return false;

    first = value;
    return true;
}

bool Progression::setSecond(double value)
{
    if (!std::isfinite(value))
        return false;

    second = value;
    return true;
}

// Ініціалізація
void Progression::Init(double first, double second)
{
    if (!std::isfinite(first) || !std::isfinite(second))
        throw invalid_argument("Invalid progression values");

    this->first = first;
    this->second = second;
}


// Обчислення елемента прогресії
double Progression::elementJ(int j) const
{
    return first * pow(second, j);
}

// Перетворення об'єкта на рядок
string Progression::toString() const
{
    ostringstream out;
    out << "first = " << first
        << ", second = " << second;
    return out.str();
}

Progression::operator string() const
{
    return toString();
}

// Унарні операції
Progression Progression::operator+() const
{
    return *this;
}

Progression Progression::operator-() const
{
    return Progression(-first, -second);
}

bool Progression::operator!() const
{
    return first == 0 && second == 0;
}

// Префіксний ++ змінює first
Progression& Progression::operator++()
{
    ++first;
    return *this;
}

// Постфіксний ++ змінює second
Progression Progression::operator++(int)
{
    Progression old(*this);
    ++second;
    return old;
}

// Префіксний -- змінює first
Progression& Progression::operator--()
{
    --first;
    return *this;
}

// Постфіксний -- змінює second
Progression Progression::operator--(int)
{
    Progression old(*this);
    --second;
    return old;
}

// Оператор присвоєння
Progression& Progression::operator=(const Progression& other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

// Складені операції
Progression& Progression::operator+=(const Progression& other)
{
    first += other.first;
    second += other.second;
    return *this;
}

Progression& Progression::operator-=(const Progression& other)
{
    first -= other.first;
    second -= other.second;
    return *this;
}

Progression& Progression::operator*=(const Progression& other)
{
    first *= other.first;
    second *= other.second;
    return *this;
}

Progression& Progression::operator/=(const Progression& other)
{
    if (other.first == 0 || other.second == 0)
        throw invalid_argument("Division by zero");

    first /= other.first;
    second /= other.second;
    return *this;
}

// Дружні функції введення та виведення
istream& operator>>(istream& in, Progression& p)
{
    double first, second;

    cout << "Enter first element: ";
    if (!(in >> first))
        return in;

    cout << "Enter ratio: ";
    if (!(in >> second))
        return in;

    if (!std::isfinite(first) || !std::isfinite(second))
    {
        in.setstate(ios::failbit);
        return in;
    }

    p.setFirst(first);
    p.setSecond(second);

    return in;
}


ostream& operator<<(ostream& out, const Progression& p)
{
    out << "first = " << p.first
        << ", second = " << p.second;
    return out;
}

// Дружні бінарні операції
Progression operator+(const Progression& a, const Progression& b)
{
    return Progression(a.first + b.first,
        a.second + b.second);
}

Progression operator-(const Progression& a, const Progression& b)
{
    return Progression(a.first - b.first,
        a.second - b.second);
}

Progression operator*(const Progression& a, const Progression& b)
{
    return Progression(a.first * b.first,
        a.second * b.second);
}

Progression operator/(const Progression& a, const Progression& b)
{
    if (b.first == 0 || b.second == 0)
        throw invalid_argument("Division by zero");

    return Progression(a.first / b.first,
        a.second / b.second);
}

// Порівняння об'єктів
bool operator==(const Progression& a, const Progression& b)
{
    return a.first == b.first && a.second == b.second;
}

bool operator!=(const Progression& a, const Progression& b)
{
    return !(a == b);
}

// Створення об'єкта
Progression makeProgression(double first, double second)
{
    return Progression(first, second);
}
