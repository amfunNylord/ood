#pragma once
#include <map>
#include <set>
#include "IObservable.h"
#include <stdexcept>

// Реализация интерфейса IObservable
template <class T, typename Event>
class CObservable : public IObservable<T, Event>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, Event e) override
	{
		m_observers.emplace(e, &observer);
	}
	// поменять структуру notify event
	void NotifyObservers() override
	{
		T data = GetChangedData();
		auto events = GetCurrentEvents();
		auto observersCopy = m_observers;
		std::set<ObserverType*> updatedObservers;

		for (auto& [event, observer] : observersCopy)
		{
			if (events.contains(event) && !updatedObservers.contains(observer))
			{
				observer->Update(data);
				updatedObservers.insert(observer);
			}
		}
	}

	void RemoveObserver(ObserverType& observer, Event e) override
	{
		auto matchingObservers = m_observers.equal_range(e);
		for (auto it = matchingObservers.first; it != matchingObservers.second; ++it)
		{
			if (it->second == &observer)
			{
				m_observers.erase(it);
				break;
			}
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;
	virtual std::set<Event> GetCurrentEvents() const = 0;

private:
	std::multimap<Event, ObserverType*> m_observers;
};
