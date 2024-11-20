#include "head.h"

using namespace std;



int main() {
    cout << "********************************" << endl;
    cout << "*                              *" << endl;
    cout << "*     ***   *****  ***         *" << endl;
    cout << "*    *   *  *     *   *        *" << endl;
    cout << "*       *   *****    *         *" << endl;
    cout << "*      *        *   *          *" << endl;
    cout << "*     ***** *****  *****       *" << endl;
    cout << "*                              *" << endl;
    cout << "********************************" << endl;
    
    cout << "Algorithm Project Version 0.2.2" << endl;
    cout << "Please choose your language(1.English 2.中文 3.日本語 4.Français): ";
    int language_type;
    cin >> language_type;

    vector<string> prmtext;
    language(prmtext,language_type);//设置语言
    
    for(int i=0;i<4;i++){
        cout << prmtext[i] << endl;
    }
    // Read the text from file
    ifstream file("text.txt");
    if (!file.is_open()) {
        cerr << prmtext[4] << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();
    file.close();

    // 将文本拆分成句子
    vector<string> sentences = splitIntoSentences(text);

    // 构建哈希表
    unordered_map<string, vector<string>> hashTable = buildHashTable(sentences);

    // 从用户输入读取查询
    string query;
    while (true) {
        cout << prmtext[5];
        cin >> query;
        if (query == "exit") {
            break;
        }
        vector<string> results = searchKeyword(hashTable, query);
        if (results.empty()) {
            cout <<prmtext[6]<< query << endl;
        } else {
            for (const auto& result : results) {
                cout << "\t" << result << endl;
            }
        }
    }

    return 0;
}