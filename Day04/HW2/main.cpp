#include <iostream>
#include <string>
#include <unordered_map>
#include <format>
#include <vector>
#include <utility>

using std::string,std::cout,std::cin,std::vector,std::pair;


string FindWord(std::unordered_map<string,string> &map, const string& str){
    if (auto search{map.find(str)}; search != map.end()){
        return search->second;

    }else {
        return "未找到对应词汇";
    }
}

void initDic(std::unordered_map<string, string>& enDic,
             std::unordered_map<string, string>& zhDic) {

    // 英文->中文
    enDic["hello"] = "你好";
    enDic["xiaomi"] = "小米";
    enDic["cjj"] = "cjj向你打招呼并点头说你好";
    enDic["meme"] = "模因";

    // 中文->英文
    zhDic["你好"] = "hello";
    zhDic["小米"] = "xiaomi";
    zhDic["cjj向你打招呼并点头说你好"] = "cjj";
    zhDic["模因"] = "meme";
}
/* 可以使用pair来初始化
 * 这样就不用写一堆了
 * */
void initDic(std::unordered_map<string, string>& enDic,
             std::unordered_map<string, string>& zhDic,
             vector<pair<string,string> > vec) {

    for (const auto& v : vec) {

        enDic[v.first] = v.second;

        zhDic[v.second] = v.first;
    }
}

int main() {
    string word{};
    std::unordered_map<string, string> enDic,zhDic;
    vector<pair<string, string> > dic{
            {"hello","你好"},
            {"xiaomi","小米"},
            {"cjj","cjj向你打招呼并点头说你好"},
            {"meme","模因"}
    };

    initDic(enDic,zhDic,dic);

    cout << "请输入单词（输入exit！即可退出）：";
    while(std::getline(cin, word)){

        if (word == "exit!") break;

        string trans {FindWord(enDic,word)};
        if (trans == "未找到对应词汇") {
            trans = FindWord(zhDic,word);
        }
        if (trans == "未找到对应词汇"){
            cout << trans << "\n";
            continue;
        }
        cout << std::format("{} 的意思是： {}\n",word,trans);
    }


    return 0;
}
