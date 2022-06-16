#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "y.tab.h"

class Pair
{
public:
    Pair(std::string x, float y) : x(x), y(y) {}
    std::string x;
    float y;
};

void add(std::string name, float value, std::map<std::string, float> &map)
{
    map[name] = value;
    std::cout << "Iterating through map: " << std::endl;
    for (auto s : map)
        std::cout << s.first << " = " << s.second << std::endl;
}

float get(std::string name, std::map<std::string, float> &map)
{
    return map[name];
    std::cout << "Iterating through map at get: " << std::endl;
    for (auto s : map)
        std::cout << s.first << " = " << s.second << std::endl;
}

void coutf(float value)
{
    std::cout << value << std::endl;
}

float operate(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return (int)a % (int)b;
    case '^':
        return pow(a, b);
    default:
        return 0;
    }
}

void cerrs(std::string s)
{
    std::cerr << s << std::endl;
}

bool isFunction(std::string s)
{
    std::vector<std::string> functionNames = {"@sin", "@cos", "@tan", "@asin", "@acos", "@atan", "@sqrt", "@log", "@exp", "@abs", "@ceil", "@floor", "@round", "@sec", "@csc", "@cot", "@sinh", "@cosh", "@tanh", "@asinh", "@acosh", "@atanh", "@sech", "@csch", "@coth", "@arcsin", "@arccos", "@arctan", "@arcsec", "@arccsc", "@arccot", "@arcsinh", "@arccosh", "@arctanh", "@arcsech", "@arccsch", "@arccoth", "@ln", "@cosec", "@acosec", "@cosech", "@arccosec", "@arccosech", "@radtodeg", "@degtorad"};
    for (auto str : functionNames)
    {
        if (str == s)
            return true;
    }
    return false;
}

float functionValue(std::string s, float f)
{
    if (s == "@sin")
        return sin(f);
    if (s == "@cos")
        return cos(f);
    if (s == "@tan")
        return tan(f);
    if (s == "@asin")
        return asin(f);
    if (s == "@acos")
        return acos(f);
    if (s == "@atan")
        return atan(f);

    if (s == "@sqrt")
        return sqrt(f);
    if (s == "@log")
        return log(f);
    if (s == "@exp")
        return exp(f);
    if (s == "@abs")
        return fabs(f);
    if (s == "@ceil")
        return ceil(f);
    if (s == "@floor")
        return floor(f);
    if (s == "@round")
        return round(f);

    if (s == "@sec")
        return 1 / cos(f);
    if (s == "@csc")
        return 1 / sin(f);
    if (s == "@cot")
        return 1 / tan(f);
    if (s == "@sinh")
        return sinh(f);
    if (s == "@cosh")
        return cosh(f);
    if (s == "@tanh")
        return tanh(f);
    if (s == "@asinh")
        return asinh(f);
    if (s == "@acosh")
        return acosh(f);
    if (s == "@atanh")
        return atanh(f);
    if (s == "@sech")
        return 1 / cosh(f);
    if (s == "@csch")
        return 1 / sinh(f);
    if (s == "@coth")
        return 1 / tanh(f);
    if (s == "@arcsin")
        return asin(f);
    if (s == "@arccos")
        return acos(f);
    if (s == "@arctan")
        return atan(f);
    if (s == "@arcsec")
        return 1 / cos(f);

    if (s == "@arccsc")
        return 1 / sin(f);
    if (s == "@arccot")
        return 1 / tan(f);
    if (s == "@arcsinh")
        return asinh(f);
    if (s == "@arccosh")
        return acosh(f);
    if (s == "@arctanh")
        return atanh(f);
    if (s == "@arcsech")
        return 1 / cosh(f);
    if (s == "@arccsch")
        return 1 / sinh(f);
    if (s == "@arccoth")
        return 1 / tanh(f);

    if (s == "@ln")
        return log(f);
    if (s == "@cosec")
        return 1 / sin(f);
    if (s == "@acosec")
        return 1 / asin(f);
    if (s == "@cosech")
        return 1 / tan(f);
    if (s == "@arccosec")
        return 1 / acos(f);
    if (s == "@arccosech")
        return 1 / atan(f);
    if (s == "@radtodeg")
        return f * 180 / 3.141592653589793;
    if (s == "@degtorad")
        return f * 3.141592653589793 / 180;
    return 0;
}

bool isNotAlNum(char c)
{
    return !(isalnum(c) || c == '_');
}

std::string strip(std::string s)
{
    s = s.substr(0, s.find("="));
    s.erase(std::remove_if(s.begin(), s.end(), isNotAlNum), s.end());

    return s;
}
std::string functionStrip(std::string s)
{
    int nearestNonAlpha = -1;
    for (int i = 1; i < s.size(); i++)
    {
        if (isalpha(s[i]) || s[i] == '_')
        {
            nearestNonAlpha = i;
        }
        else
        {
            break;
        }
    }
    if (nearestNonAlpha > 0)
        s = s.substr(0, nearestNonAlpha + 1);
    return s;
}std::vector<Pair> v;

float vget(std::string s) {
    for(auto p : v) {
        if(p.x == s) {
            return p.y;
        }
    }
    std::cerr << "Variable undefined: '";
    std::cout << s << '\'' <<std::endl;
    return 0;
}

void vput(std::string s, float f) {
    for(int i = 0; i < v.size(); ++i) {
        if(v[i].x == s) {
            v[i].y = f;
            return;
        }
    }
    v.push_back(Pair(s, f));
}

    