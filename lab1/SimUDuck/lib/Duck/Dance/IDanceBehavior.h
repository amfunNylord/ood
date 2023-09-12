#ifndef IDANCEBEHAVIOR_H
#define IDANCEBEHAVIOR_H

// Повторить, для чего нужен виртуальный деструктоор и уметь рассказать
// Использоваьт класс вместо структуры для интерфейс.
// Должен ли метод Dance быть константным? Обосновать свой ответ.
struct IDanceBehavior
{
	virtual void Dance() = 0;
	virtual ~IDanceBehavior() {}
};

#endif