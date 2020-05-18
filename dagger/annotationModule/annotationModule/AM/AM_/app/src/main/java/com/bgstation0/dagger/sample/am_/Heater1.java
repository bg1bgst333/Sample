package com.bgstation0.dagger.sample.am_;

import javax.inject.Inject;

// ヒーター1
public class Heater1 extends HeaterBase {

    // コンストラクタ
    @Inject
    Heater1(){

    }

    // 加熱
    @Override
    public String heating(){
        mIsHot = true;
        return "heater1";
    }

}
