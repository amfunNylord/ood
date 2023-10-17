#include "Beverages.h"
#include "Condiments.h"

#include <functional>
#include <iostream>
#include <string>

using namespace std;

/*
Функциональный объект, создающий лимонную добавку
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
Функция, возвращающая функцию, создающую коричную добавку
*/
function<IBeveragePtr(IBeveragePtr&&)> MakeCinnamon()
{
	return [](IBeveragePtr&& b) {
		return make_unique<CCinnamon>(move(b));
	};
}

/*
Возвращает функцию, декорирующую напиток определенной добавкой

Параметры шаблона:
	Condiment - класс добавки, конструктор которого в качестве первого аргумента
				принимает IBeveragePtr&& оборачиваемого напитка
	Args - список типов прочих параметров конструктора (возможно, пустой)
*/
template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&... args)
{
	// Возвращаем функцию, декорирующую напиток, переданный ей в качестве аргумента
	// Дополнительные аргументы декоратора, захваченные лямбда-функцией, передаются
	// конструктору декоратора через make_unique
	return [=](auto&& b) {
		// Функции make_unique передаем b вместе со списком аргументов внешней функции
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

/*
Перегруженная версия оператора <<, которая предоставляет нам синтаксический сахар
для декорирования компонента

Позволяет создать цепочку оборачивающих напиток декораторов следующим образом:
auto beverage = make_unique<CConcreteBeverage>(a, b, c)
					<< MakeCondimentA(d, e, f)
					<< MakeCondimentB(g, h);

Функциональные объекты MakeCondiment* запоминают аргументы, необходимые для создания
дополнения, и возвращают фабричную функцию, принимающую оборачиваемый напиток, которая
при своем вызове создаст нужный объект Condiment, передав ему запомненные аргументы.
Использование:
	auto beverage =
		make_unique<CConcreteBeverage>(a, b, c)
		<< MakeCondimentA(d, e, f)
		<< MakeCondimentB(g, h);
или даже так:
	auto beverage =
		make_unique<CConcreteBeverage>
		<< MakeCondiment<CondimentA>(d, e, f)
		<< MakeCondiment<CondimentB>(g, h);
В последнем случае нет необходимости писать вручную реализации MakeCondimentA и MakeCondimentB, т.к.
необходимую реализацию сгенерирует компилятор

Классический способ оборачивания выглядел бы так:
	auto baseBeverage = make_unique<CConcretedBeverage>(a, b, c);
	auto wrappedWithCondimentA = make_unique<CCondimentA>(move(baseBeverage), d, e, f);
	auto beverage = make_unique<CCondimentB>(move(wrappedWithCondimentA), g, h);
либо так:
	auto beverage = make_unique<CCondimentB>(
						make_unique<CCondimentA>(
							make_unique<CConcreteBeverage>(a, b, c), // Напиток
							d, e, f	// доп. параметы CondimentA
						),
						g, h		// доп. параметры CondimentB
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
	//	// Наливаем чашечку латте
	//	auto latte = make_unique<CLatte>();
	//	// добавляем корицы
	//	auto cinnamon = make_unique<CCinnamon>(move(latte));
	//	// добавляем пару долек лимона
	//	auto lemon = make_unique<CLemon>(move(cinnamon), 2);
	//	// добавляем пару кубиков льда
	//	auto iceCubes = make_unique<CIceCubes>(move(lemon), 2, IceCubeType::Dry);
	//	// добавляем 2 грамма шоколадной крошки
	//	auto beverage = make_unique<CChocolateCrumbs>(move(iceCubes), 2);

	//	// Выписываем счет покупателю
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}

	//{
	//	auto beverage = make_unique<CChocolateCrumbs>( // Внешний слой: шоколадная крошка
	//		make_unique<CIceCubes>( // | под нею - кубики льда
	//			make_unique<CLemon>( // | | еще ниже лимон
	//				make_unique<CCinnamon>( // | | | слоем ниже - корица
	//					make_unique<CLatte>()), // | | |   в самом сердце - Латте
	//				2), // | | 2 дольки лимона
	//			2, IceCubeType::Dry), // | 2 кубика сухого льда
	//		2); // 2 грамма шоколадной крошки

	//	// Выписываем счет покупателю
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}

	//// Подробнее рассмотрим работу MakeCondiment и оператора <<
	//{
	//	// lemon - функция, добавляющая "2 дольки лимона" к любому напитку
	//	auto lemon2 = MakeCondiment<CLemon>(2);
	//	// iceCubes - функция, добавляющая "3 кусочка льда" к любому напитку
	//	auto iceCubes3 = MakeCondiment<CIceCubes>(3, IceCubeType::Water);

	//	auto tea = make_unique<CTea>();

	//	// декорируем чай двумя дольками лимона и тремя кусочками льда
	//	auto lemonIceTea = iceCubes3(lemon2(move(tea)));
	//	/* Предыдущая строка выполняет те же действия, что и следующий код:
	//	auto lemonIceTea =
	//		make_unique<CIceCubes>(
	//			make_unique<CLemon>(
	//				move(tea),
	//				2),
	//			2, IceCubeType::Water);
	//	*/

	//	auto oneMoreLemonIceTea = make_unique<CTea>() // Берем чай
	//		<< MakeCondiment<CLemon>(2) // добавляем пару долек лимона
	//		<< MakeCondiment<CIceCubes>(3, IceCubeType::Water); // и 3 кубика льда
	//	/*
	//	Предыдущая конструкция делает то же самое, что и следующая:
	//	auto oneMoreLemonIceTea =
	//		MakeCondiment<CIceCubes>(3, IceCubeType::Water)(
	//			MakeCondiment<CLemon>(2)(make_unique<CTea>())
	//			);
	//	*/
	//}

	//// Аналог предыдущего решения с добавкой синтаксического сахара
	//// обеспечиваемого операторами << и функцией MakeCondiment
	//{
	//	auto beverage = make_unique<CLatte>() // Наливаем чашечку латте,
	//		<< MakeCondiment<CCinnamon>() // оборачиваем корицей,
	//		<< MakeCondiment<CLemon>(2) // добавляем пару долек лимона
	//		<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry) // брасаем пару кубиков сухого льда
	//		<< MakeCondiment<CChocolateCrumbs>(2); // посыпаем шоколадной крошкой

	//	// Выписываем счет покупателю
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}

	//{
	//	auto beverage = make_unique<CMilkshake>() // Наливаем молочный коктейль
	//		<< MakeCondiment<CSyrup>(SyrupType::Maple) // заливаем кленовым сиропом
	//		<< MakeCondiment<CCoconutFlakes>(8); // посыпаем кокосовой стружкой

	//	// Выписываем счет покупателю
	//	cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	//}
}
