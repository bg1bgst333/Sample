// ヘッダのインクルード
// 既定のヘッダ
#include <cctype> // C型チェック
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "expression.h" // class_expression

// メンバの定義
// 引数付きコンストラクタclass_expression(std::string str)
class_expression::class_expression(std::string str){

  // メンバにセット.
  str_ = str; // strをstr_に代入.
  std::string inner = str_; // str_をinnerにセット.
  operand1_ = NULL; // operand1_をNULLで初期化.
  operand2_ = NULL; // operand2_をNULLで初期化.
  std::string operand1_str; // オペランド1文字列.
  std::string operand2_str; // オペランド2文字列.
  operator_ = ""; // operator_を""で初期化.

  std::cout << "str = " <<str << std::endl;

  // +-の前と後を分ける.
  if (inner[0] == '(' && inner[inner.length() - 1] == ')'){ // 括弧で囲まれている.
    int count = 0; // 括弧の階層.
    bool bracket_trim = true;
    for (int i = 0; i < inner.length(); i++){
      if (inner[i] == '('){ // 開き括弧.
        count++; // 増やす.
      }
      else if (inner[i] == ')'){ // 閉じ括弧.
        count--; // 減らす.
      }
      if (i < inner.length() - 1 && count == 0){ // 途中で0の場合.
        bracket_trim = false; // トリムしない.
        break; // 抜ける.
      }
    }
    if (bracket_trim){ // bracket_trimが真.
      inner = inner.substr(1, inner.length() - 2); // 括弧を除く.
    }
  }
  int count = 0; // 括弧の階層.
  bool plusminus = false; // +-がある時.
  for (int i = 0; i < inner.length(); i++){ // inner.length()の分だけ繰り返す.
    if (inner[i] == '('){ // 開き括弧.
      count++; // 増やす.
    }
    else if (inner[i] == ')'){ // 閉じ括弧.
      count--; // 減らす.
    }
    if ((inner[i] == '+' || inner[i] == '-') && count == 0){ // 括弧のない階層で+ or -.
      plusminus = true; // plusminusをtrueにセット.
      std::string temp = inner.substr(0, i); // tempに+-は含めない.
      int last = temp.find_last_not_of(" "); // 空白の前の位置.
      operand1_str = inner.substr(0, last + 1); // オペランド1を取得.
      operator_ = inner[i]; // operator_にinner[i]を代入.
      std::string temp2 = inner.substr(i + 1, inner.length() - (i + 1)); // 後ろをtemp2に格納.
      int next = temp2.find_first_not_of(" "); // 空白の後の位置.
      operand2_str = temp2.substr(next, temp2.length() - next); // オペランド2を取得.
      operand1_ = new class_expression(operand1_str); // operand1_を生成.
      operand2_ = new class_expression(operand2_str); // operand2_を生成.
      break; // 抜ける.
    }
  }
  if (!plusminus){ // plusminusがない.
    operand1_str = inner; // operand1_strにinnerをセット.
    operand1_ = new class_term(operand1_str); // operand1_を生成.
  }

  std::cout << "operand1_str = " << operand1_str << std::endl;
  std::cout << "operand2_str = " << operand2_str << std::endl;
  std::cout << "operator_ = " << operator_ << std::endl;

}

// デストラクタ~class_expression
class_expression::~class_expression(){

  // NULLでなければ破棄.
  if (operand1_ != NULL){ // operand1_がNULLでない.
    delete operand1_; // deleteでoperand1_を破棄.
    operand1_ = NULL; // operand1_にNULLを代入.
  }
  if (operand2_ != NULL){ // operand2_がNULLでない.
    delete operand2_; // deleteでoperand2_を破棄.
    operand2_ = NULL; // operand2_にNULLを代入.
  }

}

// メンバ関数print
void class_expression::print(){

  // str_を出力.
  std::cout << str_ << std::endl; // str_を出力.

}

int class_expression::execute(){

  if (operator_ == "+"){
    return operand1_->execute() + operand2_->execute();
  }
  else if (operator_ == "-"){
    return operand1_->execute() - operand2_->execute();
  }
  else{
    return operand1_->execute();
  }

}
