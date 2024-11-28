#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>
#include <list>

using namespace std;

vector<string> splitIntoSentences(const string& text);
unordered_map<string, vector<string>> buildHashTable(const vector<string>& sentences);
unordered_map<string, vector<string>> buildCustomHashTable(const vector<string>& sentences);
unordered_map<string, list<string>> buildChainedHashTable(const vector<string>& sentences);
list<string> searchKeyword(const unordered_map<string, list<string>>& hashTable, const string& keyword);
vector<string> searchKeyword(const unordered_map<string, vector<string>>& hashTable, const string& keyword);
void language(vector<string> &prmtext, int type);