package com.bgstation0.android.sample.sqliteopenhelper_;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentValues;
import android.content.DialogInterface;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	public List<ListItem> list = null;	// ListItem型Listオブジェクトlistをnullにしておく.
	public ListView listView1 = null;	// ListViewオブジェクトlistview1をnullにしておく.
	public ListItemAdapter adapter = null;	// ListItemAdapterオブジェクトadapterをnullにしておく.
	public ListItemDBHelper hlpr = null;	// ListItemDBHelperオブジェクトhlprをnullにしておく.
	public SQLiteDatabase sqlite = null;	// SQLiteDatabaseオブジェクトsqliteをnullにしておく.
	
	// メンバメソッドの定義.
	// アクティビティが作成される時.
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // listオブジェクトの作成.
        list = new ArrayList<ListItem>();	// ArrayList<ListItem>インスタンスを作成してlistに格納.
        // adapterの取得.
        adapter = new ListItemAdapter(this, R.layout.list_item, list);	// ListItemAdapterのコンストラクタにlistを渡して, adapter取得.
        // listView1の取得.
        listView1 = (ListView)findViewById(R.id.listview1);	// findViewByIdでlistView1を取得.
        // listView1にadapterをセット.
        listView1.setAdapter(adapter);	// listView1.setAdapterでadapterをセット.
        
        // DBからの読み込み.
		try{
			if (hlpr == null){	// hlprがnullなら.
				hlpr = new ListItemDBHelper(getApplicationContext());	// hlprを作成.
			}
			if (sqlite == null){	// sqliteがnullなら.
				sqlite = hlpr.getReadableDatabase();	// 読み込み可能DBを取得.
			}
			Cursor cursor = null;	// Cursorオブジェクトcursorをnull.
			cursor = sqlite.rawQuery("SELECT * FROM listitem;", null);	// sqlite.rawQueryで"SELECT * FROM listitem;"を実行.
			int c = cursor.getCount();	// getCountで見つかった個数を取得し, cに格納.
			cursor.moveToFirst();	// cursorを最初の位置に移動.
			for (int i = 0; i < c; i++){	// cの数だけ繰り返し.
				
				// テーブルから取り出し.
				int _id = cursor.getInt(0);	// 0列目は_id.
				String name = cursor.getString(1);	// 1列目はname.
				int age = cursor.getInt(2);	// 2列目はage.
				String address = cursor.getString(3);	// 3列目はaddress.
				
				// アイテムの追加
				ListItem item = new ListItem();	// ListItemオブジェクトitemを生成.
				item.name = name;	// item.nameにname.
				item.age = age;	// item.ageにage. 
				item.address = address;	// item.addressにaddress.
				list.add(item);	// list.addでitemを追加.
				
				// 次へ移動.
				cursor.moveToNext();	// cursor.moveToNextで次へ移動.
			}
			cursor.close();	// cursorを閉じる.
		}
		catch (Exception ex){	// 例外キャッチ.
			Log.e("SQLiteOpenHelper_", ex.toString());	// ex.toStringをLogに出力.
		}
		finally{
			sqlite.close();	// sqlite.closeで閉じる.
			sqlite = null;	// null入れておく.
		}
		
		// アダプタの更新.
		adapter.notifyDataSetChanged();	// adapter.notifyDataSetChangedでUI更新.
		
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
    	
    		// Add
    		case R.id.menu_add:
    			
    			// Addブロック
    			{
    				
    				// アラートダイアログ作成.
    				LayoutInflater inflater = (LayoutInflater)getSystemService(LAYOUT_INFLATER_SERVICE);	// inflaterサービスを取得.
    				final View layout = inflater.inflate(R.layout.dialog, null);	// inflateでリソースR.layout.dialogからダイアログのViewを作成.
    				AlertDialog.Builder builder = new AlertDialog.Builder(this);	// AlertDialog.Builderの作成.
    				builder.setTitle("Add");	// setTitleでタイトルに"Add"をセット.
    				builder.setView(layout);	// setViewでビューにlayoutをセット.
    				builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// setPositiveButtonで"OK"ボタンのリスナーをセット.
    					
						@Override
						public void onClick(DialogInterface dialog, int which) {
							// TODO Auto-generated method stub
							// エディットテキストの内容を取得.
							EditText editName = (EditText)layout.findViewById(R.id.edit_text_name);	// editNameを取得.
							String strName = editName.getText().toString();	// セットされているテキストを取得.
							EditText editAge = (EditText)layout.findViewById(R.id.edit_text_age);	// editAgeを取得.
							String strAge = editAge.getText().toString();	// セットされているテキストを取得.
							int intAge = Integer.parseInt(strAge);	// intに変換.
							EditText editAddress = (EditText)layout.findViewById(R.id.edit_text_address);	// editAddressを取得.
							String strAddress = editAddress.getText().toString();	// セットされているテキストを取得.
							
							// DBへの追加.
							try{
								if (hlpr == null){	// hlprがnullなら.
									hlpr = new ListItemDBHelper(getApplicationContext());	// hlprを作成.
								}
								if (sqlite == null){	// sqliteがnullなら.
									sqlite = hlpr.getWritableDatabase();	// 書き込み可能DBを取得.
								}
								ContentValues values = new ContentValues();	// 追加する要素キーContentValuesの作成.
								values.put("name", strName);	// name
								values.put("age", intAge);	// age
								values.put("address", strAddress);	// address
								long id = -1;	// idに-1をセットしておく.
								id = sqlite.insertOrThrow("listitem", null, values);	// sqlite.insertOrThrowでINSERT.
							}
							catch (Exception ex){	// 例外キャッチ.
								Log.e("SQLiteOpenHelper_", ex.toString());	// ex.toStringをLogに出力.
							}
							finally{
								sqlite.close();	// sqlite.closeで閉じる.
								sqlite = null;	// null入れておく.
							}
							
							// アイテムの追加
							ListItem item = new ListItem();	// ListItemオブジェクトitemを生成.
							item.name = strName;	// nameはstrName.
							item.age = intAge;	// ageはintAge. 
							item.address = strAddress;	// addressはstrAdress.
							list.add(item);	// list.addでitemを追加.
							
							// アダプタの更新.
							adapter.notifyDataSetChanged();	// adapter.notifyDataSetChangedでUI更新.
						}
						
    				});
					builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {	// setNegativeButtonで"Cancel"ボタンのリスナーをセット.
						
						@Override
						public void onClick(DialogInterface dialog, int which) {
							// TODO Auto-generated method stub
							//　キャンセル処理.(実際には何もしない.)
						}
						
					});
					builder.create().show();	// ダイアログ表示.
    				
    				break;	// 抜ける.
    			}
    		
    	}
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    }
}
