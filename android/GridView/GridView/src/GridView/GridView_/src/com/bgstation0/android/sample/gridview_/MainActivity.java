package com.bgstation0.android.sample.gridview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.GridView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // GridItem配列で追加する要素を定義.
        GridItem[] griditems = new GridItem[8];	// GridItem配列griditems(要素数8)
        for (int i = 0; i < 8; i++){	// 要素数の分繰り返す.
        	griditems[i] = new GridItem();	// GridItemオブジェクトインスタンスを生成し, 各要素に格納.
        }
        griditems[0].name = "one";
        griditems[0].colorno = 0;
        griditems[1].name = "two";
        griditems[1].colorno = 1;
        griditems[2].name = "three";
        griditems[2].colorno = 0;
        griditems[3].name = "four";
        griditems[3].colorno = 1;
        griditems[4].name = "five";
        griditems[4].colorno = 1;
        griditems[5].name = "six";
        griditems[5].colorno = 0;
        griditems[6].name = "seven";
        griditems[6].colorno = 1;
        griditems[7].name = "eight";
        griditems[7].colorno = 0;
        
        // GridViewオブジェクトを取得.
        GridView gridview1 = (GridView)findViewById(R.id.gridview1);	// findViewByIdでgridview1を取得.
        
        // GridItemAdapterのadapterを生成して, gridview1とadapterとgriditemsを紐付ける.
        GridItemAdapter adapter = new GridItemAdapter(this, R.layout.grid_item, griditems);	// GridItemAdapterコンストラクタにGridViewのアイテムテンプレートのgrid_itemとグリッドデータのgriditemsをセット.
        gridview1.setAdapter(adapter);	// gridview1.setAdapterにadapterをセットして, GridViewとAdapterを紐付ける.
    }
}
