package com.bgstation0.android.sample.clt_;

import android.support.design.widget.CoordinatorLayout;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.view.View;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ツールバーをアクションバーとしてセット.
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);  // toolbarを取得.
        setSupportActionBar(toolbar);   // setSupportActionBarでtoolbarをセット.

        // FABを取得し, リスナーをセット.
        FloatingActionButton floatingActionButton = (FloatingActionButton) findViewById(R.id.fab);   // floatingActionButtonを取得.
        floatingActionButton.setOnClickListener(this);  // floatingActionButton.setOnClickListenerにthisをセット.
    }

    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v) {    // onClickをオーバーライド.

        // ボタンのidをごとに処理を振り分ける.
        switch (v.getId()) {    // v.getIdでView(Button)のidを取得.

            case R.id.fab:    // R.id.fabの時.

                // スナックバーの表示.
                CoordinatorLayout cl = (CoordinatorLayout)findViewById(R.id.coordinatorLayout); // CoordinatorLayoutオブジェクトclを取得.
                Snackbar.make(cl, "Snackbar", Snackbar.LENGTH_LONG).show(); // Snackbarで"Snackbar"と表示.(この時, clを指定する.)

                // 抜ける.
                break;    // breakで抜ける.

        }

    }

}