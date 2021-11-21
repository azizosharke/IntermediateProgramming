/************* TranslationDictionary.cpp **********************/
#include <string>
#include <iostream>
#include <fstream>

#include "TranslationDictionary.h"

using namespace std;

Trans_Dict::Trans_Dict() {}

/*************************************************************************/
/* builds dictionary from file with translation pairs source/translation */
/* on single lines                                                       */
/*************************************************************************/
Trans_Dict::Trans_Dict(string file_name) {
    string line, translation, word;
    ifstream f;
    Transpair p;
    size_t trans_offset;



    f.open(file_name);
    if(f) {
        opened_ok = true;
    }
    else {
        opened_ok = false;
    }

    if(opened_ok) {

        while(f >> line) {
            trans_offset = line.find('/'); /* trans_offset is location of / */

            if(trans_offset == string::npos) {
                cout << "there was an entry with no /\n";
                continue;
            }
            else {
                word = line.substr(0,trans_offset); // up to /
                translation = line.substr(trans_offset+1); // after /
                // make transpair with word and translation
                p.french = word;
                p.english = translation;
                thewords.push_back(p); // add transpair to thewords
            }

        }
    }

}


/*****************************************************************/
/* looks up word in dictionary, returning true or false          */
/* setting 'trans' to contain the translation if found           */
/*****************************************************************/
bool Trans_Dict::lookup(string word, string& trans) {
    int i;
    for(i = 0; i < thewords.size(); i++) {
        if (thewords[i].french == word) {
            trans = thewords[i].english;
            return true;
        }
    }

    return false;
}


bool Trans_Dict::french_search(string word, string& trans) {
    int j ;
    for(j = 0; j < thewords.size(); j++) { // for loop to look for the words
        if (thewords[j].english == word) {
            trans = thewords[j].french;  // convert it to french
            return true;
        }
    }
    return false;
}
bool Trans_Dict::update(string wordFrench, string wordEnglish) {
    for(auto & theword : thewords) {
        if (theword.french == wordFrench){
            theword.english = wordEnglish;
            return true;
        }
    }
    Transpair words;
    words.french = wordFrench;
    words.english = wordEnglish;
    thewords.push_back(words);
    return true;
}
bool Trans_Dict::export_to_file(string filename) {
    ofstream file;
    file.open(filename);
    for(auto & theword : thewords) {
        string line = theword.french + "/" + theword.english + '\n';
        file << line;
    }
    file.close();
    return true;
}





