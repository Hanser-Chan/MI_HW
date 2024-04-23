#include <iostream>
#include <string>
#include <unordered_map>
#include <format>

using std::string,std::cout,std::cin;

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
    enDic["world"] = "世界";
    enDic["xiaomi"] = "小米";
    enDic["cjj"] = "cjj向你打招呼并点头说你好";
    enDic["meme"] = "模因";

    // 中文->英文
    zhDic["你好"] = "hello";
    zhDic["世界"] = "world";
    zhDic["小米"] = "xiaomi";
    zhDic["cjj向你打招呼并点头说你好"] = "cjj";
    zhDic["模因"] = "meme";
}

int main() {
    string word{};
    std::unordered_map<string, string> enDic,zhDic;

    initDic(enDic,zhDic);

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
