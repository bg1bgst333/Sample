// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// クラスclass_elementの定義
class class_element{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string name_; // std::stringメンバオブジェクトname_.
    int num_; // int型メンバ変数num_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタ
    class_element(); // コンストラクタclass_element.
    class_element(std::string name, int num); // 引数付きコンストラクタclass_element.
    // メンバ関数
    void set_name(std::string name); // nameをセットするset_name.
    std::string get_name(); // nameを取得するget_name.
    void set_num(int num); // numをセットするset_num.
    int get_num(); // numを取得するget_num.

};
