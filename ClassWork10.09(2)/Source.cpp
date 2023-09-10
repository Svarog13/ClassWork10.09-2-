#include<iostream>

class Car
{
private:
	std::string name;
public:
	Car():name("none"){}
	Car(std::string n):name(n){}
	void Drive()const
	{
		std::cout << "I drive " << std::endl;
	}
	void Use() const
	{
		std::cout << "Driving " << name << std::endl;
	}
	
};
class Airplane
{
private:
	std::string name;
public:
	Airplane (): name ("none"){}
	Airplane (std::string n) : name(n){}
	void Fly()const
	{
		std::cout << "I fly" << std::endl;
	}
	void Use()const
	{
		std::cout << "Flying " << name << std::endl;
	}
};
class FlyCar : public Car, public Airplane
{
public:
	FlyCar(std::string name) : Car(name) , Airplane(name){}
};
class A
{
public:
	int value;
	void Show()const
	{
		std::cout << " Value : " << value << std::endl;
	}
};
class B {};
class C {};
class D1 :public virtual A, public B, public C {};
class D2 : public virtual A {};
class D3 : public virtual D1, public D2
{
public:
	int getValue()const
	{
		/*return A::value;
		return D1::value;*/

		return value;
	}
};
class Person
{
private:
	std::string name;
	std::string surname;
public:
	Person() : name("none"), surname("none") {}
	Person(std::string name , std::string surname) : name(name),surname (surname){}

	void setName(std::string name)
	{
		this->name = name;
	}
	void setSurname(std::string surname)
	{
		this->surname = surname;
	}
	std::string getName()const
	{
		return name;
	}
	std::string getSurname()const
	{
		return surname;
	}
	void Show()const
    {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Surname: " << surname << std::endl;
	}
};
class Gamer
{
private:
	int gameHours;
public:
	Gamer()
	{
		gameHours = 100;
	}
	void Show()const
	{
		std::cout << "I have " << gameHours << " hours in games " << std::endl;
	}
};
class SimplePlayer : public Gamer, public Person
{
public:
	SimplePlayer()
	{

	}
	SimplePlayer(std::string n, std::string s) : Person (n,s){}
	void Show()const
	{
		Person::Show();
		std::cout << std::endl;
		Gamer::Show();
	}	
};
class Student : public Person
{
private:
	int mark;
public:
	Student()
	{
		mark = 12;
	}
	void Show()const
	{
		Person::Show();
		std::cout << " I have only one mark : " << mark << std:: endl;
	}
	void setMark(int mark)
	{
		this->mark = mark;
	}
};
class BadStudent : public Student, public SimplePlayer
{
public:
	BadStudent()
	{
		Student::Person::setName("Valera");
		Student::Person::setSurname("Petrovich");
		Student::setMark(2);
	}
	void Show()const
	{
		Student::Show();
		SimplePlayer::Gamer::Show();
	}
};

class Pizza 
{
public:
	virtual void makePizza() const = 0;
};

class Souce
{
public:
	virtual void makeSouce() const = 0;
};

class Milano: public Pizza
{
public:
	void makePizza()const override
	{
		std::cout << " We make Milano pizza! " << std::endl;
	}
};

class Greece : public Pizza
{
public:
	void makePizza() const override
	{
		std::cout << " We make Greece pizza! " << std::endl;
	}

};

class MilanoSouce : public Souce
{
public:
	void makeSouce() const override
	{
		std::cout << " We make Milano souce! " << std::endl;
	}
};

class GreeceSouce : public Souce
{
public:
	void makeSouce() const override
	{
		std::cout << " We make Greece souce! " << std::endl;
	}
};

class Fabric
{
public:
	virtual void makePizza()const = 0;
	virtual void makeSouce()const = 0;
};

class FabricMilano: public Fabric
{
public:
	void makePizza() const override
	{
		std::cout << "We make Milano pizza!" << std::endl;
    }
	void makeSouce() const override
	{
		std::cout << "We make Milano souce!" << std::endl;
	}
};

class FabricGreece : public Fabric
{
public:
	void makePizza() const override
	{
		std::cout << "We make Greece pizza!" << std::endl;
	}
	void makeSouce() const override
	{
		std::cout << "We make Greece souce!" << std::endl;
	}
};


int main()
{/*
	Person p;
	p.setName("Yurii");
	p.setSurname("Khvas");
	p.Show();

	SimplePlayer simple("Yurii", "Khvas");
	simple.Show();

	BadStudent bad;
	bad.setMark(2);*/

	/*Car car("Audi");
	car.Drive();
	Airplane an("Mriya");
	FlyCar flycar("Mriya Audi");
	flycar.Drive();
	flycar.Fly();
	((Car)flycar).Use();
*/
	int choise = 0;
	MilanoSouce milanoSouce;
	GreeceSouce greeceSouce;
	FabricMilano milanoPizza;
	FabricGreece greecePizza;
	std::cout << "Enter the choise: - 1.Milano Souce, 2.Greece Souce , 3. Milano Pizza, 4. Greece Pizza: " << std::endl;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
		milanoSouce.makeSouce();
		break;
	case 2:
		greeceSouce.makeSouce();
		break;
	case 3:
		milanoPizza.makeSouce();
		milanoPizza.makePizza();
		break;
	case 4:
		greecePizza.makeSouce();
		greecePizza.makePizza();
		break;
	default:
		break;
	};
}
