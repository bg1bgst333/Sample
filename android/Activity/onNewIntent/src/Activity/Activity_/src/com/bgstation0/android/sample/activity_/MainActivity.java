package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContextにthisをセット.
        
        // インテントの取得.
        Intent intent = getIntent();	// インテントの取得.
        if (intent != null){	// intentがnullでない時.
        	String title = intent.getStringExtra(Intent.EXTRA_TEXT);	// titleを取得.
        	if (title != null){	// titleがnullでない時.
        		Toast.makeText(mContext, "onCreate: " + title, Toast.LENGTH_LONG).show();	// titleを表示.
        	}
        	else{
        		Toast.makeText(mContext, "onCreate: title = null", Toast.LENGTH_LONG).show();	// titleはnull.
        	}
        	String url = intent.getDataString();	// urlを取得.
        	if (url != null){	// urlがnullでない時.
        		Toast.makeText(mContext, "onCreate: " + url, Toast.LENGTH_LONG).show();	// urlを表示.
        	}
        	else{
        		Toast.makeText(mContext, "onCreate: url = null", Toast.LENGTH_LONG).show();	// urlはnull.
        	}
        }
        else{
        	Toast.makeText(mContext, "onCreate: intent = null", Toast.LENGTH_LONG).show();	// intentはnull.
        }
        
        // ボタンにクリックリスナーをセット.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				// URLを表示するインテントの作成.
				Intent launcherIntent = new Intent(Intent.ACTION_VIEW);	// launcherIntentを作成.
				launcherIntent.addCategory(Intent.CATEGORY_DEFAULT);	// CATEGORY_DEFAULTを追加.
				launcherIntent.setClassName(mContext.getPackageName(), mContext.getClass().getName());	// クラス名をセット.
				String url = "http://bgstation0.com";	// urlのセット.
				String title = "B.G-STATION";	// titleのセット.
				launcherIntent.putExtra(Intent.EXTRA_TEXT, title);	// titleをlauncherIntentにセット.
				launcherIntent.setData(Uri.parse(url));	// urlをlauncherIntentにセット.
				
				// ショートカットを作成するインテントの作成.
				Intent shortcutIntent = new Intent();	// shortcutIntentを作成.
				shortcutIntent.putExtra(Intent.EXTRA_SHORTCUT_INTENT, launcherIntent);	// launcherIntentを渡す.
				shortcutIntent.putExtra(Intent.EXTRA_SHORTCUT_NAME, title);	// titleを渡す.
				Parcelable iconResource = Intent.ShortcutIconResource.fromContext(mContext, R.drawable.ic_launcher);	// ショートカットアイコンリソースの取得.
				shortcutIntent.putExtra(Intent.EXTRA_SHORTCUT_ICON_RESOURCE, iconResource);	// iconResourceのセット.
				shortcutIntent.setAction("com.android.launcher.action.INSTALL_SHORTCUT");	// ショートカット作成アクションをセット.
				sendBroadcast(shortcutIntent);	// sendBroadcastでshortcutIntentを送信.
				
			}
			
		});
            
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	super.onNewIntent(intent);
    	
    	// 渡されたintentの判定.
        if (intent != null){	// intentがnullでない時.
        	String title = intent.getStringExtra(Intent.EXTRA_TEXT);	// titleを取得.
        	if (title != null){	// titleがnullでない時.
        		Toast.makeText(mContext, "onNewIntent: " + title, Toast.LENGTH_LONG).show();	// titleを表示.
        	}
        	else{
        		Toast.makeText(mContext, "onNewIntent: title = null", Toast.LENGTH_LONG).show();	// titleはnull.
        	}
        	String url = intent.getDataString();	// urlを取得.
        	if (url != null){	// urlがnullでない時.
        		Toast.makeText(mContext, "onNewIntent: " + url, Toast.LENGTH_LONG).show();	// urlを表示.
        	}
        	else{
        		Toast.makeText(mContext, "onNewIntent: url = null", Toast.LENGTH_LONG).show();	// urlはnull.
        	}
        }
        else{
        	Toast.makeText(mContext, "onNewIntent: intent = null", Toast.LENGTH_LONG).show();	// intentはnull.
        }
    	
    }
    
}