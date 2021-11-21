#include "Rule.h"
#include <vector>

using namespace std;

class Grammar {
public:
    Grammar();
    Grammar(const string& filename);
    vector<Rule> rules;
    void show();

};