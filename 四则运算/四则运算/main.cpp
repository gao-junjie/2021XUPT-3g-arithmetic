//
//  main.cpp
//  四则运算
//
//  Created by mac on 2021/9/26.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
using namespace std;
char operation[1000];
    
int Calculate (int a, char b, int c) {
    if (b == '+') {
        return a + c;
    } else if (b == '-') {
        return a - c;
    } else if (b == '*') {
        return a * c;
    } else if (b == '/') {
        return a / c;
    }
    return 0;
}
    
int Compare (char a) {
    if (a == '+' || a == '-') {
        return 1;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == '#') {
        return 0;
    } else cout << "格式错误";
    return 0;
}
    
int main(int argc, const char * argv[]) {
    
    int numberStack[100] = {0};
    int numberTop = -1;
        
    char symbolStack[100] = {'#'};
    int symbolTop = -1;
        
    int tempNumber = 0;
    bool judge = false;
        
    cin >> operation;
        
    for (int i = 0; i < strlen(operation); i++) {
        if (operation[i] >= '0' && operation[i] <= '9') {
            tempNumber = tempNumber * 10 + operation[i] - '0';
            judge = false;
        } else {
            if (judge == false) {
                numberStack[++numberTop] = tempNumber;
                tempNumber = 0;
                judge = true;
            }
            if (symbolTop == -1) {
                symbolStack[++symbolTop] = operation[i];
            } else if (Compare(symbolStack[symbolTop]) < Compare(operation[i])) {
                symbolStack[++symbolTop] = operation[i];
            } else {
                int a = numberStack[numberTop--];
                char b = symbolStack[symbolTop--];
                int c = numberStack[numberTop--];
                tempNumber = Calculate (a, b, c);
                numberStack[++numberTop] = tempNumber;
                if (operation[i] == '#') {
                    cout << numberStack[numberTop] << endl;
                    break;
                }
                tempNumber = 0;
                i--;
            }
        }
    }
}
