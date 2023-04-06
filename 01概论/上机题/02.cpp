#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex() : real(0), imag(0) {}                   // 默认构造函数
    Complex(double r) : real(r), imag(0) {}           // 构造函数，实部为r，虚部为0
    Complex(double r, double i) : real(r), imag(i) {} // 构造函数，实部为r，虚部为i
    double getReal() { return real; }                 // 获取实部
    double getImag() { return imag; }                 // 获取虚部
    void setReal(double r) { real = r; }              // 修改实部
    void setImag(double i) { imag = i; }              // 修改虚部
    Complex operator+(const Complex &c)
    { // 重载加法运算
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    Complex operator-(const Complex &c)
    { // 重载减法运算
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    Complex operator*(const Complex &c)
    { // 重载乘法运算
        Complex temp;
        temp.real = real * c.real - imag * c.imag;
        temp.imag = real * c.imag + imag * c.real;
        return temp;
    }
    Complex operator/(const Complex &c)
    { // 重载除法运算
        Complex temp;
        double denominator = c.real * c.real + c.imag * c.imag;
        temp.real = (real * c.real + imag * c.imag) / denominator;
        temp.imag = (imag * c.real - real * c.imag) / denominator;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const Complex &c)
    { // 重载输出运算
        os << c.real << "+" << c.imag << "i";
        return os;
    }
};

int main()
{
    Complex c1;
    Complex c2(2.3);
    Complex c3(4.5, 6.7);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;
    c1.setReal(1.2);
    c1.setImag(3.4);
    cout << "c1: " << c1 << endl;
    Complex c4 = c2 + c3;
    cout << "c4 = c2 + c3: " << c4 << endl;
    Complex c5 = c3 - c2;
    cout << "c5 = c3 - c2: " << c5 << endl;
    Complex c6 = c2 * c3;
    cout << "c6 = c2 * c3: " << c6 << endl;
    Complex c7 = c3 / c2;
    cout << "c7 = c3 / c2: " << c7 << endl;
    return 0;
}
