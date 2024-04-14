#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;
ll mod = 1000000007;

map<int, string> commas = {
    {0, ""},
    {1, "thousand"},
    {2, "million"},
    {3, "billion"},
    {4, "trillion"}
};

map<int, string> num_in_English = {
    {0, ""}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
    {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
    {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}
};

// 英語で表現された数字を数値に変換する
long long English_to_Number(vector<string> str_num) {
    return 0;
}

// 1000未満の数値を英語に変換する
string less_than_1000(int num) {
    string res = "";
    int less_than_100 = num % 100;
    if(less_than_100 >= 10 && less_than_100 <= 19) {
        res = num_in_English[less_than_100];
    } else {
        int tens_place = less_than_100 - less_than_100%10, ones_place = less_than_100%10;
        res = num_in_English[tens_place] + " " + num_in_English[ones_place];
    }
    num -= less_than_100;
    num /= 100;
    if(num != 0) {
        res = num_in_English[num] + " hundred " + res;
    }
    return res;
}

// 数値を英語で表現された数字に変換する
string Number_to_English(long long num) {
    if(num == 0) return "Zero";

    int count = 0;
    string res = "";
    while(num != 0) {
        int tmp = num % 1000;
        res = commas[count] + less_than_1000(tmp) + res;
        num -= tmp;
        num /= 1000;
        count++;
    }

    res[0] -= 32;
    return res;
}

vector<string> String_to_Vector() {
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
    // vector<string> S = String_to_Vector();
    // S[0][0] += 32;

    int a; cin >> a;
    cout << less_than_1000(a) << endl;

    //long long num = English_to_Number(S);
    //cout << num << endl;
    //num++;
    //cout << Number_to_English(num) << endl;
}
