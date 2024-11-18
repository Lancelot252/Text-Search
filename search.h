#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
// 加载文本并按句号分割成句子
vector<string> load_text(const string &filename) {
    ifstream file(filename);
    vector<string> sentences;
    if (!file) {
        cerr << "无法打开文件 " << filename << endl;
        return sentences;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();

    // 使用正则表达式分割文本，支持中英文句号
    regex sentence_regex(R"([^。.]+[。.]?)");
    auto words_begin = sregex_iterator(text.begin(), text.end(), sentence_regex);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        sentences.push_back((*i).str());
    }

    return sentences;
}
// 构建关键词和句子的索引哈希表
unordered_map<string, vector<int>> build_index(const vector<string> &sentences) {
    unordered_map<string, vector<int>> index;
    for (int i = 0; i < sentences.size(); ++i) {
        istringstream stream(sentences[i]);
        string word;
        while (stream >> word) {
            // 清理单词中的标点符号
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            if (!word.empty()) {
                index[word].push_back(i);
            }
        }
    }
    return index;
}
// 使用unordered_map<string, unordered_set<int>>来优化存储
unordered_map<string, unordered_set<int>> build_optimized_index(const vector<string> &sentences) {
    unordered_map<string, unordered_set<int>> index;
    for (int i = 0; i < sentences.size(); ++i) {
        istringstream stream(sentences[i]);
        string word;
        while (stream >> word) {
            // 清理单词中的标点符号
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            if (!word.empty()) {
                index[word].insert(i);
            }
        }
    }
    return index;
}

// 查找并输出包含关键词的句子，使用优化后的索引
void search_optimized_query(const unordered_map<string, unordered_set<int>> &index,
                            const vector<string> &sentences, const string &query) {
    auto it = index.find(query);
    if (it != index.end()) {
        cout << "查询 \"" << query << "\" 的结果：" << endl;
        for (int idx : it->second) {
            cout << " - " << sentences[idx] << endl;
        }
    } else {
        cout << "没有找到包含关键词 \"" << query << "\" 的句子。" << endl;
    }
}
// 使用平方探测法构建哈希表
unordered_map<string, vector<int>> build_quadratic_probing_index(const vector<string> &sentences) {
    unordered_map<string, vector<int>> index;
    for (int i = 0; i < sentences.size(); ++i) {
        istringstream stream(sentences[i]);
        string word;
        while (stream >> word) {
            // 清理单词中的标点符号
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            if (!word.empty()) {
                int hash_value = hash<string>{}(word);
                int j = 0;
                while (!index[word].empty()) {
                    hash_value = (hash_value + j * j) % index.bucket_count();
                    j++;
                }
                index[word].push_back(i);
            }
        }
    }
    return index;
}

// 使用线性探测法构建哈希表
unordered_map<string, vector<int>> build_linear_probing_index(const vector<string> &sentences) {
    unordered_map<string, vector<int>> index;
    for (int i = 0; i < sentences.size(); ++i) {
        istringstream stream(sentences[i]);
        string word;
        while (stream >> word) {
            // 清理单词中的标点符号
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            if (!word.empty()) {
                int hash_value = hash<string>{}(word);
                while (!index[word].empty()) {
                    hash_value = (hash_value + 1) % index.bucket_count();
                }
                index[word].push_back(i);
            }
        }
    }
    return index;
}

// 根据数据自动选择使用哪一种探测法
unordered_map<string, vector<int>> build_auto_index(const vector<string> &sentences) {
    if (sentences.size() > 1000) {
        return build_quadratic_probing_index(sentences);
    } else {
        return build_linear_probing_index(sentences);
    }
}
// 查找并输出包含关键词的句子
vector<string> search_query(const unordered_map<string, vector<int>>& index, const vector<string>& sentences, const string& query) {
    vector<string> results;
    auto it = index.find(query);
    if (it != index.end()) {
        for (int idx : it->second) {
            results.push_back(sentences[idx]);
        }
    }
    return results;
}

