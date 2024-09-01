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
            std::cerr << "������: ����������� �� ����� ���� ����� 0. ��������������� �������� �� ��������� 1." << std::endl;
            denominator = 1;
        }
        reduce();
    }

    void input() {
        std::cout << "������� ���������: ";
        std::cin >> numerator;
        std::cout << "������� �����������: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cerr << "������: ����������� �� ����� ���� ����� 0. ��������������� �������� �� ��������� 1." << std::endl;
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

    std::cout << "������ �����: ";
    f1.print();
    std::cout << "������ �����: ";
    f2.print();

    std::cout << "�����: ";
    sum.print();
    std::cout << "��������: ";
    difference.print();
    std::cout << "������������: ";
    product.print();
    std::cout << "�������: ";
    quotient.print();
}
