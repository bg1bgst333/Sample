package com.bgstation0.android.sample.context_;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.os.Bundle;
import android.text.Editable;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // オプションメニューが作成される時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){

    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	return true;	// trueを返す.
    	
    }
    
    // メニューが選択された時.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    	
    	// どのメニューが選択されたか.
    	switch (item.getItemId()){	// アイテムIDごとに振り分け.
    	
    		// Write file
    		case R.id.menu_write_file:
    			
    			// Write file ブロック
    			{
    				
    				// ファイル名を取得.
    				EditText edittextName = (EditText)findViewById(R.id.edittext_filename);	// findViewByIdでedittext_filenameを取得.
    				Editable textName = edittextName.getText();	// edittextName.getTextでテキスト取得.
    				String filename = textName.toString();	// textName.toStringで文字列取得.
    			
    				// ファイル内容を取得.
    				EditText edittextContent = (EditText)findViewById(R.id.edittext_filecontent);	// findViewByIdでedittext_filecontentを取得.
    				Editable textContent = edittextContent.getText();	// edittextContent.getTextでテキスト取得.
    				String filecontent = textContent.toString();	// textContent.toStringで文字列取得.
    			
    				// ファイル名チェック.
    				if (filename.length() == 0){
    					Toast.makeText(this, "filename is empty!", Toast.LENGTH_SHORT).show();	// "filename is empty!"と表示.
    					break;	// 途中で抜ける.
    				}
    			
    				// ファイルに書き込む.
    				try{	// tryで囲む.
    					FileOutputStream out = openFileOutput(filename, MODE_PRIVATE);	// openFileOutputでfilenameのファイルを開いてファイル出力ストリームを取得.
    					out.write(filecontent.getBytes());	// out.writeでfilecontentを書き込む.
    					out.close();	// out.closeで閉じる.
    				}
    				catch (FileNotFoundException fileNotEx){	// ファイルが見つからない.
    					Toast.makeText(this, "File not found!", Toast.LENGTH_SHORT).show();	// "File not found!"と表示.
    				}
    				catch (IOException ioEx){	// IOエラー.
    					Toast.makeText(this, "IO error!", Toast.LENGTH_SHORT).show();	// "IO Error!"と表示.
    				}
    				break;	// ここで抜ける.
    				
    			}
    			
    		// Read file
    		case R.id.menu_read_file:
    			
    			// Read file ブロック
    			{
    				
    				// ファイル名を取得.
    				EditText edittextName = (EditText)findViewById(R.id.edittext_filename);	// findViewByIdでedittext_filenameを取得.
    				Editable textName = edittextName.getText();	// edittextName.getTextでテキスト取得.
    				String filename = textName.toString();	// textName.toStringで文字列取得.
    				
    				// ファイル名チェック.
    				if (filename.length() == 0){
    					Toast.makeText(this, "filename is empty!", Toast.LENGTH_SHORT).show();	// "filename is empty!"と表示.
    					break;	// 途中で抜ける.
    				}
    				
    				// ファイルから読み込む.
    				try{	// tryで囲む.
    					FileInputStream in = openFileInput(filename);	// openFileInputでfilenameのファイルを開いてファイル入力ストリームを取得.
    					byte[] bytes = new byte[in.available()];	// in.availableでファイル入力ストリームが読み込める推定サイズがわかるので, その分のバイト列確保.
    	                in.read(bytes);	// in.readで読み込む.
    	                String content = new String(bytes);	// 文字列に変換.
    	                EditText edittextContent = (EditText)findViewById(R.id.edittext_filecontent);	// findViewByIdでedittext_filecontentを取得.
    	                edittextContent.setText(content);	// edittextContent.setTextでテキストをセット.
    	                in.close();	// in.closeで閉じる.
    				}
    				catch (FileNotFoundException fileNotEx){	// ファイルが見つからない.
    					Toast.makeText(this, "File not found!", Toast.LENGTH_SHORT).show();	// "File not found!"と表示.
    				}
    				catch (IOException ioEx){	// IOエラー.
    					Toast.makeText(this, "IO error!", Toast.LENGTH_SHORT).show();	// "IO Error!"と表示.
    				}
    				break;	// ここで抜ける.
    				
    			}
    	}
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    }
}