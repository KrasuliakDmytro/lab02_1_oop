#pragma once
#include <iostream>
#include <string>

using namespace std;

class Progression
{
private:
    double first;
    double second;

public:
    // Конструктор без аргументів
    Progression();

    // Конструктор ініціалізації
    Progression(double first, double second);

    // Конструктор копіювання
    Progression(const Progression& other);

    // Методи доступу
    double getFirst() const;
    double getSecond() const;

    bool setFirst(double value);
    bool setSecond(double value);

    // Ініціалізація та обчислення елемента прогресії
    void Init(double first, double second);
    double elementJ(int j) const;

    // Перетворення на рядок
    string toString() const;
    operator string() const;

    // Унарні операції
    Progression operator+() const;
    Progression operator-() const;
    bool operator!() const;

    // Інкремент і декремент
    Progression& operator++();
    Progression operator++(int);
    Progression& operator--();
    Progression operator--(int);

    // Присвоєння
    Progression& operator=(const Progression& other);

    // Складені операції присвоєння
    Progression& operator+=(const Progression& other);
    Progression& operator-=(const Progression& other);
    Progression& operator*=(const Progression& other);
    Progression& operator/=(const Progression& other);

    // Дружні функції введення та виведення
    friend istream& operator>>(istream& in, Progression& p);
    friend ostream& operator<<(ostream& out, const Progression& p);

    // Інші бінарні операції — дружні функції
    friend Progression operator+(const Progression& a,
        const Progression& b);
    friend Progression operator-(const Progression& a,
        const Progression& b);
    friend Progression operator*(const Progression& a,
        const Progression& b);
    friend Progression operator/(const Progression& a,
        const Progression& b);

    friend bool operator==(const Progression& a,
        const Progression& b);
    friend bool operator!=(const Progression& a,
        const Progression& b);

    // Зовнішня функція створення об'єкта
    friend Progression makeProgression(double first, double second);
};

// Функція створення об'єкта
Progression makeProgression(double first, double second);
