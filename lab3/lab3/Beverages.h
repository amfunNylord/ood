#pragma once
#include <iostream>
#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string& description)
		: m_description(description)
	{
	}

	std::string GetDescription() const override
	{
		return m_description;
	}

private:
	std::string m_description;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		: CBeverage(description)
	{
	}

	double GetCost() const override
	{
		return 60;
	}
};

enum class CappuccinoPortion
{
	Standard,
	Double
};
// строковое описание порции сделать, переименовать cappuccinotype
// Капуччино
class CCappuccino : public CCoffee
{
public:
	CCappuccino(CappuccinoPortion cappuccinoPortion, const std::string& cappuccino = "Cappuccino")
		: CCoffee(cappuccino)
		, m_cappuccinoPortion(cappuccinoPortion)
	{
	}

	double GetCost() const override
	{
		switch (m_cappuccinoPortion)
		{
		case CappuccinoPortion::Standard:
			return 80;
		case CappuccinoPortion::Double:
			return 120;
		default:
			throw std::invalid_argument("Invalid cappuccino portion");
		}
	}

	std::string GetDescription() const override
	{
		switch (m_cappuccinoPortion)
		{
		case CappuccinoPortion::Standard:
			return CBeverage::GetDescription() + "Standard";
		case CappuccinoPortion::Double:
			return CBeverage::GetDescription() + "Double";
		default:
			throw std::invalid_argument("Invalid cappuccino portion");
		}
	}

private:
	CappuccinoPortion m_cappuccinoPortion;
};

enum class LattePortion
{
	Standard,
	Double
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(LattePortion lattePortion, const std::string& latte = "Latte")
		: CCoffee(latte)
		, m_lattePortion(lattePortion)
	{
	}

	double GetCost() const override
	{
		switch (m_lattePortion)
		{
		case LattePortion::Standard:
			return 90;
		case LattePortion::Double:
			return 130;
		default:
			throw std::invalid_argument("Invalid latte portion");
		}
	}

	std::string GetDescription() const override
	{
		switch (m_lattePortion)
		{
		case LattePortion::Standard:
			return CBeverage::GetDescription() + "Standard";
		case LattePortion::Double:
			return CBeverage::GetDescription() + "Double";
		default:
			throw std::invalid_argument("Invalid latte portion");
		}
	}

private:
	LattePortion m_lattePortion;
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(std::string teaType, const std::string& tea = "Tea")
		: CBeverage(tea) // const std::string &
		, m_teaType(teaType)
	{
	}

	double GetCost() const override
	{
		return 30;
	}
	
	std::string GetDescription() const override
	{
		return m_teaType + ' ' + CBeverage::GetDescription();
	}

private:
	std::string m_teaType;
};

enum class PortionSize
{
	Small,
	Medium,
	Large
};
// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(PortionSize portionSize, const std::string& milkshake = "Milkshake")
		: CBeverage(milkshake)
		, m_portionSize(portionSize)
	{
	}

	std::string GetDescription() const override
	{
		switch (m_portionSize)
		{
		case PortionSize::Small:
			return "Small " + CBeverage::GetDescription();
		case PortionSize::Medium:
			return "Medium " + CBeverage::GetDescription();
		case PortionSize::Large:
			return "Large " + CBeverage::GetDescription();
		default:
			throw std::invalid_argument("Invalid portion size");
		}
	}

	double GetCost() const override
	{
		switch (m_portionSize)
		{
		case PortionSize::Small:
			return 50;
		case PortionSize::Medium:
			return 60;
		case PortionSize::Large:
			return 80;
		default:
			throw std::invalid_argument("Invalid portion size");
		}
	}

private:
	PortionSize m_portionSize;
};
