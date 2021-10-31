#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

bool is_an_email(string s);

int main() {

    bool notWord = false;            // boolean for testing the email function
    string filename;
    cout << "which file\n";
    cin >> filename;

    ifstream f;
    f.open(filename);
    if(!f) {
        cout << "could not open\n";
        return 0;
    }

    vector<string> emails;
    vector<string> theFile;           // vector for the file
    string word;
    while (f >> word){
        theFile.emplace_back(word);
    }
    for (auto & i : theFile){          // vector for the file
        if(is_an_email(i)){
            emails.emplace_back(i);
        }
        if(i == "TOP-SECRET"){                 // if that it is true
            notWord = true;
        }
    }
    if(notWord){
        for(auto & email : emails){         // if not run a loop .. int i =0 ; i <email.size();i++
            cout << email << "\n";
        }
    }

    // // block to test is_an_email
    // // you might want to un-comment this to test your function before
    // // proceeding
    // vector<string> emails = {"amy@blah", "@blah", "blah@"};
    // for(int i=0; i < emails.size(); i++) {
    //   cout << emails[i] << ": ";
    //   if(is_an_email(emails[i])) { cout << "yep\n";}
    //   else { cout << "nope\n";}
    // }

    // ADD FURTHER CODE HERE
    // make a vector of all the file's contents and then process that

    // DESIRED BEHAVIOUR: if run on top_secret_file should see

    // lisa@simpsons.sit.com
    // joey@friends.sit.com
    // homer@simpsons.sit.com
    // marge@simpsons.sit.com
    // bart@simpsons.sit.com
    // maggie@simpsons.sit.com
    // rachel@friends.sit.com
    // ross@friends.sit.com
    // chandler@friends.sit.com
    // monica@friends.sit.com


}


// COMPLETE THE FUNCTION is_an_email(string s)
// it should check that
// s contains @ somewhere,
//  but not right at start
//  and not right at end
// ie.
//  amy@blah -> true
//  @blah    -> false
//  blah@    -> false

bool is_an_email(string s) {
    for(int j = 0; j < s.size(); j++){
        char email = s[j];
        if(email== '@' &&j!= s.size()-1 &&  j!=0){  // first one at the end , // second one at the end
            return true;
        }
    }
    return false;

}
