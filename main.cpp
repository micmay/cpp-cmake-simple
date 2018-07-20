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
  auto* m = malloc(4242);
  std::cout << "Hello World" << std::endl;
}
