// 二重インクルード防止
#ifndef __EXPRESSION_H_
#define __EXPRESSION_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "operand.h" // interface_operand
#include "term.h" // class_term

// クラスclass_expression
class class_expression : public interface_operand{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string str_; // 式文字列
    interface_operand *operand1_; // オペランド1
    interface_operand *operand2_; // オペランド2
    std::string operator_; // オペレータ

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_expression(std::string str); // 引数付きコンストラクタ
    virtual ~class_expression(); // デストラクタ
    // メンバ関数
    virtual void print(); // メンバ関数print
    virtual int execute();

};

#endif 
