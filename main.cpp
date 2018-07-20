#include <iostream>

class foo {
    private:
    int m_notInitialized;
public:
    foo() {

    }
};

int main(void)
{
auto b = foo();
std::cout << "Hello World" << std::endl;
}
