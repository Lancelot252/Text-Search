#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

// Function to split text into sentences
vector<string> splitIntoSentences(const string& text) {
    vector<string> sentences;
    stringstream ss(text);
    string sentence;
    while (getline(ss, sentence, '.')) {
        if (!sentence.empty()) {
            sentences.push_back(sentence + ".");
        }
    }
    return sentences;
}

// Function to build the hash table
unordered_map<string, vector<string>> buildHashTable(const vector<string>& sentences) {
    unordered_map<string, vector<string>> hashTable;
    for (const auto& sentence : sentences) {
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            // Remove punctuation from the word
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            hashTable[word].push_back(sentence);
        }
    }
    return hashTable;
}

// Function to search for a keyword in the hash table
vector<string> searchKeyword(const unordered_map<string, vector<string>>& hashTable, const string& keyword) {
    auto it = hashTable.find(keyword);
    if (it != hashTable.end()) {
        return it->second;
    }
    return {};
}

int main() {
    // Read the text from file
    ifstream file("text.txt");
    if (!file.is_open()) {
        cerr << "Failed to open text.txt" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();
    file.close();

    // Split text into sentences
    vector<string> sentences = splitIntoSentences(text);

    // Build the hash table
    unordered_map<string, vector<string>> hashTable = buildHashTable(sentences);

    // Read queries from user input
    string query;
    while (true) {
        cout << "Enter a keyword to search (or type 'exit' to quit): ";
        cin >> query;
        if (query == "exit") {
            break;
        }
        vector<string> results = searchKeyword(hashTable, query);
        if (results.empty()) {
            cout << "No sentences found containing the keyword: " << query << endl;
        } else {
            for (const auto& result : results) {
                cout << "\t" << result << endl;
            }
        }
    }

    return 0;
}