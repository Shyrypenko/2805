#include <iostream>
#include <numeric>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Ошибка: знаменатель не может быть равен 0. Устанавливается значение по умолчанию 1." << std::endl;
            denominator = 1;
        }
        reduce();
    }

    void input() {
        std::cout << "Введите числитель: ";
        std::cin >> numerator;
        std::cout << "Введите знаменатель: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cerr << "Ошибка: знаменатель не может быть равен 0. Устанавливается значение по умолчанию 1." << std::endl;
            denominator = 1;
        }
        reduce();
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2;
    f2.input();

    Fraction sum = f1 + f2;
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;

    std::cout << "Первая дробь: ";
    f1.print();
    std::cout << "Вторая дробь: ";
    f2.print();

    std::cout << "Сумма: ";
    sum.print();
    std::cout << "Разность: ";
    difference.print();
    std::cout << "Произведение: ";
    product.print();
    std::cout << "Частное: ";
    quotient.print();
}
