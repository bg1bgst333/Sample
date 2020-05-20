package com.bgstation0.dagger.sample.ac_;

import javax.inject.Inject;

// ヒーターベース
public class HeaterBase {

    // メンバフィールドの定義
    public Boolean mIsHot = false;

    // コンストラクタ
    @Inject
    HeaterBase(){

    }

    // 加熱
    public String heating(){
        mIsHot = true;
        return "heaterbase";
    }

    // 温かいかどうか判定.
    public Boolean isHot(){
        return mIsHot;
    }

}
