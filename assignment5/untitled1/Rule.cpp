#include "Rule.h"
#include <iostream>

Rule::Rule() = default;

// make the rule_as_string member be same as 'input'
// this will break it into daughter and mother parts
Rule::Rule(string input)
{
    int FIVE = 5;
    int ONE = 1;
    int ZERO = 0 ;
    rule_as_string = std::move(input);
    string daughter;
    size_t j, start, end;
    j = rule_as_string.find(" --> ");
    start = j + FIVE;
    end = j;
    daughter = rule_as_string.substr(ZERO,end) ;
    mother = daughter;
    while((j = rule_as_string.find(',',start))
    != string::npos)
    {
        end = j-start;
        daughter = rule_as_string.substr(start,end);
        daughters.push_back(daughter);
        start = j+ONE;
    }

    daughter = rule_as_string.substr(start);
    daughters.push_back(daughter);
}

// show the the rule_as_string member
// same as rule prasing assignment
void Rule::show()
{
    cout << mother;
    cout << " -- > " << endl;
    for (auto & daughter : daughters)
    {
        cout << "     " << daughter << endl;
    }
}

