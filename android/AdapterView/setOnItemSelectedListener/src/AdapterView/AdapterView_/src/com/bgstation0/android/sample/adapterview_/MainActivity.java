package com.bgstation0.android.sample.adapterview_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext;	// ContextオブジェクトmContext.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContextにthisをセット.
        
        // ArrayAdapterの生成.
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item);	// 既定のandroid.R.layout.simple_spinner_itemでアダプタ作成.
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);	// ドロップダウンリスト表示時のビューは既定のandroid.R.layout.simple_spinner_dropdown_itemをセット.
        // アイテムの追加.
        adapter.add("Item1");	// Item1を追加.
        adapter.add("item2");	// Item2を追加.
        adapter.add("Item3"); 	// Item3を追加.
        // スピナーにアダプタをセット.
        final Spinner spinner = (Spinner)findViewById(R.id.spinner);	// spinnerを取得.(finalにしておく.)
        spinner.setAdapter(adapter);	// adapterをセット.
        // ボタンのクリックリスナーをセット.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String itemStr = (String)spinner.getSelectedItem();	// AdapterView.getSelectedItemで選択されたアイテムitemStrを取得.
				Toast.makeText(mContext, itemStr, Toast.LENGTH_LONG).show();	// itemStrを表示.
			}
			
        });
        // スピナーでアイテムが選択された時のリスナーをセット.
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
        	
        	 @Override
        	 public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        		 
        		 // 選択されたアイテムの取得.
        		 Spinner spnr = (Spinner)parent;	// parentをキャストspnrに.
        		 String itemStr = (String)spnr.getSelectedItem();	// spnr.getSelectedItemでitemStr取得.
        		 Toast.makeText(mContext, itemStr, Toast.LENGTH_LONG).show();	// itemStrを表示.
        		 
        	 }
        	 
        	 @Override
             public void onNothingSelected(AdapterView<?> arg0) {
             
        	 }
        	 
        });
        
    }
    
}