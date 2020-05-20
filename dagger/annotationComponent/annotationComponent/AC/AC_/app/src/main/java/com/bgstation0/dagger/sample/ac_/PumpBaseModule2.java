package com.bgstation0.dagger.sample.ac_;

import dagger.Module;
import dagger.Provides;

// パンプベースモジュール.
@Module
public class PumpBaseModule2 {

    // パンプベースの提供.
    @Provides
    static PumpBase providePumpBase2(Pump2 pump2){
        return pump2;   // pump2を返す.
    }

}
