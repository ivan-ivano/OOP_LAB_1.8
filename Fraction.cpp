// Fraction.cpp
#include "Fraction.h"

Fraction::LongLong::LongLong() : highPart(0), lowPart(0) {}

Fraction::LongLong::LongLong(long high, unsigned long low) : highPart(high), lowPart(low) {}

Fraction::LongLong Fraction::LongLong::operator+(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart + other.lowPart;
    result.highPart = highPart + other.highPart + (result.lowPart < lowPart);
    return result;
}

Fraction::LongLong Fraction::LongLong::operator-(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart - other.lowPart;
    result.highPart = highPart - other.highPart - (result.lowPart > lowPart);
    return result;
}

Fraction::LongLong Fraction::LongLong::operator*(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart * other.lowPart;
    result.highPart = highPart * other.highPart;
    return result;
}

bool Fraction::LongLong::operator==(const LongLong& other) const {
    return (highPart == other.highPart) && (lowPart == other.lowPart);
}

Fraction::LongLong Fraction::LongLong::operator*(const int& other) const {
    LongLong result;
    result.lowPart = lowPart * other;
    result.highPart = highPart * other;
    return result;
}

Fraction::LongLong Fraction::LongLong::operator/(const int& other) const {
    LongLong result;
    result.lowPart = lowPart / other;
    result.highPart = highPart / other;
    result.lowPart += (ULONG_MAX + 1ull) / other * (result.highPart % other);
    return result;
}

long Fraction::LongLong::GetHighPart() const {
    return highPart;
}

unsigned long Fraction::LongLong::GetLowPart() const {
    return lowPart;
}

void Fraction::LongLong::SetHighPart(long a) {
    highPart = a;
}

void Fraction::LongLong::SetLowPart(unsigned long a) {
    lowPart = a;
}

void Fraction::LongLong::Display() const {
    std::cout << "LongLong: " << highPart << " " << lowPart << std::endl;
}

void Fraction::LongLong::Read() {
    std::cout << "Enter LongLong (highPart lowPart): ";
    std::cin >> highPart >> lowPart;
}

void Fraction::LongLong::Init(long high, unsigned long low) {
    highPart = high;
    lowPart = low;
}

std::string Fraction::LongLong::ToString() const {
    std::stringstream ss;
    ss << highPart << " " << lowPart;
    return ss.str();
}

Fraction::Fraction() : fractionalPart(0) {}

Fraction::Fraction(const LongLong& intPart, unsigned short fracPart) : integerPart(intPart), fractionalPart(fracPart) {}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart + other.integerPart;
    result.fractionalPart = fractionalPart + other.fractionalPart;
    while (result.fractionalPart >= 10) {
        result.integerPart = result.integerPart + LongLong(0, 1);
        result.fractionalPart -= 10;
    }
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart - other.integerPart;
    result.fractionalPart = fractionalPart - other.fractionalPart;
    while (result.fractionalPart < 0) {
        result.integerPart = result.integerPart - LongLong(0, 1);
        result.fractionalPart += 10;
    }
    return result;
}

Fraction Fraction::Calculator::Add(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.integerPart = a.integerPart + b.integerPart;
    result.fractionalPart = a.fractionalPart + b.fractionalPart;
    while (result.fractionalPart >= 10) {
        result.integerPart = result.integerPart + Fraction::LongLong(0, 1);
        result.fractionalPart -= 10;
    }
    return result;
}

Fraction Fraction::Calculator::Subtract(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.integerPart = a.integerPart - b.integerPart;
    result.fractionalPart = a.fractionalPart - b.fractionalPart;
    while (result.fractionalPart < 0) {
        result.integerPart = result.integerPart - Fraction::LongLong(0, 1);
        result.fractionalPart += 10;
    }
    return result;
}

Fraction Fraction::Calculator::Multiply(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.integerPart = a.integerPart * b.integerPart;
    Fraction::LongLong num = b.integerPart * a.fractionalPart + a.integerPart * b.fractionalPart + Fraction::LongLong(0, a.fractionalPart * b.fractionalPart / 10);
    result.integerPart = result.integerPart + num / 10;
    result.fractionalPart = num.GetLowPart() % 10;
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart * other.integerPart;
    LongLong num = other.integerPart * fractionalPart + integerPart * other.fractionalPart + LongLong(0, fractionalPart * other.fractionalPart / 10);
    result.integerPart = result.integerPart + num / 10;
    result.fractionalPart = num.GetLowPart() % 10;
    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return (integerPart == other.integerPart) && (fractionalPart == other.fractionalPart);
}

void Fraction::Display() const {
    std::cout << "Fraction: ";
    integerPart.Display();
    std::cout << "Fractional part: " << fractionalPart << std::endl;
}

void Fraction::Read() {
    integerPart.Read();
    std::cout << "Enter Fraction (fractionalPart): " << std::endl;
    std::cin >> fractionalPart;
}

void Fraction::Init(const LongLong& intPart, unsigned short fracPart) {
    integerPart = intPart;
    fractionalPart = fracPart;
}


unsigned short Fraction::GetFractionalPart() const {
    return fractionalPart;
}

void Fraction::SetIntegerPart(const LongLong& a) {
    integerPart = a;
}

void Fraction::SetFractionalPart(unsigned short a) {
    fractionalPart = a;
}

std::string Fraction::ToString() const {
    std::stringstream ss;
    ss << integerPart.GetHighPart() << " " << integerPart.GetLowPart() << " " << fractionalPart;
    return ss.str();
}
