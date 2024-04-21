# 实现思路

## 设置类

### rPoint 类

- 属性
  - `coordinate`：私有属性，类型为 `std::pair<double, double>`，存储点的坐标。
- 方法
  - `rPoint(const std::pair<double, double> &coordinate)`：构造函数，使用坐标对进行初始化。
  - `getCoordinate() const`：公有方法，返回坐标对的常量引用。
  - `setCoordinate(const std::pair<double, double> &coordinate)`：公有方法，设置坐标对。

```cpp
class rPoint{
public:
    explicit rPoint(const std::pair<double, double> &coordinate);

    [[nodiscard]]const std::pair<double, double> &getCoordinate() const;

    void setCoordinate(const std::pair<double, double> &coordinate);


private:
    std::pair<double,double> coordinate;
};
```

### Rectangle 类

- 属性
  - `rPoint1`, `rPoint2`, `rPoint3`, `rPoint4`：私有属性，每个属性都是一个 `rPoint` 对象，代表矩形的四个顶点。
- 方法
  - `Rectangle(rPoint &rPoint1, rPoint &rPoint2, rPoint &rPoint3, rPoint &rPoint4)`：构造函数，初始化矩形的四个顶点。
  - `getRPoint1() const`、`getRPoint2() const`、`getRPoint3() const`、`getRPoint4() const`：公有方法，返回四个顶点的引用。
  - `setRPoint1(const rPoint &rPoint1)`、`setRPoint2(const rPoint &rPoint2)`、`setRPoint3(const rPoint &rPoint3)`、`setRPoint4(const rPoint &rPoint4)`：公有方法，设置四个顶点。
  - `sideLen(const rPoint& rPoint1, const rPoint& rPoint2)`：公有方法，计算两个点之间的距离。
  - `area(const Rectangle& rectangle)`：公有方法，计算矩形的面积。

```cpp
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
```

### 类之间的关系

- `Rectangle` 类**依赖**于 `rPoint` 类。矩形由四个 `rPoint` 类型的点组成。这表现为 `Rectangle` 类包含四个 `rPoint` 类的实例作为其属性。

![uml.png](https://img2.imgtp.com/2024/04/21/1IUr8meu.png)

## 算法构成

### **确认点构成矩形**：

检查对角线是否相等且是否相交于中点：

- 对角线 \( AC \) 和 \( BD \) 的长度分别为：
  $AC = \sqrt{(x_3 - x_1)^2 + (y_3 - y_1)^2}, \quad BD = \sqrt{(x_4 - x_2)^2 + (y_4 - y_2)^2}$
- 验证 \( AC = BD \)。

```cpp
bool isRectangle(const rPoint& rPoint1, const rPoint& rPoint2,
                 const rPoint& rPoint3, const rPoint& rPoint4){
    double l1{sideLen(rPoint1,rPoint3)};
    double l2{sideLen(rPoint2,rPoint4)};
    if (l1 == l2) return true;

    return false;
}
```



### 计算面积：
假设四个点的坐标为$  (x_1, y_1), (x_2, y_2), (x_3, y_3), (x_4, y_4) $：
**步骤 1**：计算边长。

- $AB = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$
- $BC = \sqrt{(x_3 - x_2)^2 + (y_3 - y_2)^2}$


**步骤 2**：选择两组相邻的边（例如 \( AB \) 和 \( BC \)），并计算面积。

- **面积**$ = AB \times BC$

```cpp
double Rectangle::area(const Rectangle& rectangle){
    double l1{sideLen(rectangle.getRPoint1(),rectangle.getRPoint2())};
    double l2{sideLen(rectangle.getRPoint2(),rectangle.getRPoint3())};
    //double l3{sideLen(rPoint1,rPoint4)};
    //double l4{sideLen(rPoint3,rPoint4)};
    return l1*l2;
}
```

