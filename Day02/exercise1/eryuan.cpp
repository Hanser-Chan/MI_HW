#include <iostream>
#include <cmath>
#include <complex>

void solveQuadratic(double a, double b, double c)
{
    double discriminant = b * b - 4 * a * c;
    double realPart = -b / (2 * a);

    if (discriminant > 0)
    {
        // 两个实根
        double sqrtDisc = sqrt(discriminant);
        double root1 = (realPart + sqrtDisc);
        double root2 = (realPart - sqrtDisc);
        // std::cout << "Roots are real and different." << std::endl;
        std::cout << "Root 1 = " << root1 << std::endl;
        std::cout << "Root 2 = " << root2 << std::endl;
    }
    else if (discriminant == 0)
    {
        // 一个实根
        // std::cout << "Roots are real and the same." << std::endl;
        std::cout << "Root 1 = Root 2 = " << realPart << std::endl;
    }
    else
    {
        // 复根
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        // std::cout << "Roots are complex." << std::endl;
        std::cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

int main()
{
    double a, b, c;
    std::cout << "请输入系数 a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0)
    {
        std::cout << "这不是一元二次方程" << std::endl;
        return 1; // 非一元二次方程
    }

    solveQuadratic(a, b, c);
    return 0;
}
