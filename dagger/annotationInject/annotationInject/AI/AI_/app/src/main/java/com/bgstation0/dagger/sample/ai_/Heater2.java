package com.bgstation0.dagger.sample.ai_;

import javax.inject.Inject;

// ヒーター2
public class Heater2 extends HeaterBase {

    // コンストラクタ
    @Inject
    Heater2(){

    }

    // 加熱
    @Override
    public String heating(){
        mIsHot = true;
        return "heater2";
    }

}
