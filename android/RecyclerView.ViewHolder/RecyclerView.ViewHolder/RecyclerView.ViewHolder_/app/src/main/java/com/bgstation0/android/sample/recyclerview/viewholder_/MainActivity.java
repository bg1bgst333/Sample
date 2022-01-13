package com.bgstation0.android.sample.recyclerview.viewholder_;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.animation.LinearInterpolator;
import android.widget.Toast;
import android.widget.Toolbar;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends /*AppCompatActivity*/ Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ツールバーのセット.
        Toolbar toolbar1 = findViewById(R.id.toolbar1); // toolbar1を取得.
        toolbar1.setLogo(R.mipmap.logo1);   // logo1をセット.
        toolbar1.setTitle(R.string.title_string);   // title_stringをセット.
        toolbar1.setSubtitle(R.string.subtitle_string); // subtitle_stringをセット.
        setActionBar(toolbar1); // setActionBarでtoolbar1をセット.

        // recyclerview1の取得.
        RecyclerView recyclerview1 = (RecyclerView)findViewById(R.id.recyclerview1);    // recyclerview1を取得.
        Toast.makeText(this, "recyclerview1 = " + recyclerview1.toString(), Toast.LENGTH_LONG).show();  // recyclerview1の取得.

        // LayoutManagerのセット.
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(MainActivity.this);
        recyclerview1.setLayoutManager(linearLayoutManager);

        // ArrayListで追加する要素を定義.
        List<ListItem> items = new ArrayList<ListItem>();	// itemsを取得.
        for (int i = 0; i < 10000; i++){	// アイテム追加.
            ListItem item = new ListItem();
            item.name = "Name" + Integer.toString(i);	// 名前に表示する文字列をセット.
            item.address = "Address" + Integer.toString(i); // 住所に表示する文字列をセット
            items.add(item);	// itemを追加.
        }

        // アダプタのセット.
        CustomAdapter customAdapter = new CustomAdapter(this, items);
        recyclerview1.setAdapter(customAdapter);

    }

}