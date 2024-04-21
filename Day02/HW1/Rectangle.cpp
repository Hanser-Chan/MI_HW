//
// Created by JJC on 2024/4/21.
//
//#include <iostream>
#include <cmath>
#include "Rectangle.h"

const std::pair<double, double> &rPoint::getCoordinate() const {
    return coordinate;
}

void rPoint::setCoordinate(const std::pair<double, double> &coordinate) {
    rPoint::coordinate = coordinate;
}

rPoint::rPoint(const std::pair<double, double> &coordinate) : coordinate(coordinate) {}

Rectangle::Rectangle(rPoint &rPoint1, rPoint &rPoint2, rPoint &rPoint3, rPoint &rPoint4)
        : rPoint1(std::move(rPoint1)), rPoint2(std::move(rPoint2)), rPoint3(std::move(rPoint3)), rPoint4(std::move(rPoint4)) {}

const rPoint &Rectangle::getRPoint1() const {
    return rPoint1;
}

void Rectangle::setRPoint1(const rPoint &rPoint1) {
    Rectangle::rPoint1 = rPoint1;
}

const rPoint &Rectangle::getRPoint2() const {
    return rPoint2;
}

void Rectangle::setRPoint2(const rPoint &rPoint2) {
    Rectangle::rPoint2 = rPoint2;
}

const rPoint &Rectangle::getRPoint3() const {
    return rPoint3;
}

void Rectangle::setRPoint3(const rPoint &rPoint3) {
    Rectangle::rPoint3 = rPoint3;
}

const rPoint &Rectangle::getRPoint4() const {
    return rPoint4;
}

void Rectangle::setRPoint4(const rPoint &rPoint4) {
    Rectangle::rPoint4 = rPoint4;
}


double sideLen(const rPoint& rPoint11, const rPoint& rPoint22){
    double x1{rPoint11.getCoordinate().first},x2{rPoint22.getCoordinate().first};
    double y1{rPoint11.getCoordinate().second},y2{rPoint22.getCoordinate().second};
    double sideL = sqrt(( pow(x1-x2,2) ) + (pow(y1-y2,2) ));
    return sideL;
}

double area(const Rectangle& rectangle){
    double l1{sideLen(rectangle.getRPoint1(),rectangle.getRPoint2())};
    double l2{sideLen(rectangle.getRPoint2(),rectangle.getRPoint3())};
    //double l3{sideLen(rPoint1,rPoint4)};
    //double l4{sideLen(rPoint3,rPoint4)};
    return l1*l2;
}


bool isRectangle(const rPoint& rPoint1, const rPoint& rPoint2,
                 const rPoint& rPoint3, const rPoint& rPoint4){
    double l1{sideLen(rPoint1,rPoint3)};
    double l2{sideLen(rPoint2,rPoint4)};
    if (l1 == l2) return true;

    return false;
}