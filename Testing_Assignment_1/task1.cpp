/*
This C++ program reads synonyms from a file, stores them in parallel arrays, and then paraphrases the input text using the synonyms.

The 'readSynonymsFromFile' function:
1. Takes a filename, a vector of words, and a vector of vectors of synonyms as input.
2. Opens the input file and reads its contents line by line.
3. For each line, extracts the word and its associated synonyms.
4. Stores the word in the 'words' vector and its synonyms in a nested vector 'synonyms'.
5. Closes the file after reading.

The 'paraphraseText' function:
1. Takes the input text, the 'words' vector, and the 'synonyms' vector as input.
2. Tokenizes the input text into words using a stringstream.
3. For each word, checks if it matches any of the words in the 'words' vector.
4. If a match is found, randomly selects a synonym for that word and replaces it.
5. Appends the paraphrased word (either the original or the synonym) to the 'output' string.

In the 'main' function:
1. Creates vectors 'words' and 'synonyms' to store the synonyms read from the file.
2. Calls 'readSynonymsFromFile' to populate these vectors with data from the file "synonyms.txt".
3. Asks the user to enter the text to paraphrase.
4. Calls 'paraphraseText' to paraphrase the input text using the synonyms read from the file.
5. Prints the paraphrased text to the console.

Sample 'synonyms.txt' file contents:
-----------------------------------
hello hi hey
run jog sprint
big large huge
quick fast rapid

Sample input and output:
------------------------
Input text: "Hello, please run quickly."
Paraphrased text: "Hi, please jog rapidly."
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to read synonyms from the file and store them in parallel arrays
void readSynonymsFromFile(const string& filename, vector<string>& words, vector<vector<string>>& synonyms) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Unable to open the file " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string word;
        iss >> word;
        words.push_back(word);

        vector<string> syns;
        string synonym;
        while (iss >> synonym) {
            syns.push_back(synonym);
        }
        synonyms.push_back(syns);
    }

    inFile.close();
}

// Function to paraphrase the input text using synonyms
string paraphraseText(const string& input, const vector<string>& words, const vector<vector<string>>& synonyms) {
    string output = "";
    istringstream iss(input);
    string word;

    while (iss >> word) {
        bool paraphrased = false;

        for (size_t i = 0; i < words.size(); i++) {
            if (word == words[i]) {
                size_t numSynonyms = synonyms[i].size();
                if (numSynonyms > 0) {
                    srand(time(0));
                    int randomIndex = rand() % numSynonyms;
                    word = synonyms[i][randomIndex];
                    paraphrased = true;
                    break;
                }
            }
        }

        if (!paraphrased) {
            output += word + " ";
        }
    }

    return output;
}

int main() {
    vector<string> words;
    vector<vector<string>> synonyms;

    // Read synonyms from the file
    readSynonymsFromFile("synonyms.txt", words, synonyms);

    string inputText;
    cout << "Enter the text to paraphrase: ";
    getline(cin, inputText);

    string paraphrasedText = paraphraseText(inputText, words, synonyms);
    cout << "Paraphrased text: " << paraphrasedText << endl;

    return 0;
}
