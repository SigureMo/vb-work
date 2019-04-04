#include <iostream>
#include <cmath>
#include "arithmetic_unit.hpp"
#include "operand.hpp"
#include "operator.hpp"
#include "compute.hpp"

using namespace std;

/**
 * @ref: 中M 浙江大学 数据结构 2.2 堆栈应用 表达式求值
 */

int main(void) {

  // test
  // Support +-*/^()
  while (true) {
    string expression;
    string tmp_expression;
    checkVars();
    cout << "> ";
    do {
      getline(cin, tmp_expression);
      for (int i = 0; i < tmp_expression.size(); i++) {
        if (tmp_expression[i] != ' ') {
          expression += tmp_expression[i];
        }
      }
    } while (expression[expression.size()-1] != '=');
    fillArithmeticUnitVector(expression);
    cout << "> " << computeValue() << endl;
    checkVars();
  }

  // TODO
  // [ ] 垃圾回收问题
  // [+] 负号的问题
  // [ ] 变量的支持
  // [ ] 一元运算符（前缀、后缀）
  return 0;
}
