#ifndef QUAKBEHAVIOR_H
#define QUAKBEHAVIOR_H

#include <iostream>
#include <functional>

using QuackBehavior = std::function<void()>;

QuackBehavior muteQuackBehavior = []() {};

QuackBehavior quackBehavior = []() {
	std::cout << "Quack Quack!!!" << std::endl;
};

QuackBehavior squeakBehavior = []() {
	std::cout << "Squeek!!!" << std::endl;
};

#endif