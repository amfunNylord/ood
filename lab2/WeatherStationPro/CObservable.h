#pragma once
#include <map>
#include <iostream>
#include <unordered_map>
#include "IObservable.h"

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, const int priority = 0) override
	{
		if (m_observers.find(&observer) != m_observers.end())
		{
			throw std::logic_error("Can't subscribe more than once");
		}
		m_observers[&observer] = priority;
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		std::multimap<int, ObserverType*, std::greater<int>> sortedObservers;
		for (const auto& observer : m_observers)
		{
			sortedObservers.insert(std::make_pair(observer.second, observer.first));
		}
		for (const auto& observer : sortedObservers)
		{
			observer.second->Update(data);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		m_observers.erase(&observer);
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::unordered_map<ObserverType*, int> m_observers;
};
