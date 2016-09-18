package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義
	FragmentManager fragmentManager = null;	// FragmentManagerオブジェクトfragmentManagerをnullに初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // FragmentManagerの取得.
        fragmentManager = getFragmentManager();	// getFragmentManagerでfragmentManagerを取得.
        
    }
    
    // メニューが作成された時.
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
    	
    		// Menu1
    		case R.id.menu_menu1:
    			
    			// Menu1ブロック
    			{
    				
    				// フラグメント"tag1"があるか確認する.
    				Fragment f1 = fragmentManager.findFragmentByTag("tag1");	// fragmentManager.findFragmentByTagで"tag1"なFragmentを探し, あればf1に格納.
    				if (f1 == null){	// f1がnullなら.
        				// フラグメントの追加
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					Fragment fragment = new MainFragment();	// MainFragmentオブジェクトを作成し, Fragment型のfragmentに格納.
    					Bundle args = new Bundle();	// 置換するFragmentに渡すパラメータargsをBundleオブジェクトとして作成.
    					args.putString("text", "fragment1");	// キーは"text", 値は"fragment1".
    					args.putString("color", "red");	// キーは"color", 値は"red".
    					fragment.setArguments(args);	// fragment.setArgumentsでargsをセット.
    					fragmentTransaction.add(R.id.framelayout1, fragment, "tag1");	// fragmentTransaction.addでR.id.framelayout1にfragmentを追加.("tag1"をタグ付け.)
    					//fragmentTransaction.replace(R.id.framelayout1, fragment, "tag1");	// fragmentTransaction.replaceでR.id.framelayout1をfragmentに置換.("tag1"をタグ付け.)
    					fragmentTransaction.addToBackStack(null);	// fragmentTransaction.addToBackStackで置換前の状態をバックスタックに保存.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				else{	// f1がnullでない場合.(f1が見つかった場合.)
    					// フラグメントの表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.show(f1);	// fragmentTransaction.showでf1を表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    				// フラグメント"tag2"があれば隠す.
    				Fragment f2 = fragmentManager.findFragmentByTag("tag2");	// fragmentManager.findFragmentByTagで"tag2"なFragmentを探し, あればf2に格納.
    				if (f2 != null){	// f2がnullでなければ.
    					// フラグメントの非表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.hide(f2);	// fragmentTransaction.hideでf2を非表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    				// フラグメント"tag3"があれば隠す.
    				Fragment f3 = fragmentManager.findFragmentByTag("tag3");	// fragmentManager.findFragmentByTagで"tag3"なFragmentを探し, あればf3に格納.
    				if (f3 != null){	// f3がnullでなければ.
    					// フラグメントの非表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.hide(f3);	// fragmentTransaction.hideでf3を非表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    			}
    			
    			break;
    			
    		// Menu2
    		case R.id.menu_menu2:
    			
    			//　Menu2ブロック
    			{

    				// フラグメント"tag2"があるか確認する.
    				Fragment f2 = fragmentManager.findFragmentByTag("tag2");	// fragmentManager.findFragmentByTagで"tag2"なFragmentを探し, あればf2に格納.
    				if (f2 == null){	// f2がnullなら.
        				// フラグメントの追加
	    				FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
	    				Fragment fragment = new MainFragment();	// MainFragmentオブジェクトを作成し, Fragment型のfragmentに格納.
	    				Bundle args = new Bundle();	// 置換するFragmentに渡すパラメータargsをBundleオブジェクトとして作成.
	    				args.putString("text", "fragment2");	// キーは"text", 値は"fragment2".
	    				args.putString("color", "green");	// キーは"color", 値は"green".
	    				fragment.setArguments(args);	// fragment.setArgumentsでargsをセット.
	    				fragmentTransaction.add(R.id.framelayout1, fragment, "tag2");	// fragmentTransaction.addでR.id.framelayout1にfragmentを追加.("tag2"をタグ付け.)
	    				//fragmentTransaction.replace(R.id.framelayout1, fragment, "tag2");	// fragmentTransaction.replaceでR.id.framelayout1をfragmentに置換.("tag2"をタグ付け.)
	    				fragmentTransaction.addToBackStack(null);	// fragmentTransaction.addToBackStackで置換前の状態をバックスタックに保存.
	    				fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				else{	// f2がnullでない場合.(f1が見つかった場合.)
    					// フラグメントの表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.show(f2);	// fragmentTransaction.showでf2を表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    				// フラグメント"tag1"があれば隠す.
    				Fragment f1 = fragmentManager.findFragmentByTag("tag1");	// fragmentManager.findFragmentByTagで"tag1"なFragmentを探し, あればf1に格納.
    				if (f1 != null){	// f1がnullでなければ.
    					// フラグメントの非表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.hide(f1);	// fragmentTransaction.hideでf1を非表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    				// フラグメント"tag3"があれば隠す.
    				Fragment f3 = fragmentManager.findFragmentByTag("tag3");	// fragmentManager.findFragmentByTagで"tag3"なFragmentを探し, あればf3に格納.
    				if (f3 != null){	// f3がnullでなければ.
    					// フラグメントの非表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.hide(f3);	// fragmentTransaction.hideでf3を非表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    			}
    					
    			break;
    	
    		// Menu3
    		case R.id.menu_menu3:
    			
    			// Menu3ブロック
    			{

    				// フラグメント"tag3"があるか確認する.
    				Fragment f3 = fragmentManager.findFragmentByTag("tag3");	// fragmentManager.findFragmentByTagで"tag3"なFragmentを探し, あればf3に格納.
    				if (f3 == null){	// f3がnullなら.
        				// フラグメントの追加
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					Fragment fragment = new MainFragment();	// MainFragmentオブジェクトを作成し, Fragment型のfragmentに格納.
    					Bundle args = new Bundle();	// 置換するFragmentに渡すパラメータargsをBundleオブジェクトとして作成.
    					args.putString("text", "fragment3");	// キーは"text", 値は"fragment3".
    					args.putString("color", "blue");	// キーは"color", 値は"blue".
    					fragment.setArguments(args);	// fragment.setArgumentsでargsをセット.
    					fragmentTransaction.add(R.id.framelayout1, fragment, "tag3");	// fragmentTransaction.addでR.id.framelayout1にfragmentを追加.("tag3"をタグ付け.)
    					//fragmentTransaction.replace(R.id.framelayout1, fragment, "tag3");	// fragmentTransaction.replaceでR.id.framelayout1をfragmentに置換.("tag3"をタグ付け.)
    					fragmentTransaction.addToBackStack(null);	// fragmentTransaction.addToBackStackで置換前の状態をバックスタックに保存.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				else{	// f3がnullでない場合.(f3が見つかった場合.)
    					// フラグメントの表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.show(f3);	// fragmentTransaction.showでf3を表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    				// フラグメント"tag1"があれば隠す.
    				Fragment f1 = fragmentManager.findFragmentByTag("tag1");	// fragmentManager.findFragmentByTagで"tag1"なFragmentを探し, あればf1に格納.
    				if (f1 != null){	// f1がnullでなければ.
    					// フラグメントの非表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.hide(f1);	// fragmentTransaction.hideでf1を非表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    				// フラグメント"tag2"があれば隠す.
    				Fragment f2 = fragmentManager.findFragmentByTag("tag2");	// fragmentManager.findFragmentByTagで"tag2"なFragmentを探し, あればf2に格納.
    				if (f2 != null){	// f2がnullでなければ.
    					// フラグメントの非表示
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransactionでfragmentTransactionを取得.
    					fragmentTransaction.hide(f2);	// fragmentTransaction.hideでf2を非表示.
    					fragmentTransaction.commit();	// fragmentTransaction.commitで確定.
    				}
    				
    			}
    			
    			break;
    			
    	}
    	
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
}