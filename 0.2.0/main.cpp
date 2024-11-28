#include "head.h"

using namespace std;



int main() {
    cout << "////////////////////////////////" << endl;
    cout << "//                            //" << endl;
    cout << "//     ***   *****  ***       //" << endl;
    cout << "//    *   *  *     *   *      //" << endl;
    cout << "//       *   *****    *       //" << endl;
    cout << "//      *        *   *        //" << endl;
    cout << "//     ***** *****  *****     //" << endl;
    cout << "//                            //" << endl;
    cout << "////////////////////////////////" << endl;
    
    cout << "Algorithm Project Version 0.2.7" << endl;
    cout << "Please choose your language(1.English 2.中文 3.日本語 4.Français): ";
    int language_type;
    cin >> language_type;

    vector<string> prmtext;
    language(prmtext,language_type);//设置语言
    
    for(int i=0;i<4;i++){
        cout << prmtext[i] << endl;
    }
    // 读取文本文件
    ifstream file("text.txt");
    if (!file.is_open()) {
        cerr << prmtext[4] << endl;
        return 1;
    }

    // 读取文本内容
    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();
    file.close();

    // 将文本拆分成句子
    vector<string> sentences = splitIntoSentences(text);

    // 选择哈希函数类型
    cout << prmtext[5] << endl;
    int hash_function_type;
    cin >> hash_function_type;

    // 构建哈希表
    if (hash_function_type == 1) {
        unordered_map<string, vector<string>> hashTable = buildHashTable(sentences);
        // 从用户输入读取查询
        string query;
        while (true) {
            cout << prmtext[6];
            cin >> query;
            if (query == "exit") {
                break;
            }
            vector<string> results = searchKeyword(hashTable, query);
            if (results.empty()) {
                cout <<prmtext[7]<< query << endl;
            } else {
                for (const auto& result : results) {
                    cout << "\t" << result << endl;
                }
            }
        }
    } else if (hash_function_type == 2) {
        unordered_map<string, vector<string>> hashTable = buildCustomHashTable(sentences);
        // 从用户输入读取查询
        string query;
        while (true) {
            cout << prmtext[6];
            cin >> query;
            if (query == "exit") {
                break;
            }
            vector<string> results = searchKeyword(hashTable, query);
            if (results.empty()) {
                cout <<prmtext[7]<< query << endl;
            } else {
                for (const auto& result : results) {
                    cout << "\t" << result << endl;
                }
            }
        }
    } else if (hash_function_type == 3) {
        unordered_map<string, list<string>> hashTable = buildChainedHashTable(sentences);
        // 从用户输入读取查询
        string query;
        while (true) {
            cout << prmtext[6];
            cin >> query;
            if (query == "exit") {
                break;
            }
            list<string> results = searchKeyword(hashTable, query);
            if (results.empty()) {
                cout <<prmtext[7]<< query << endl;
            } else {
                for (const auto& result : results) {
                    cout << "\t" << result << endl;
                }
            }
        }
    }

    return 0;
}