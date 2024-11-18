#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include "search.h"

using namespace std;


int main() {
    string filename;
    cout << "********************************" << endl;
    cout << "*                              *" << endl;
    cout << "*     ***   *****  ***         *" << endl;
    cout << "*    *   *  *     *   *        *" << endl;
    cout << "*       *   *****    *         *" << endl;
    cout << "*      *        *   *          *" << endl;
    cout << "*     ***** *****  *****       *" << endl;
    cout << "*                              *" << endl;
    cout << "********************************" << endl;
    
    cout << "Algorithm Project Version 0.1.1" << endl;
    cout << "welcome to use this program" << endl;

    cout << "Please enter the file path: ";
    getline(cin, filename);

    // Load text and build hash table index
    auto sentences = load_text(filename);
    if (sentences.empty()) {
        cerr << "Failed to load text from file." << endl;
        return 1; // Loading failed, exit program
    }

    auto index = build_index(sentences);

    // Perform query
    string query;
    while (true) {
        cout << "> ";

        // Use more functions from search.h
        vector<string> results = search_query(index, sentences, query);
        if (results.empty()) {
            cout << "No results found for query: " << query << endl;
        } else {
            cout << "Results for query: " << query << endl;
            for (const auto& result : results) {
                cout << result << endl;
            }
        }

        cout<< "Do you want to continue? (y/n): ";
        char cont;
        cin>>cont;
        if(cont == 'n') break;
        
    }

    return 0;
}
