package com.bgstation0.dagger.sample.ac_;

import dagger.Module;
import dagger.Provides;

// パンプベースモジュール.
@Module
public class PumpBaseModule {

    // パンプベースの提供.
    @Provides
    static PumpBase providePumpBase(Pump1 pump1){
        return pump1;   // pump1を返す.
    }

}
