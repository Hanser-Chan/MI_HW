#include <iostream>
#include <format>
#include <string>
#include "Rectangle.h"

int main() {

    rPoint rPoint1(std::pair<double,double> (1,1) );
    rPoint rPoint2(std::pair<double,double> (1,4) );
    rPoint rPoint3(std::pair<double,double> (5,4) );
    rPoint rPoint4(std::pair<double,double> (5,1) );

    if (isRectangle(rPoint1,rPoint2,rPoint3,rPoint4)){
        Rectangle rectangle(rPoint1,rPoint2,rPoint3,rPoint4);
        double x1{rPoint1.getCoordinate().first},y1{rPoint1.getCoordinate().second};
        double x2{rPoint2.getCoordinate().first},y2{rPoint2.getCoordinate().second};
        double x3{rPoint3.getCoordinate().first},y3{rPoint3.getCoordinate().second};
        double x4{rPoint4.getCoordinate().first},y4{rPoint4.getCoordinate().second};

        std::cout << std::format("该矩形坐标为({},{})({},{})({},{})({},{})\n",
                                 x1,y1,x2,y2,x3,y3,x4,y4)
                  << std::format("该矩形面积为{}\n", rectangle.area(rectangle));
    }else {
        std::cout << "这四个点不能围成矩形\n" ;
    }

    return 0;
}
