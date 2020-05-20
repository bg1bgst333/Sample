package com.bgstation0.dagger.sample.ac_;

import javax.inject.Inject;

// パンプ1
public class Pump2 implements PumpBase{

    // コンストラクタ
    @Inject
    Pump2(){

    }

    // 組み上げ
    @Override
    public String pumping(){
        return "pumb2";
    }

}