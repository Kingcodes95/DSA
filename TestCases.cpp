#include <iostream>
#include <cassert>

int add(int x, int y) {
    return x + y;
}
void testAdd() {
    assert(add(10, 20) == 30);
    assert(add(15, 15) == 30);
    assert(add(200, 150) == 350);
    std::cout << "All tests Passed" << std::endl;
}
int main() {

    testAdd();

    return 0;
}