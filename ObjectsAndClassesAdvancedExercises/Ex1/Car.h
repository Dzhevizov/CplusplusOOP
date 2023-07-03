#ifndef CAR_H
#define CAR_H

using namespace std;

class Car
{
	string Brand;
	string Model;
	int Year;

public:

	Car(string sBrand, string sModel, int nYear)
		: Brand(sBrand)
		, Model(sModel)
		, Year(nYear)
	{
	}

	~Car()
	{
	}

	string GetBrand() const
	{
		return Brand;
	}

	string GetModel() const
	{
		return Model;
	}

	int GetYear() const
	{
		return Year;
	}
};

#endif // !CAR_H