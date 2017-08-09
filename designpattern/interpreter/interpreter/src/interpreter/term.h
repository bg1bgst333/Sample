// 二重インクルード防止
#ifndef __TERM_H_
#define __TERM_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "operand.h" // interface_operand
#include "expression.h" // class_expression

// クラスclass_term
class class_term : public interface_operand{

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
    class_term(std::string str); // 引数付きコンストラクタ
    virtual ~class_term(); // デストラクタ
    // メンバ関数
    virtual void print(); // メンバ関数print
    virtual int execute();

};

#endif 
