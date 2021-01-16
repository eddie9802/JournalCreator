#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Takes in the users questions for the journal and returns them in a vector
vector<string> getStreakQuestions() {
    vector<string> allQuestions;

    // At least one question is required
    string question;

    // Reads user questions until no question is entered
    do {
        getline(cin, question);
        // Checks if a question mark is at the end
        if (question[question.length() - 1] == '?') {
            allQuestions.push_back(question);
            cout << "\nQuestion successfully added.  Please enter another question or enter nothing to complete the streak file creation process\n";
        } else if (question.length() > 0) {
            cout << "Questions must end in a question mark" << endl;
        } else if (allQuestions.size() == 0) {
            cout << "Atleast one question must be given" << endl;
        }
    } while (allQuestions.size() == 0 || question.length() > 0);
    return allQuestions;
}


// Creates a .jr file
void createStreakFile() {
    cout << "What would you like to call your streak file?\n";
    string streakFileName;
    getline(cin, streakFileName);

    cout << "\nWhere would you like your streak file to be located?  Please specify the filepath as DIRNAME/ ...etc\n";
    string filepath;
    getline(cin, filepath);

    cout << endl << "Please enter the questions you would like to ask the user on opening of streak file";
    cout << endl << "To enter a question write out your question and press enter.  If you don't want to enter any more questions enter nothing" << endl;

    vector<string> allQuestions = getStreakQuestions();

    // Writes questions to the file given by streakFileName and path filepath.  Creates a .stk file
    filepath.append(streakFileName);
    filepath.append(".stk");
    ofstream outfile(filepath);

    outfile << "Streak file questions" << endl;
    // Writes all of the questions to the start of the file
    for (int i = 0; i < allQuestions.size(); i++) {
        outfile << allQuestions[i];
    }
    outfile.close();
}

void addToStreakFile() {

}

void startStreakCalculator() {
    // Prints welcome message, asks user if they would like to create a journal and gets their response
    cout << "Welcome to StreakCalculator.  Would you like to create a streak file? y/n\n";
    string answer;
    getline(cin, answer);

    // Checks users answer to previous y/n question

    if (answer == "y") {
        createStreakFile();
    } else {
        addToStreakFile();
    }


}

int main(int argc, char* argv[]) {
    startStreakCalculator();
    return 0;
}