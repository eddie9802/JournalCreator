#include <iostream>

using namespace std;


void startJournalCreator() {
    // Prints welcome message, asks user if they would like to create a journal and gets their response
    cout << "Welcome to JournalCreator.  Would you like to create a journal? y/n\n";
    string answer;
    cin >> answer;

    // Checks users answer to previous y/n question
    bool createJournal = (answer == "y") ? true : false;
}

int main(int argc, char* argv[]) {
    startJournalCreator();
    return 0;
}