import std.core;

class Beverage
{
public:

	enum class CupSize : int
	{
		Tall,
		Grande,
		Venti
	};

	virtual std::string getDescription() const
	{
		return description;
	}

	virtual double cost() const = 0;

	void setSize(CupSize newSize)
	{
		size = newSize;
	}

	CupSize getSize() const
	{
		return size;
	}

protected:
	CupSize size;
	std::string description = "Unknow Beverage."; 
};