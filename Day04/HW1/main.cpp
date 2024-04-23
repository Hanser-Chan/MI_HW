#include <iostream>
#include <string>
#include <utility>
#include <format>

using std::string,std::cout,std::format;

class Phone{
public:
    Phone(string mName, int age) : m_name(std::move(mName)), m_age(age) {}

    [[nodiscard]] const string &getName() const { return m_name; }

    void setMName(const string &mName) { m_name = mName; }

    [[nodiscard]] int getAge() const { return m_age; }

    void setAge(int age) { m_age = age; }

private:
    string m_name;
    int m_age;
};




template <typename T>
void cSwap(T &a, T &b){//全部使用move，避免所有复制
    T temp { std::move(a) };
    a = std::move(b);
    b = std::move(temp);
}



int main() {
    double a{10},b{20};
    string s1{"abc"},s2{"I love Xiaomi"};

    Phone p1("友商",40);
    Phone p2("小米",14);

    cout << format("a={},b={},交换后的值为：",a,b);
    cSwap(a,b);
    cout << a << "," << b << std::endl;

    cout << format("\ns1={},s2={},交换后的值为：",s1,s2);
    cSwap(s1,s2);
    cout << s1 << ", " << s2 << std::endl;

    cout << format("\n手机厂商有两个：{} 和 {} ,让我们大声说：",p1.getName(),p2.getName());
    cSwap(p1,p2);
    cout << format("{} 万岁, {} 是**(bushi),我们要感谢 {} ，一枝独放不是春，百花齐放春满园\n",
                   p1.getName(),p2.getName(),p2.getName());

}
