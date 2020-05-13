package com.bgstation0.dagger.sample.ai_;

import javax.inject.Inject;

// コーヒーメーカー
public class CoffeeMaker {

    // メンバフィールドの定義
    //@Inject Heater1 heater;
    @Inject Heater2 heater;
    //@Inject Pump1 pump;
    @Inject Pump2 pump;
    //@Inject PumpBase pump;

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
