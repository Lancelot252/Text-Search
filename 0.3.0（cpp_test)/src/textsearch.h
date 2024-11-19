#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <QString>
#include <QFile>
#include <QTextStream>

using namespace std;

class TextSearch {
public:
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

    unordered_map<string, unordered_set<string>> buildHashTable(const vector<string>& sentences) {
        unordered_map<string, unordered_set<string>> hashTable;
        for (const auto& sentence : sentences) {
            stringstream ss(sentence);
            string word;
            while (ss >> word) {
                string cleanWord;
                remove_copy_if(word.begin(), word.end(), back_inserter(cleanWord), ::ispunct);
                hashTable[cleanWord].insert(sentence);
            }
        }
        return hashTable;
    }

    unordered_set<string> searchKeyword(const unordered_map<string, unordered_set<string>>& hashTable, const string& keyword) {
        auto it = hashTable.find(keyword);
        if (it != hashTable.end()) {
            return it->second;
        }
        return {};
    }

    QString loadTextFromFile(const QString& fileName) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return "";
        }
        QTextStream in(&file);
        return in.readAll();
    }
};