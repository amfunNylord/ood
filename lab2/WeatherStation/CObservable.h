#pragma once
#include <map>
#include <iostream>
#include "IObservable.h"

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, const int priority = 0) override
	{
		// наблюдатель должен иметь возможность попдписаться не более 1 раза - done
		for (auto& observ : m_observers)
		{
			if (observ.second == &observer)
			{
				throw std::logic_error("Can't subscribe more than once");
			}
		}
		m_observers.insert(std::pair<int, ObserverType*>(priority, &observer));
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		std::multimap<int, ObserverType*, std::greater<int>> copyObservers = m_observers;
		for (auto& observer : copyObservers)
		{
			observer.second->Update(data);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{

		std::multimap<int, ObserverType*, std::greater<int>> observersCopy;

		for (const auto& obs : m_observers)
		{
			if ((obs.second) != &observer)
			{
				observersCopy.insert(obs);
			}
		}

		std::swap(observersCopy, m_observers);
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::multimap<int, ObserverType*, std::greater<int>> m_observers;
};
