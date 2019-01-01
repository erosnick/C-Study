/**
	  普通继承（没有使用虚基类）
  */

  // 基类A  
class A
{
public:
	int dataA;
};

class B : public A
{
public:
	int dataB;
};

class C : public A
{
public:
	int dataC;
};

class D : public B, public C
{
public:
	int dataD;
};