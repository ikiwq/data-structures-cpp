#include "vector.h"
#include "stack.h"
#include <iostream>

int main(int argc, char* argv[]) {
	skl::stack<int> stack1;
	stack1.push(5);
	stack1.push(15);
	stack1.pop();
	std::cout << stack1.peek();
	return 0;
}