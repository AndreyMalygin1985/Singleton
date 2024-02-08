#include <iostream>
#include <Windows.h>

using namespace std;

//Target
class ChemicalElement {
protected:
	string name;
	double dencity;
	int position;
public:
	ChemicalElement(string pName) {
		name = pName;
	}
	virtual ~ChemicalElement() {};
	virtual void Show() {
		cout << "Химический элемент: " << name << endl;
	};
};

//Adaptee
class ChemicalElementInformation {
public:
	ChemicalElementInformation() {};
	~ChemicalElementInformation() {};

	double GetDencity(string name) const {
		if (name == "aluminum") { return 2.7; }
		if (name == "barium") { return 3.76; }
		return 0;
	}

	int GetPositionFromPeriodicTable(string name) const
	{
		if (name == "aluminum") { return 13; }
		if (name == "barium") { return 56; }
		return 0;
	}

};

//Adapter
class ExtendedChemicalElement : public ChemicalElement {
private:
	ChemicalElementInformation* pInformation;
public:
	ExtendedChemicalElement(string pName) : ChemicalElement(pName) {
		pInformation = new ChemicalElementInformation();
	}

	~ExtendedChemicalElement() {
		delete pInformation;
	}

	void Show()	{
		cout << "++++++++++++++++++++" << endl;
		ChemicalElement::Show();
		dencity = pInformation->GetDencity(name);
		position = pInformation->GetPositionFromPeriodicTable(name);
		cout << "Dencity of Element - " << dencity << endl;
		cout << "Position of Element - " << position << endl;

	}
};

int main()
{
	SetConsoleOutputCP(1251);

	ChemicalElement* ptr = new ExtendedChemicalElement("aluminum");
	ptr->Show();
	delete ptr;

	ptr = new ExtendedChemicalElement("barium");
	ptr->Show();
	delete ptr;


	return 0;
}