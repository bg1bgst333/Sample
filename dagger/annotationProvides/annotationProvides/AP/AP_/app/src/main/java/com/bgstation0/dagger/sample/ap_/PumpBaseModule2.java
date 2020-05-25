package com.bgstation0.dagger.sample.ap_;

import dagger.Module;
import dagger.Provides;

// パンプベースモジュール2.
@Module
public class PumpBaseModule2 {

    // パンプベースの提供.
    @Provides
    static PumpBase providePumpBase(Pump2 pump2){
        return pump2;   // pump2を返す.
    }

    // ヒーターベースの提供
    @Provides
    static HeaterBase provideHeaterBase(){
        return new Heater2();
    }

}
