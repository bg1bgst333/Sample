package com.bgstation0.rxandroid.sample.as_;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import rx.Observable;
import rx.Subscriber;
import rx.Subscription;
import rx.android.schedulers.AndroidSchedulers;
import rx.functions.Action;
import rx.functions.Action1;
import rx.schedulers.Schedulers;

// メインアクティビティ.
public class MainActivity extends AppCompatActivity {

    // メンバフィールドの定義
    final String TAG = getClass().getName();    // TAGをクラス名で初期化.
    Subscription mSubscription = null;  // サブスクリプションをnullで初期化.
    Context mContext = null;    // コンテキストをnullで初期化.

    // アクティビティが生成された時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // オブザーバブルの生成.
        Observable<String> observable = Observable.create(new Observable.OnSubscribe<String>() {
            @Override
            public void call(Subscriber<? super String> subscriber) {
                // tryで囲む.
                try{
                    // 発行と休止の繰り返し.
                    subscriber.onNext("aaa");   // "aaa"を発行.
                    Thread.sleep(3000); // 3秒休止.
                    subscriber.onNext("bbb");   // "bbb"を発行.
                    Thread.sleep(3000); // 3秒休止.
                    subscriber.onNext("ccc");   // "ccc"を発行.
                    subscriber.onCompleted();   // 完了通知.
                }
                catch (Exception ex){   // 例外をキャッチ.
                    Log.d(TAG, ex.getMessage());    // メッセージをログに残す.
                }
            }
        }).subscribeOn(Schedulers.newThread())  // 新しいスレッドで実行.
        .observeOn(AndroidSchedulers.mainThread()); // Androidのメインスレッドで実行.

        // オブザーバブルに通知処理を登録.
        mSubscription = observable.subscribe(new Action1<String>(){
            @Override
            public void call(String s) {
                // TextViewにセット.
                TextView textView1 = findViewById(R.id.textview1);  // textView1を取得.
                textView1.setText(s);   // sをセット.
            }
        });

    }

    // アクティビティが破棄された時.
    @Override
    protected void onDestroy() {

        // 既定の処理.
        super.onDestroy();

        // サブスクリプションの破棄.
        mSubscription.unsubscribe();    // mSubscriptionをアンサブスクライブ.

    }

}