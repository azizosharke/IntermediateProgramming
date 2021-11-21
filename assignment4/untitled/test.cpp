/*********************************/
/* tests the Trans_Dict class    */
/*********************************/
#include <iostream>
#include "TranslationDictionary.h"
#include <stdlib.h>


using namespace std;

void tester_function(Trans_Dict& d, string name, vector<string> fr_words);
void tester_functionA(Trans_Dict& d, string name, vector<string> englishWords);



int main() {
    Trans_Dict d1("translist.txt");
    Trans_Dict d2("translist2.txt");

    if (!d1.opened_ok) {
        cerr << "dictionary to translist did not open ok\n";
        exit(0);
    }

    if (!d2.opened_ok) {
        cerr << "dictionary to translist2 did not open ok\n";
        exit(0);
    }




    string trans_english;
    vector<string>fr_words;

     fr_words = {"soulier", "jupe", "chien"};
     tester_function(d1, "translist", fr_words);
     fr_words = {"chien", "oiseau", "soulier"};
     tester_function(d2, "translist2", fr_words);

     vector<string>englishWords;
     englishWords = { "shoe" , "hat"};
    tester_functionA(d1, "translist", englishWords);

    englishWords.clear();
    englishWords.emplace_back("hat");
    englishWords.emplace_back("shoe");
     d1.update("hat" , "cheapau");
     d1.update("shoe", "soulier");
     cout << "testing d1 after adding chapeau/hat \n";
     tester_function(d1,"translist", englishWords);


    fr_words.clear();
    fr_words.emplace_back("chien");
    d2.update("chien","hound");
    cout << "testing d2 after adding chien/hound\n";
    tester_function(d2, "translist2", fr_words);






}




void tester_function(Trans_Dict& d, string name, vector<string> fr_words) {
    string trans_english;
    for(unsigned int i=0; i < fr_words.size(); i++) {
        if(d.lookup(fr_words[i],trans_english)) {
            cout << name << " trans of " << fr_words[i] << " is " << trans_english << endl;
        }
        else {
            cout << "no " << name << " trans of " << fr_words[i] << endl;
        }
    }
    cout<< " ------------ \n";
}

void tester_functionA(Trans_Dict& d, string name, vector<string> english_words) {
    string trans_french;
    for(unsigned int i=0; i < english_words.size(); i++) {
        if(d.french_search(english_words[i],trans_french)) {
            cout << name << " trans of " << english_words[i] << " is " << trans_french << endl;
        }
        else {
            cout << "no " << name << " trans of " << english_words[i] << endl;
        }

    }
    cout<< " ------------ \n";
}

