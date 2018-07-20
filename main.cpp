#include <iostream>

class foo {
 private:
  // CppCheck will find it
  int m_notInitialized;

 public:
  foo() {}
};

int main(void) {
  auto b = foo();
  std::cout << "Hello World" << std::endl;
}
