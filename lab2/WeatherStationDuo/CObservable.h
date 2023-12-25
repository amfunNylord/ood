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
		/*for (const auto& observ : m_observers)
		{
			if (observ.second == &observer)
			{
				throw std::logic_error("Can't subscribe more than once");
			}
		}
		m_observers.insert(std::pair<int, ObserverType*>(priority, &observer));*/
		if (m_observers.find(&observer) != m_observers.end())
		{
			throw std::logic_error("Can't subscribe more than once");
		}
		m_observers[&observer] = priority;
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		/*auto copyObservers = m_observers;
		for (auto& observer : copyObservers)
		{
			observer.second->Update(data);
		}*/
		std::multimap<int, ObserverType*, std::greater<int>> sortedObservers;
		for (const auto& observer : m_observers)
		{
			sortedObservers.insert(std::make_pair(observer.second, observer.first));
		}
		for (const auto& observer : sortedObservers)
		{
			observer.second->Update(data, *this);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{

		/*std::multimap<int, ObserverType*, std::greater<int>> observersCopy;

		for (const auto& obs : m_observers)
		{
			if ((obs.second) != &observer)
			{
				observersCopy.insert(obs);
			}
		}

		std::swap(observersCopy, m_observers);*/

		m_observers.erase(&observer);
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	// добавить еще что-то map set чтобы скорость была быстрее чем линейная
	//std::multimap<int, ObserverType*, std::greater<int>> m_observers;
	std::unordered_map<ObserverType*, int> m_observers;
};
