package com.bgstation0.dagger.sample.am_;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import dagger.Component;

// メインアクティビティ
public class MainActivity extends AppCompatActivity {

    // メンバフィールドの定義
    private CoffeeShop coffeeShop;

    // アクティビティ生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // コーヒーショップの生成.
        //coffeeShop = DaggerMainActivity_CoffeeShop.create();    // DaggerMainActivity_CoffeeShop.createでcoffeeShopを作成.
        coffeeShop = DaggerMainActivity_CoffeeShop.builder().pumpBaseModule(new PumpBaseModule()).build();  // PumpBaseModuleに差し替え.

        // ドリップ.
        TextView textView1 = findViewById(R.id.textview1);  // textView1を取得.
        textView1.setText(coffeeShop.maker().drip());   // textView1.setTextにdrip.

    }

    // コーヒーメーカー(PumpBaseModuleを指定.)
    @Component(modules = PumpBaseModule.class)
    interface CoffeeShop{
        CoffeeMaker maker();
    }

}