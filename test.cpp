#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>
#include <string>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}
}

TEST_CASE("ALL substrings are removed","[removeAllSubstrings]")
{
	SECTION("removing bb from aaaabbbb")
	{ // should remove both instances of bb
		REQUIRE( RemoveAllSubstrings("aaaabbbb", "bb") == "aaaa" );
	}
	SECTION("removing bb from aaaaaaaa")
	{ // should return the original string
		REQUIRE( RemoveAllSubstrings("aaaaaaaa", "bb") == "aaaaaaaa" );
	}
}

TEST_CASE("FIRST substring is removed","[removeFirstSubstrings]")
{
	SECTION("removing bb from aaaabbbb")
	{ // should remove just the first instance of bb
		REQUIRE( RemoveFirstSubstring("aaaabbbb", "bb") == "aaaabb" );
	}
	SECTION("removing bb from aaaaaaaa")
	{ // should return the original string
		REQUIRE( RemoveFirstSubstring("aaaaaaaa", "bb") == "aaaaaaaa" );
	}
}

TEST_CASE("false for odd, true for even","[EvenMask]")
{
	SECTION("{1,2,3,4,5} -> {false,true,false,true,false}")
	{
		std::vector<int> nums = {1,2,3,4,5};
		std::vector<bool> mask = {false,true,false,true,false};
		REQUIRE( EvenMask(nums) == mask );
	}
}

TEST_CASE("true for odd, false for even","[OddMask]")
{
	SECTION("{1,2,3,4,5} -> {true,false,true,false,true}")
	{
		std::vector<int> nums = {1,2,3,4,5};
		std::vector<bool> mask = {true,false,true,false,true};
		REQUIRE( OddMask(nums) == mask );
	}
}

TEST_CASE("Sum of vector<int>","[Sum]")
{
	SECTION("{1,2,3,4,5} -> 15")
	{
		std::vector<int> nums = {1,2,3,4,5};
		REQUIRE( Sum(nums) == 15 );
	}
}











