class Point
{
public:

	virtual ~Point() {}

private:

	static Point P;
	float X;
	float Y;
	float Z;
};

class Point2D
{
public:
	Point2D(float X = 0.0, float Y = 0.0);
	virtual ~Point2D();

	virtual void Mumble();
	virtual float Z();
protected:
	float _X, _Y;
};

class Point3D : public virtual Point2D
{
public:
	Point3D(float X = 0.0, float Y = 0.0, float Z = 0.0);
	~Point3D();

	float Z();

protected:
	float _Z;
};

class Base1
{
public:
	Base1();
	virtual ~Base1();
	virtual void SpeakClearly();
	virtual Base1* Clone() const;
protected:
	float Data_Base1;
};

class Base2
{
public:
	Base2();
	virtual ~Base2();
	virtual void Mumble();
	virtual Base2* Clone() const;
protected:
	float Data_Base2;
};

class Derived : public Base1, public Base2
{
public:
	Derived();
	virtual ~Derived();
	virtual Derived* Clone() const;
	virtual void Foo();
protected:
	float Data_Derived;
};