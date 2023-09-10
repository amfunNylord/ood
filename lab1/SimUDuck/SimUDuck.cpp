#include <iostream>
#include <memory>

struct IQuackBehavior
{
	virtual void Quack() = 0;
	virtual ~IQuackBehavior() {}
};

struct IFlyBehavior
{
	virtual void Fly() = 0;
	virtual ~IFlyBehavior() {}
};

struct IDanceBehavior
{
	virtual void Dance() = 0;
	virtual ~IDanceBehavior() {}
};

class CDuck
{
public:
	void PerformQuack()
	{
		m_quackBehavior->Quack();
	}
	void PerformFly()
	{
		m_flyBehavior->Fly();
	}
	void PerformDance()
	{
		m_danceBehavior->Dance();
	}

protected:
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};

class CQuack : public IQuackBehavior
{
	// реализация кряканья
	void Quack() override
	{
		std::cout << "Quack!" << std::endl;
	}
};

class CNoQuack : public IQuackBehavior
{
	void Quack() override{};
};

class CFlyWithWings : public IFlyBehavior
{
	// реализация полета
	void Fly() override
	{
		std::cout << "I can fly with wings" << std::endl;
	}
};

class CNoFly : public IFlyBehavior
{
	void Fly() override{};
};

class CDanceWaltz : public IDanceBehavior
{
	void Dance() override
	{
		std::cout << "I am dancing waltz" << std::endl;
	}
};

class CDanceMinuet : public IDanceBehavior
{
	void Dance() override
	{
		std::cout << "I am dancing minuet" << std::endl;
	}
};

class CNoDance : public IDanceBehavior
{
	void Dance() override {}
};

class CMallardDuck : public CDuck
{
public:
	CMallardDuck()
	{
		m_quackBehavior = std::make_unique<CQuack>();
		m_flyBehavior = std::make_unique<CFlyWithWings>();
		m_danceBehavior = std::make_unique<CDanceWaltz>();
	}
};

class CReadHeadDuck : public CDuck
{
public:
	CReadHeadDuck()
	{
		m_quackBehavior = std::make_unique<CQuack>();
		m_flyBehavior = std::make_unique<CFlyWithWings>();
		m_danceBehavior = std::make_unique<CDanceMinuet>();
	}
};

class CModelDuck : public CDuck
{
public:
	CModelDuck()
	{
		m_quackBehavior = std::make_unique<CNoQuack>();
		m_flyBehavior = std::make_unique<CNoFly>();
		m_danceBehavior = std::make_unique<CNoDance>();
	}
};

int main()
{
	CModelDuck modelDuck;
	CReadHeadDuck readHeadDuck;
	CMallardDuck mallardDuck;

	modelDuck.PerformDance();
	modelDuck.PerformFly();
	modelDuck.PerformQuack();

	mallardDuck.PerformDance();
	mallardDuck.PerformFly();
	mallardDuck.PerformQuack();

	readHeadDuck.PerformDance();
	readHeadDuck.PerformFly();
	readHeadDuck.PerformQuack();

	return 0;
}