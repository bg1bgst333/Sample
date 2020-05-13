package com.bgstation0.dagger.sample.ai_;

import javax.inject.Inject;

// パンプ2
public class Pump2 extends PumpBase{

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