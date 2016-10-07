package com.bgstation0.android.sample.downloadmanager_;

import android.app.Activity;
import android.app.DownloadManager;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements OnClickListener {	// View.OnClickListenerを実装.

	// メンバフィールドの定義.
	public DownloadManager downloadManager = null;	// DownloadManager型downloadManagerをnullにセット.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        // DownloadManagerの確保.
        if (downloadManager == null){	// downloadManagerがnullなら.
        	downloadManager = (DownloadManager)getSystemService(DOWNLOAD_SERVICE);	// getSystemServiceでDOWNLOAD_SERVICEを取得し, downloadManagerに格納.
        }
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	// URLの前処理
    	EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1の取得.
    	String url = edittext1.getText().toString();	// edittext1の内容をurlに代入.
    	Uri downloadUri = Uri.parse(url);	// urlをUri.parseでパースし, downloadUriに格納.
    	String downloadFilename = downloadUri.getLastPathSegment();	// downloadUri.getLastPathSegmentでファイル名の部分だけ取り出す.
    	// ダウンロードリクエストの作成
    	DownloadManager.Request request = new DownloadManager.Request(downloadUri);	// DownloadManager.RequestオブジェクトをdownloadUriを渡して作成, requestに格納.
    	request.setDestinationInExternalFilesDir(getApplicationContext(), Environment.DIRECTORY_DCIM, "/" + downloadFilename);	// request.setDestinationInExternalFilesDirでダウンロード先を指定.
    	request.setTitle("DownloadManager_");	// 通知画面のタイトルをセット.
    	request.setAllowedNetworkTypes(DownloadManager.Request.NETWORK_MOBILE | DownloadManager.Request.NETWORK_WIFI);	// ネットワークタイプはモバイル(3G/LTE)とWiFi両方.
    	request.setMimeType("application/octet-stream");	// MIMEタイプは"application/octet-stream".
    	// ダウンロードレシーバーの作成.
    	DownloadReceiver downloadReceiver = new DownloadReceiver(this);	// DownloadReceiver型downloadReceiverを作成.
    	registerReceiver(downloadReceiver, new IntentFilter(DownloadManager.ACTION_DOWNLOAD_COMPLETE));  // downloadReceiverとACTION_DOWNLOAD_COMPLETEなIntentFilterのインスタンスをregisterReceiverで登録.
    	// リクエストを投げる.
    	downloadManager.enqueue(request);	// downloadManagerにrequestを追加.
    }
}
