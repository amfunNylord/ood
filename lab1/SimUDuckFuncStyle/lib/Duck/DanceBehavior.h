#ifndef DANCEBEHAVIOR_H
#define DANCEBEHAVIOR_H

#include <functional>
#include <iostream>

using DanceBehavior = std::function<void()>;

DanceBehavior danceNoWayBehavior = []() {};

DanceBehavior danceMinuetBehavior = []() {
	std::cout << "I am dancing minuet" << std::endl;
};

DanceBehavior danceWaltzBehavior = []() {
	std::cout << "I am dancing waltz" << std::endl;
};

#endif