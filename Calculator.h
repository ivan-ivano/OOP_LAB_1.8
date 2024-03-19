// Calculator.h
#include <sstream>
#include <string>

class Calculator {

public:
    class Fraction {
    private:
        LongLong integerPart;
        unsigned short int fractionalPart;


    public:
        class LongLong {
        private:
            long highPart;
            unsigned long lowPart;

        public:
            LongLong();
            LongLong(long high, unsigned long low);

            LongLong operator+(const LongLong& other) const;
            LongLong operator-(const LongLong& other) const;
            LongLong operator*(const LongLong& other) const;

            bool operator==(const LongLong& other) const;

            LongLong operator*(const int& other) const;

            LongLong operator/(const int& other) const;

            long GetHighPart() const;
            unsigned long GetLowPart() const;
            void SetHighPart(long a);
            void SetLowPart(unsigned long a);

            void Display() const;
            void Read();

            void Init(long high, unsigned long low);

            std::string ToString(LongLong& a);
        };


    public:
        Fraction();
        Fraction(const LongLong& intPart, unsigned short fracPart);

        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        bool operator==(const Fraction& other) const;

        void Display() const;
        void Read();
        void Init(LongLong intPart, unsigned short fracPart);
        std::string ToString(Fraction& a);

        LongLong GetIntegerPart() const;
        unsigned short GetFractionalPart() const;
        void SetIntegerPart(const LongLong& a);
        void SetFractionalPart(unsigned short a);
    };


public:
    static Fraction Add(const Fraction& a, const Fraction& b);
    static Fraction Subtract(const Fraction& a, const Fraction& b);
    static Fraction Multiply(const Fraction& a, const Fraction& b);
};


