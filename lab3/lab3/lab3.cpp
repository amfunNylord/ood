#include "Beverages.h"
#include "Condiments.h"

#include <functional>
#include <iostream>
#include <string>

using namespace std;

/*
�������������� ������, ��������� �������� �������
*/
struct MakeLemon
{
	MakeLemon(unsigned quantity)
		: m_quantity(quantity)
	{
	}

	auto operator()(IBeveragePtr&& beverage) const
	{
		return make_unique<CLemon>(move(beverage), m_quantity);
	}

private:
	unsigned m_quantity;
};

/*
�������, ������������ �������, ��������� �������� �������
*/
function<IBeveragePtr(IBeveragePtr&&)> MakeCinnamon()
{
	return [](IBeveragePtr&& b) {
		return make_unique<CCinnamon>(move(b));
	};
}

/*
���������� �������, ������������ ������� ������������ ��������

��������� �������:
	Condiment - ����� �������, ����������� �������� � �������� ������� ���������
				��������� IBeveragePtr&& �������������� �������
	Args - ������ ����� ������ ���������� ������������ (��������, ������)
*/
template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&... args)
{
	// ���������� �������, ������������ �������, ���������� �� � �������� ���������
	// �������������� ��������� ����������, ����������� ������-��������, ����������
	// ������������ ���������� ����� make_unique
	return [=](auto&& b) {
		// ������� make_unique �������� b ������ �� ������� ���������� ������� �������
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

/*
������������� ������ ��������� <<, ������� ������������� ��� �������������� �����
��� ������������� ����������

��������� ������� ������� ������������� ������� ����������� ��������� �������:
auto beverage = make_unique<CConcreteBeverage>(a, b, c)
					<< MakeCondimentA(d, e, f)
					<< MakeCondimentB(g, h);

�������������� ������� MakeCondiment* ���������� ���������, ����������� ��� ��������
����������, � ���������� ��������� �������, ����������� ������������� �������, �������
��� ����� ������ ������� ������ ������ Condiment, ������� ��� ����������� ���������.
�������������:
	auto beverage =
		make_unique<CConcreteBeverage>(a, b, c)
		<< MakeCondimentA(d, e, f)
		<< MakeCondimentB(g, h);
��� ���� ���:
	auto beverage =
		make_unique<CConcreteBeverage>
		<< MakeCondiment<CondimentA>(d, e, f)
		<< MakeCondiment<CondimentB>(g, h);
� ��������� ������ ��� ������������� ������ ������� ���������� MakeCondimentA � MakeCondimentB, �.�.
����������� ���������� ����������� ����������

������������ ������ ������������ �������� �� ���:
	auto baseBeverage = make_unique<CConcretedBeverage>(a, b, c);
	auto wrappedWithCondimentA = make_unique<CCondimentA>(move(baseBeverage), d, e, f);
	auto beverage = make_unique<CCondimentB>(move(wrappedWithCondimentA), g, h);
���� ���:
	auto beverage = make_unique<CCondimentB>(
						make_unique<CCondimentA>(
							make_unique<CConcreteBeverage>(a, b, c), // �������
							d, e, f	// ���. �������� CondimentA
						),
						g, h		// ���. ��������� CondimentB
					);

unique_ptr<CLemon> operator << (IBeveragePtr && lhs, const MakeLemon & factory)
{
	return factory(move(lhs));
}
unique_ptr<CCinnamon> operator << (IBeveragePtr && lhs, const MakeCinnamon & factory)
{
	return factory(move(lhs));
}
*/
template <typename Component, typename Decorator>
auto operator<<(Component&& component, const Decorator& decorate)
{
	return decorate(forward<Component>(component));
}

void DialogWithUser()
{
	cout << "Type 1 for coffee, 2 for tea or 3 for milkshake" << std::endl;
	int beverageChoice;
	cin >> beverageChoice;

	unique_ptr<IBeverage> beverage;

	if (beverageChoice == 1)
	{
		cout << "Type 1 for cappuccino or 2 for latte" << std::endl;
		int coffeChoice;
		cin >> coffeChoice;

		switch (coffeChoice)
		{
		case 1:
			cout << "Type 1 for standard or 2 for double" << std::endl;
			int cappuccinoChoice;
			cin >> cappuccinoChoice;
			switch (cappuccinoChoice)
			{
			case 1:
				beverage = make_unique<CCappuccino>(CappuccinoType::Standard);
				break;
			case 2:
				beverage = make_unique<CCappuccino>(CappuccinoType::Double);
				break;
			default:
				throw std::invalid_argument("Invalid cappuccino type");
			}
			break;
		case 2:
			cout << "Type 1 for standard or 2 for double" << std::endl;
			int latteChoice;
			cin >> latteChoice;
			switch (latteChoice)
			{
			case 1:
				beverage = make_unique<CLatte>(LatteType::Standard);
				break;
			case 2:
				beverage = make_unique<CLatte>(LatteType::Double);
				break;
			default:
				throw std::invalid_argument("Invalid latte type");
			}
			break;
		default:
			throw std::invalid_argument("Invalid coffe choice");
		}
	}
	else if (beverageChoice == 2)
	{
		cout << "Type 1 for green, 2 for yellow, 3 for white or 4 for black" << std::endl;
		int teaChoice;
		cin >> teaChoice;

		switch (teaChoice)
		{
		case 1:
			beverage = make_unique<CTea>("Green");
			break;
		case 2:
			beverage = make_unique<CTea>("Yellow");
			break;
		case 3:
			beverage = make_unique<CTea>("White");
			break;
		case 4: 
			beverage = make_unique<CTea>("Black");
			break;
		default:
			throw std::invalid_argument("Invalid tea sort");
		}
	}
	else if (beverageChoice == 3)
	{
		cout << "Type 1 for small, 2 for medium or 3 for large" << std::endl;

		int milkshakeChoice;
		cin >> milkshakeChoice;

		switch (milkshakeChoice)
		{
		case 1:
			beverage = make_unique<CMilkshake>(PortionSize::Small);
			break;
		case 2:
			beverage = make_unique<CMilkshake>(PortionSize::Medium);
			break;
		case 3:
			beverage = make_unique<CMilkshake>(PortionSize::Large);
			break;
		default:
			throw std::invalid_argument("Invalid size of portion");
		}
	}
	else
	{
		throw std::invalid_argument("Invalid beverage choice");
	}

	int condimentChoice;
	for (;;)
	{
		cout << "1 - Lemon, 2 - Cinnamon, 3 - Cream, 4 - Chocolate, 5 - Liquor, 0 - Checkout" << endl;
		cin >> condimentChoice;

		if (condimentChoice == 1)
		{
			// beverage = make_unique<CLemon>(move(beverage));
			beverage = move(beverage) << MakeCondiment<CLemon>(2);
		}
		else if (condimentChoice == 2)
		{
			// beverage = make_unique<CCinnamon>(move(beverage));
			beverage = move(beverage) << MakeCondiment<CCinnamon>();
		}
		else if (condimentChoice == 3)
		{
			beverage = make_unique<CCream>(move(beverage));
		}
		else if (condimentChoice == 4)
		{
			cout << "Type count of slice(max only 5)" << endl;
			int sliceCount;
			cin >> sliceCount;
			beverage = make_unique<CChocolate>(move(beverage), sliceCount);
		}
		else if (condimentChoice == 5)
		{
			cout << "Type 1 for nutty or 2 for chocolate" << endl;
			int liquorType;
			cin >> liquorType;

			switch (liquorType)
			{
			case 1:
				beverage = make_unique<CLiquor>(move(beverage), LiquorType::Nutty);
				break;
			case 2:
				beverage = make_unique<CLiquor>(move(beverage), LiquorType::Chocolate);
				break;
			default:
				throw std::invalid_argument("Invalid liquor type");
			}
		}
		else if (condimentChoice == 0)
		{
			break;
		}
		else
		{
			return;
		}
	}

	cout << beverage->GetDescription() << ", cost: " << beverage->GetCost() << endl;
}

int main()
{
	DialogWithUser();
	//cout << endl;
	//{
	//	// �������� ������� �����
	//	auto latte = make_unique<CLatte>();
	//	// ��������� ������
	//	auto cinnamon = make_unique<CCinnamon>(move(latte));
	//	// ��������� ���� ����� ������
	//	auto lemon = make_unique<CLemon>(move(cinnamon), 2);
	//	// ��������� ���� ������� ����
	//	auto iceCubes = make_unique<CIceCubes>(move(lemon), 2, IceCubeType::Dry);
	//	// ��������� 2 ������ ���������� ������
	//	auto beverage = make_unique<CChocolateCrumbs>(move(iceCubes), 2);

	//	// ���������� ���� ����������
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}

	//{
	//	auto beverage = make_unique<CChocolateCrumbs>( // ������� ����: ���������� ������
	//		make_unique<CIceCubes>( // | ��� ��� - ������ ����
	//			make_unique<CLemon>( // | | ��� ���� �����
	//				make_unique<CCinnamon>( // | | | ����� ���� - ������
	//					make_unique<CLatte>()), // | | |   � ����� ������ - �����
	//				2), // | | 2 ������ ������
	//			2, IceCubeType::Dry), // | 2 ������ ������ ����
	//		2); // 2 ������ ���������� ������

	//	// ���������� ���� ����������
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}

	//// ��������� ���������� ������ MakeCondiment � ��������� <<
	//{
	//	// lemon - �������, ����������� "2 ������ ������" � ������ �������
	//	auto lemon2 = MakeCondiment<CLemon>(2);
	//	// iceCubes - �������, ����������� "3 ������� ����" � ������ �������
	//	auto iceCubes3 = MakeCondiment<CIceCubes>(3, IceCubeType::Water);

	//	auto tea = make_unique<CTea>();

	//	// ���������� ��� ����� �������� ������ � ����� ��������� ����
	//	auto lemonIceTea = iceCubes3(lemon2(move(tea)));
	//	/* ���������� ������ ��������� �� �� ��������, ��� � ��������� ���:
	//	auto lemonIceTea =
	//		make_unique<CIceCubes>(
	//			make_unique<CLemon>(
	//				move(tea),
	//				2),
	//			2, IceCubeType::Water);
	//	*/

	//	auto oneMoreLemonIceTea = make_unique<CTea>() // ����� ���
	//		<< MakeCondiment<CLemon>(2) // ��������� ���� ����� ������
	//		<< MakeCondiment<CIceCubes>(3, IceCubeType::Water); // � 3 ������ ����
	//	/*
	//	���������� ����������� ������ �� �� �����, ��� � ���������:
	//	auto oneMoreLemonIceTea =
	//		MakeCondiment<CIceCubes>(3, IceCubeType::Water)(
	//			MakeCondiment<CLemon>(2)(make_unique<CTea>())
	//			);
	//	*/
	//}

	//// ������ ����������� ������� � �������� ��������������� ������
	//// ��������������� ����������� << � �������� MakeCondiment
	//{
	//	auto beverage = make_unique<CLatte>() // �������� ������� �����,
	//		<< MakeCondiment<CCinnamon>() // ����������� �������,
	//		<< MakeCondiment<CLemon>(2) // ��������� ���� ����� ������
	//		<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry) // ������� ���� ������� ������ ����
	//		<< MakeCondiment<CChocolateCrumbs>(2); // �������� ���������� �������

	//	// ���������� ���� ����������
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}

	//{
	//	auto beverage = make_unique<CMilkshake>() // �������� �������� ��������
	//		<< MakeCondiment<CSyrup>(SyrupType::Maple) // �������� �������� �������
	//		<< MakeCondiment<CCoconutFlakes>(8); // �������� ��������� ��������

	//	// ���������� ���� ����������
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}
}
