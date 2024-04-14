#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <regex>
using namespace std;
using ll = long long;

map<int, string> commas = {
    {0, ""},
    {1, "thousand"},
    {2, "million"},
    {3, "billion"},
    {4, "trillion"}
};

map<int, string> numInEnglish = {
    {0, ""}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
    {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
    {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}
};

// 英語で表現された数字を数値に変換する
// long long EnglishToNumber(vector<string> str_num) {
//     return 0;
// }

// 1000未満の数値を英語に変換する
string lessThan1000(int num) {
    if(numInEnglish.find(num) != numInEnglish.end()) {
        return numInEnglish[num];
    }

    string res = "";
    int less_than_100 = num % 100;
    if(less_than_100 >= 10 && less_than_100 <= 19) {
        res = numInEnglish[less_than_100];
    } else {
        int tens_place = less_than_100 - less_than_100%10, ones_place = less_than_100%10;
        res = numInEnglish[tens_place] + " " + numInEnglish[ones_place];
    }
    num -= less_than_100;
    num /= 100;
    if(num != 0) {
        res = numInEnglish[num] + " hundred " + res;
    }
    return res;
}

// 半角スペースが2つ続いていた場合に1つのみにする
string removeExtraSpaces(const string& str) {
    string result;
    bool prevWasSpace = false;

    for (char c : str) {
        if (c == ' ') {
            if (!prevWasSpace) {
                result += c;
                prevWasSpace = true;
            }
        } else {
            result += c;
            prevWasSpace = false;
        }
    }

    return result;
}

// 数値を英語で表現された数字に変換する
string numberToEnglish(long long num) {
    if(num == 0) return "Zero";

    int count = 0;
    string res = "";
    while(num != 0) {
        int tmp = num % 1000;
        if(tmp != 0) res = lessThan1000(tmp) + " " + commas[count] + " " + res;
        num -= tmp;
        num /= 1000;
        count++;
    }

    res = removeExtraSpaces(res);
    res[0] -= 32;
    return res;
}

vector<string> stringToVector() {
    string s;
    getline(cin, s);
    vector<string> res;
    stringstream ss(s);
    while (getline(ss, s, ' ')) {
        res.push_back(s);
    }
    return res;
}

// 英語で表現された数字を入力として受け取り、その数字と任意の数字との和を計算する
int main() {
    // vector<string> S =stringToVector();
    // S[0][0] += 32;

    int a; cin >> a;
    cout << numberToEnglish(a) << endl;

    //long long num = EnglishToNumber(S);
    //cout << num << endl;
    //num++;
    //cout << numberToEnglish(num) << endl;
}
