// ChaiScript.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <chaiscript/chaiscript.hpp>

std::string HelloWorld(const std::string & Name)
{
	return "Hello " + Name + "!\n";
}

int main()
{
	chaiscript::ChaiScript Chai;

	Chai.add(chaiscript::fun(&HelloWorld), "HellowWorld");

	Chai.eval(R"(puts(HellowWorld("Bob"));)");
}
