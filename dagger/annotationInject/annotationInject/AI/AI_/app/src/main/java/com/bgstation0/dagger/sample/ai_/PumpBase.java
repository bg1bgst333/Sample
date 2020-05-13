package com.bgstation0.dagger.sample.ai_;

import javax.inject.Inject;

// パンプベース
public class PumpBase {

    // メンバフィールドの定義.
    //private final HeaterBase mHeater;

    // コンストラクタ
    @Inject
    //PumpBase(HeaterBase heater){
    PumpBase(){
        //mHeater = heater;
    }

    // 組み上げ
    public String pumping(){
        return "pumbbase";
        /*
        if (mHeater.getClass().equals(Heater1.class)) {   // Heater1
            return "large pumbbase";
        }
        else{   // Heater2
            return "small pumbbase";
        }
        */
    }

}