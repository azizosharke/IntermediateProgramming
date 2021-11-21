#include <string>
#include <vector>
using namespace std;

class Rule {
public:
    Rule();
    string rule_as_string;
    Rule(string input);
    string mother;
    vector<string> daughters;
    void show();

};