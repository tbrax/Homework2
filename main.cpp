// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
using std::string;
using std::cout;
using std::endl;

int Add(string numbers)
{
	int temp_hold =0;
	string prev_input = "";
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] != ',' && numbers[i] != '\n')
		{
			temp_hold += (int)(numbers[i] - '0') % 48;;
		}

	}
	return temp_hold;
}
TEST_CASE("Empty returns zero", "[Add]")
{
	REQUIRE(Add("") == 0);
	REQUIRE(Add("1") == 1);
	REQUIRE(Add("2") == 2);
	REQUIRE(Add("1,1") == 2);
	REQUIRE(Add("1,3,3") == 7);
	REQUIRE(Add("5,5,5,4") == 19);
	REQUIRE(Add("5\n5\n5\n4") == 19);
	REQUIRE(Add("3,3\n3,3") == 12);
}
