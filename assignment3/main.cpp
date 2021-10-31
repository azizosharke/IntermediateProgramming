#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void fancy_print(vector<string> r);

int main(int argc, char *argv[]) {
    // open indicated file
    // get lines making vectors from rules

    char *fname;
    ifstream file;
    fname = argv[1]; // filename is first command line argument

    file.open(fname);

    string line;
    int nrules = 0;
    vector<string> rule;
    vector<vector<string>> the_rules;
    size_t i, start, len; // len is number of characters in a category
    string category;


    while (getline(file, line)) {

        i = line.find(" --> "); // i is first after mother
        start = i + 5;          // start is first of daughter
        len = i;                // length of mother is i
        category = line.substr(0, len); // make string from mother

        rule.push_back(category); // mother of rule gets pushed

        /* push all daughters up to last comma */
        while ((i = line.find(',', start)) != string::npos) {
            len = i - start;     // length of current daughter
            category = line.substr(start, len);
            rule.push_back(category);
            start = i + 1;
        }

        /* push last dtr */

        category = line.substr(start);
        rule.push_back(category);
        the_rules.push_back(rule);
        nrules++;
        rule.clear();
    }

    for(int j = 0; j < the_rules.size(); j++) {
        fancy_print(the_rules[j]);
    }
    cout << "number of rules was " << nrules << endl;
    while(true) {
        int input;
        cout << "How many daughters do you want to see?" << endl;
        cin >> input;
        int count;
        count = 0;
        for(auto & the_rule : the_rules) {              // for (int j =0 ; j<the_rules.size();j++
            if (input != the_rule.size() - 1)
                continue;
            fancy_print(the_rule);
            count++;
        }
        if (count != 0) {
        }
        else {
            cout << "There are no rules with that many daughters" << endl;
        }
        cout << "do you want to continue! Please press [yes / no] ?" << endl;
        string character;
        cin >> character;
        if (character == "yes")
            continue;
        return 0;
    }

}


void fancy_print(vector<string> r) {
    cout << r[0];
    cout << " --> " << endl;
    for (unsigned int i = 1; i < r.size(); i++) {
        cout << "     " << r[i] << endl;
    }

}







