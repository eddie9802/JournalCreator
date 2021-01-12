#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Takes in the users questions for the journal and returns them in a vector
vector<string> getJournalQuestions() {
    vector<string> allQuestions;

    // At least one question is required
    string question;

    // Reads user questions until no question is entered
    do {
        getline(cin, question);
        // Checks if a question mark is at the end
        if (question[question.length() - 1] == '?') {
            allQuestions.push_back(question);
            cout << "\nQuestion successfully added.  Please enter another question or enter nothing to complete the journal creation process\n";
        } else if (question.length() > 0) {
            cout << "Questions must end in a question mark" << endl;
        } else if (allQuestions.size() == 0) {
            cout << "Atleast one question must be given" << endl;
        }
    } while (allQuestions.size() == 0 || question.length() > 0);
    return allQuestions;
}


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

    vector<string> allQuestions = getJournalQuestions();

    // Writes questions to the file given by journalName and path filepath.  Creates a .jr file
    filepath.append(journalName);
    filepath.append(".jr");
    ofstream outfile(filepath);

    outfile << "Journal Questions" << endl;
    // Writes all of the questions to the start of the file
    for (int i = 0; i < allQuestions.size(); i++) {
        outfile << allQuestions[i];
    }
    outfile.close();
}

void addToJournal() {

}

void startJournalCreator() {
    // Prints welcome message, asks user if they would like to create a journal and gets their response
    cout << "Welcome to JournalCreator.  Would you like to create a journal? y/n\n";
    string answer;
    getline(cin, answer);

    // Checks users answer to previous y/n question

    if (answer == "y") {
        createJournalFile();
    } else {
        addToJournal();
    }


}

int main(int argc, char* argv[]) {
    startJournalCreator();
    return 0;
}