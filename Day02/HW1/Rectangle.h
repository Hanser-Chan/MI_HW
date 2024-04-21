//
// Created by JJC on 2024/4/21.
//
#ifndef HW1_RECTANGLE_H
#define HW1_RECTANGLE_H

#include <iostream>
#include <vector>
#include <utility>

class rPoint{
public:
    explicit rPoint(const std::pair<double, double> &coordinate);

    [[nodiscard]]const std::pair<double, double> &getCoordinate() const;

    void setCoordinate(const std::pair<double, double> &coordinate);


private:
    std::pair<double,double> coordinate;
};

class Rectangle{
public:
    Rectangle(rPoint &rPoint1, rPoint &rPoint2,
              rPoint &rPoint3, rPoint &rPoint4);

    [[nodiscard]]const rPoint &getRPoint1() const;

    void setRPoint1(const rPoint &rPoint1);

    [[nodiscard]]const rPoint &getRPoint2() const;

    void setRPoint2(const rPoint &rPoint2);

    [[nodiscard]]const rPoint &getRPoint3() const;

    void setRPoint3(const rPoint &rPoint3);

    [[nodiscard]]const rPoint &getRPoint4() const;

    void setRPoint4(const rPoint &rPoint4);

    double sideLen(const rPoint& rPoint11, const rPoint& rPoint22);

    double area(const Rectangle& rectangle);

private:
    rPoint rPoint1;
    rPoint rPoint2;
    rPoint rPoint3;
    rPoint rPoint4;
};

bool isRectangle(const rPoint& rPoint1, const rPoint& rPoint2,
                 const rPoint& rPoint3, const rPoint& rPoint4);
#endif //HW1_RECTANGLE_H
