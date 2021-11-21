#include "Grammar.h"
#include <iostream>
#include <fstream>

Grammar::Grammar()= default;

// open the file, get its lines one-by-one, feeding these to Rule constructor
// and using to build up rules member


Grammar::Grammar(const string& fname) {
ifstream fileToUse;            // open the file part
fileToUse.open(fname);

string line;
    while (getline(fileToUse,line))
    { // get its line one by one
        Rule the_rule(line);
        rules.emplace_back(the_rule);
    }

}

// go thru rules using each members show method
void Grammar::show()
{
    // fix this ---- > fixed
    //cout << "this should display the rules\n";

    cout << "Number of the rules was " << rules.size() << endl;
    for (auto & rule : rules)
    {
        rule.show();
    }
}