#include "calculator.h"

string Calculator::calculator(string s) {
	double n = s.size(), dgt = 0;
	char preSign = '+';//第一个数是正的
	vector<double> v;
	int num = 1;       //小数点
	bool IsPoint = false;
	for (int i = 0; i < n; i++) {
		if (!IsNum(s[i])) preSign = s[i], num = 1, IsPoint = false;
		else {
			while (IsNum(s[i]))
			{
				if (s[i] == '.') i++, IsPoint = true;
				if (IsPoint)
				{
					dgt = dgt + (s[i] - '0') * pow(0.1, num);
					num++;

				}
				else dgt = dgt * 10 + s[i] - '0';
				i++;
				cout << "dgt==" << dgt << endl;
			}
			cout << "num=" << dgt << endl;
			cout << "symbol=" << preSign << endl;
			if (preSign == '+') v.push_back(dgt);
			if (preSign == '-') v.push_back(-dgt);
			if (preSign == '*') v.back() *= dgt;
			if (preSign == '/') v.back() /= dgt;
			dgt = 0, i--;
		}
	}
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	double result = AddNum(v);
	cout << "result=" << result << endl;
	return transform(result);
}

string Calculator::transform(double result)
{
	string sum;
	sum.push_back('=');
	string temp = to_string(result);
	sum += temp;
	for (auto it = sum.end() - 1; it != sum.begin(); it--)
	{
		if (*it == '0') sum.pop_back();
		
		else break;
	}
	cout << "sum=" << sum << endl;
	return sum;
}

bool Calculator::IsNum(char s)
{
	return (s >= '0' && s <= '9') || s == '.';
}

double Calculator::AddNum(vector<double> num)
{
	double result = 0.0f;
	for (auto it = num.begin(); it != num.end(); it++)
	{
		result += *it;
	}
	return result;
}

bool Calculator::IsInputSign(string sign)
{
	bool IsSign = false;
	if (sign == "-") IsSign = true;
	else if (sign == "+") IsSign = true;
	else if (sign == "*")IsSign = true;
	else if (sign == "/")IsSign = true;
	else IsSign = false;
	return IsSign;
}