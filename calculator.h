#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Calculator
{

public:
	string calculator(string s);
	string transform(double result);

	bool IsNum(char s);

	double AddNum(vector<double>num);

	bool IsInputSign(string sign);


};