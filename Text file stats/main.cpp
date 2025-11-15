#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct fileData {
    int characters = 0;
    int words = 0;
    int lines = 0;
};

int getWordCount(const string& s) { // it is modern cpp to pass by reference
    int wordcount = 0;
    bool is_word = false;

    // For every char c in sentence s
    // Logic is: Only count when a new word is detected after a whitespace
    for (char c : s) {
        if (isspace(c)) { // isspace is able to work with more than just ' '
            is_word = false;
        } else {
            if (!is_word) {
            is_word = true;
            wordcount++;
            }
        }
    }

    return wordcount;
}

int main() {
    string filename = "";
    cout << "Enter filename to read: ";
    cin >> filename;

    // If user did not provide file extension in their answer,
    // add it for them
    if (filename.find(".txt") == string::npos) {
        filename += ".txt"; 
    }
    
    ifstream TextFile(filename); // Read from the file
    if (TextFile.fail()) {
        cout << "Text file of that file name does not exist" << endl;
        return 1;
    }

    string text; // String to store text file data in
    fileData stats; // stats for the text file
    // Calculate data from the file line by line
    while(getline (TextFile, text)) {
        cout << text << endl;
        stats.words += getWordCount(text);
        stats.characters += text.length();
        stats.lines++;
    }
    
    // Print data
    cout << "Word count: " << stats.words << endl;
    cout << "Character count: " << stats.characters << endl;
    cout << "Line count: " << stats.lines << endl;

    // Close the file
    TextFile.close();
}