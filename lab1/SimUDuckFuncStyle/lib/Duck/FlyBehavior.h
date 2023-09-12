#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

#include <functional>
#include <iostream>

using FlyBehavior = std::function<void()>;

FlyBehavior flyWithWings = [countOfFlies = 0]() mutable {
	std::cout << "I'm flying with wings!!" << std::endl;
	countOfFlies++;
	std::cout << "My flight number is " << countOfFlies << std::endl;
};

FlyBehavior flyNoWay = []() {};

#endif
