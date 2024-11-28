#include "head.h"

using namespace std;

// 将文本拆分成句子的函数
vector<string> splitIntoSentences(const string& text) {
    vector<string> sentences;
    stringstream ss(text);
    string sentence;
    while (getline(ss, sentence, '.')) {
        if (!sentence.empty()) {
            sentences.push_back(sentence + ".");//将句子存入vector
        }
    }
    return sentences;
}

// 构建哈希表的函数
unordered_map<string, vector<string>> buildHashTable(const vector<string>& sentences) {
    unordered_map<string, vector<string>> hashTable;//哈希表
    for (const auto& sentence : sentences) {
        stringstream ss(sentence);//将句子转换为字符串流
        string word;//存储单词
        while (ss >> word) {
            // 去除单词中的标点符号
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            hashTable[word].push_back(sentence);//将单词和句子存入哈希表
        }
    }
    return hashTable;
}

// 使用自定义哈希函数构建哈希表的函数
unordered_map<string, vector<string>> buildCustomHashTable(const vector<string>& sentences) {
    struct CustomHash {
        size_t operator()(const string& key) const {
            // 自定义哈希函数实现
            size_t hash = 0;
            for (char c : key) {
                hash = hash * 31 + c;
            }
            return hash;//返回哈希值
        }
    };

    unordered_map<string, vector<string>, CustomHash> hashTable;
    for (const auto& sentence : sentences) {
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            hashTable[word].push_back(sentence);
        }
    }
    return unordered_map<string, vector<string>>(hashTable.begin(), hashTable.end());
}

// 使用链式结构构建哈希表的函数
unordered_map<string, list<string>> buildChainedHashTable(const vector<string>& sentences) {
    unordered_map<string, list<string>> hashTable;
    for (const auto& sentence : sentences) {
        stringstream ss(sentence);//将句子转换为字符串流
        string word;//存储单词
        while (ss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());//去除单词中的标点符号
            hashTable[word].push_back(sentence);//将单词和句子存入哈希表
        }
    }
    return hashTable;
}

// 在链式哈希表中搜索关键字的函数
list<string> searchKeyword(const unordered_map<string, list<string>>& hashTable, const string& keyword) {
    auto it = hashTable.find(keyword);//在哈希表中查找关键字
    if (it != hashTable.end()) {
        return it->second;
    }
    return {};
}

// 在哈希表中搜索关键字的函数
vector<string> searchKeyword(const unordered_map<string, vector<string>>& hashTable, const string& keyword) {
    auto it = hashTable.find(keyword); // 在哈希表中查找关键字
    if (it != hashTable.end()) {
        return it->second;
    }
    return {};
}

void language(vector<string> &prmtext, int type) {
    if (type == 1) {
        prmtext.push_back("welcome to use this program");
        prmtext.push_back("This program is used to search for sentences containing a keyword in a text file");
        prmtext.push_back("The text file must be named 'text.txt' and must be in the same directory as the executable");
        prmtext.push_back("Currently only supports searching in English");
        prmtext.push_back("Failed to open text.txt");
        prmtext.push_back("Please choose your hash function (1. Default 2. Custom 3. Chained): ");
        prmtext.push_back("Enter a keyword to search (or type 'exit' to quit): ");
        prmtext.push_back("No sentences found containing the keyword: ");
    } else if (type == 2) {
        prmtext.push_back("欢迎使用本程序");
        prmtext.push_back("本程序用于在文本文件中搜索包含关键字的句子");
        prmtext.push_back("文本文件必须命名为'text.txt'，并且必须与可执行文件在同一目录中");
        prmtext.push_back("目前仅支持英文搜索");
        prmtext.push_back("无法打开text.txt");
        prmtext.push_back("请选择您的哈希函数（1. 默认 2. 自定义 3. 链式）：");
        prmtext.push_back("输入要搜索的关键字（或输入'exit'退出）：");
        prmtext.push_back("未找到包含关键字的句子：");
    } else if (type == 3) {
        prmtext.push_back("このプログラムを使用していただきありがとうございます");
        prmtext.push_back("このプログラムは、テキストファイル内のキーワードを含む文を検索するために使用されます");
        prmtext.push_back("テキストファイルは'text.txt'という名前でなければならず、実行可能ファイルと同じディレクトリにある必要があります");
        prmtext.push_back("現在、英語のみをサポートしています");
        prmtext.push_back("text.txtを開けませんでした");
        prmtext.push_back("ハッシュ関数を選択してください（1. デフォルト 2. カスタム 3. チェイン）：");
        prmtext.push_back("検索するキーワードを入力してください（'exit'と入力して終了）：");
        prmtext.push_back("キーワードを含む文が見つかりませんでした：");
    } else if (type == 4) {
        prmtext.push_back("Bienvenue dans ce programme");
        prmtext.push_back("Ce programme est utilisé pour rechercher des phrases contenant un mot-clé dans un fichier texte");
        prmtext.push_back("Le fichier texte doit être nommé 'text.txt' et doit se trouver dans le même répertoire que l'exécutable");
        prmtext.push_back("Prend actuellement en charge la recherche en anglais uniquement");
        prmtext.push_back("Impossible d'ouvrir text.txt");
        prmtext.push_back("Veuillez choisir votre fonction de hachage (1. Par défaut 2. Personnalisé 3. Chaîné) :");
        prmtext.push_back("Entrez un mot-clé à rechercher (ou tapez 'exit' pour quitter) :");
        prmtext.push_back("Aucune phrase contenant le mot-clé n'a été trouvée :");
    }
}