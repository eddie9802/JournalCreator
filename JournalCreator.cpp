#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Creates a .jr file
void createJournalFile() {
    cout << "What would you like to call your journal?\n";
    string journalName;
    getline(cin, journalName);

    cout << "\nWhere would you like your journal to be located?  Please specify the filepath as DIRNAME/ ...etc\n";
    string filepath;
    getline(cin, filepath);

    cout << "\nPlease enter the questions you would like to ask the user on addition of journal entries";
    cout << "\nTo enter a question write out your question and press enter.  If you don't want to enter any more questions enter nothing\n";

    // Takes in the users questions for the journal
    vector<string> allQuestions;
    string question;
    getline(cin, question);
    allQuestions.push_back(question);
    while (question.length() > 0) {
        cout << "\nPlease enter another queston\n";
        getline(cin, question);
        allQuestions.push_back(question);
    }

    for (int i = 0; i < allQuestions.size(); i++) {
        cout << allQuestions[i] << "\n";
    }

}

void addToJournal() {

}

void startJournalCreator() {
    // Prints welcome message, asks user if they would like to create a journal and gets their response
    cout << "Welcome to JournalCreator.  Would you like to create a journal? y/n\n";
    string answer;
    getline(cin, answer);

    // Checks users answer to previous y/n question
    bool createJournal = (answer == "y") ? true : false;

    if (createJournal) {
        createJournalFile();
    } else {
        addToJournal();
    }


}

int main(int argc, char* argv[]) {
    startJournalCreator();
    return 0;
}