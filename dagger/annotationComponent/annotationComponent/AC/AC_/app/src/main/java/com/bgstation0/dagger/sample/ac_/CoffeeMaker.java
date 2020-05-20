package com.bgstation0.dagger.sample.ac_;

import javax.inject.Inject;

// コーヒーメーカー
public class CoffeeMaker {

    // メンバフィールドの定義
    @Inject Heater1 heater;
    @Inject PumpBase pump;

    // コンストラクタの定義
    @Inject
    CoffeeMaker(){

    }

    // ドリップ.
    public String drip(){
        String dripStr = "";
        dripStr = dripStr + heater.heating();
        dripStr = dripStr + pump.pumping();
        return dripStr;
    }

}
