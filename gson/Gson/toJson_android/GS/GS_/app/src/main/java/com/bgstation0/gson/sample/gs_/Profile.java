package com.bgstation0.gson.sample.gs_;

// プロファイルクラス
public class Profile {

    // メンバフィールドの定義
    public String name;	// 名前
    public String email;	// 電子メール

    // コンストラクタの定義.
    public Profile(String name, String email) {	// Profileを生成.
        this.name = name;	// this.nameにnameを渡す.
        this.email = email;	// this.emailにemailを渡す.
    }

}
