package com.bgstation0.android.sample.autocompletetextview_;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // AutoCompleteTextViewにadapterをセット.
        ArrayList<String> strArrayList = new ArrayList<String>();	// strArrayListを作成.
        strArrayList.add("AAC");	// "AAC"
        strArrayList.add("ABC");	// "ABC"
        strArrayList.add("ABCDE");	// "ABCDE"
        strArrayList.add("BBB");	// "BBB"
        strArrayList.add("CCC");	// "CCC"
        strArrayList.add("PQRS");	// "PQRS"
        strArrayList.add("VWXYZ");	// "VWXYZ"
        strArrayList.add("XYZ");	// "XYZ"
        strArrayList.add("ZZZ");	// "ZZZ"
        AutoCompleteTextView autoCompleteTextView = (AutoCompleteTextView)findViewById(R.id.autocompletetextview1);	// autoCompleteTextViewを取得.
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.auto_complete_list_item, strArrayList);	// adapter作成.
        autoCompleteTextView.setAdapter(adapter);	// adapterをセット.
        autoCompleteTextView.setThreshold(1);	// 1文字入力したらオートコンプリート開始.
        
    }
    
}