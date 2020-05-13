package com.bgstation0.dagger.sample.ai_;

import javax.inject.Inject;

// パンプ1
public class Pump1 extends PumpBase{

    // コンストラクタ
    @Inject
    Pump1(){

    }

    // 組み上げ
    @Override
    public String pumping(){
        return "pumb1";
    }

}