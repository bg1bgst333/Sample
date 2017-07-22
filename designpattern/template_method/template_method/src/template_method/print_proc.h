// 二重インクルード防止
#ifndef __PRINT_PROC_H_
#define __PRINT_PROC_H_

// クラスclass_print_procの定義
class class_print_proc{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_proc(){}; // コンストラクタclass_print_proc
    virtual ~class_print_proc(){}; // デストラクタ~class_print_proc
    // メンバ関数
    virtual bool begin_print() = 0; // 前処理用純粋仮想関数begin_print
    virtual bool print() = 0; // 本処理用純粋仮想関数print
    virtual bool end_print() = 0; // 後処理用純粋仮想関数end_print
    void template_method(); // テンプレートメソッドtemplate_method

};

#endif
