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

void language(vector<string> &prmtext,int type){
    if (type == 1) {
        prmtext.push_back("welcome to use this program");
        prmtext.push_back("This program is used to search for sentences containing a keyword in a text file");
        prmtext.push_back("The text file must be named 'text.txt' and must be in the same directory as the executable");
        prmtext.push_back("Currently only supports searching in English");
        prmtext.push_back("Failed to open text.txt");
        prmtext.push_back("Enter a keyword to search (or type 'exit' to quit): ");
        prmtext.push_back("No sentences found containing the keyword: ");
    } else if (type == 2)
    {
        prmtext.push_back("欢迎使用本程序");
        prmtext.push_back("本程序用于在文本文件中搜索包含关键字的句子");
        prmtext.push_back("文本文件必须命名为'text.txt'，并且必须与可执行文件在同一目录中");
        prmtext.push_back("目前仅支持英文搜索");
        prmtext.push_back("无法打开text.txt");
        prmtext.push_back("输入要搜索的关键字(或输入'exit'退出): ");
        prmtext.push_back("未找到包含关键字的句子: ");
    }else if(type == 3){
        prmtext.push_back("このプログラムを使用していただきありがとうございます");
        prmtext.push_back("このプログラムは、テキストファイル内のキーワードを含む文を検索するために使用されます");
        prmtext.push_back("テキストファイルは'text.txt'という名前でなければならず、実行可能ファイルと同じディレクトリにある必要があります");
        prmtext.push_back("現在、英語のみをサポートしています");
        prmtext.push_back("text.txtを開けませんでした");
        prmtext.push_back("検索するキーワードを入力してください('exit'と入力して終了): ");
        prmtext.push_back("キーワードを含む文が見つかりませんでした: ");
    }else if(type == 4){
        prmtext.push_back("Bienvenue dans ce programme");
        prmtext.push_back("Ce programme est utilisé pour rechercher des phrases contenant un mot-clé dans un fichier texte");
        prmtext.push_back("Le fichier texte doit être nommé 'text.txt' et doit se trouver dans le même répertoire que l'exécutable");
        prmtext.push_back("Prend actuellement en charge la recherche en anglais uniquement");
        prmtext.push_back("Impossible d'ouvrir text.txt");
        prmtext.push_back("Entrez un mot-clé à rechercher (ou tapez 'exit' pour quitter): ");
        prmtext.push_back("Aucune phrase contenant le mot-clé n'a été trouvée: ");
    }
}

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
    language(prmtext,language_type);//language setting
    
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

    // Split text into sentences
    vector<string> sentences = splitIntoSentences(text);

    // Build the hash table
    unordered_map<string, vector<string>> hashTable = buildHashTable(sentences);

    // Read queries from user input
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