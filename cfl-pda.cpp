#include <iostream>
#include <string>
#include <stack>


int main() {
	std::string input;
	std::stack<char> s;
	std::cout << "Enter your string: ";
	std::cin >> input;
	enum State {
		q0,
		q1,
		qFail = -1
	};
	State currentState = q0;
	for (std::string::size_type i = 0; i < input.length(); i++) {
		switch (currentState) {
			case q0:
				if (input[i] == 'a') {
					s.push('a');
					currentState = q0;
				} else if (input[i] == 'b') {
					if (s.empty() == true) {
						std::cout << "The stack is empty, not enough a's" << std::endl;
						currentState = qFail;
					} else {
						s.pop();
						currentState = q1;	
					}
				} else {
					std::cout << "Invalid character read" << std::endl;
					currentState = qFail;
				}
				break;


			case q1:
				if (input[i] == 'b') {
					if (s.empty() == true) {
						std::cout << "The stack is empty, not enough a's" << std::endl;
						currentState = qFail;
					} else {
						s.pop();
						currentState = q1;
					}
				} else {
					if (input[i] == 'a') {
						std::cout << "Cannot have a's after b's" << std::endl;
					} else {
						std::cout << "Invalid character read" << std::endl;
					}
					currentState = qFail;
				}

				break;
			
			case qFail:
				return 1;
		}
	}
	if (currentState == qFail) {
		return 1;
	}
	if (currentState == q1 && s.empty() == true) {
		std::cout << "The string is accepted" << std::endl;
		return 0;
	}
	std::cout << "The stack is not empty, there are not enough b's" << std::endl;
	return 2;
}
