#pragma once
class ChocolateBoiler
{
public:
	ChocolateBoiler();
	~ChocolateBoiler();
	void Fill();
	void Drain();
	void Boil();
	bool IsEmpty();
	bool IsBoilded();
	//ChocolateBoiler* m_p1;
	//ChocolateBoiler* m_p2;
private:
	bool isEmpty;
	bool isBoiled;
};

