package com.bgstation0.dagger.sample.ac_;

import javax.inject.Inject;

// パンプ1
public class Pump1 implements PumpBase{

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