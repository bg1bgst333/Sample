// 二重インクルード防止
#ifndef __MODEL_H_
#define __MODEL_H_

// 既定のヘッダ
#include <string> // std::string

// クラスclass_model
class class_model{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string str1_; // メンバ変数str1_
    std::string str2_; // メンバ変数str2_
    std::string result_; // メンバ変数result_

  // 公開メンバ
  public:

    // 公開メンバ関数
    std::string func(std::string str1, std::string str2){

      // メンバのセット.
      str1_ = str1; // str1_にstr1をセット.
      str2_ = str2; // str2_にstr2をセット.

      // str1とstr2の連結.
      result_ = str1_ + str2_; // str1_とstr2_を連結してresult_に格納.

      // 返す.
      return result_; // result_を返す.

    }

};

#endif  
