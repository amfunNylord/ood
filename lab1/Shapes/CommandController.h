#pragma once
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <sstream>

#include "Shape.h"
#include "Picture.h"

class CommandController
{
public:
	CommandController(std::istream& input, std::ostream& output, shape::Picture& picture);
	bool HandleCommand();
	~CommandController();

private:
	bool AddShape(std::istream& args);
	bool List();
	bool DeleteShape(std::istream& args);
	bool ChangeColor(std::istream& args);
	bool ChangeShape(std::istream& args);
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;

	shape::Picture m_picture;
};
