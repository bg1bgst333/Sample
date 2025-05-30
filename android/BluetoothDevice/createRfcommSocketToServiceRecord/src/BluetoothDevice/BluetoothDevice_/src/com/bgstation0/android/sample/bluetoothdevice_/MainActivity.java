package com.bgstation0.android.sample.bluetoothdevice_;

import java.io.IOException;
import java.util.ArrayList;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

// メインアクティビティ
public class MainActivity extends Activity implements OnClickListener, OnItemClickListener{

    // メンバフィールドの定義
    Context mContext = null;	// mContextをnullで初期化.
    ListView mListView1 = null;	// mListView1をnullで初期化.
    ArrayList<BluetoothDevice> mBluetoothDeviceList = null;	// mBluetoothDeviceListをnullで初期化.
    CustomAdapter mCustomAdapter = null;	// mCustomAdapterをnullで初期化.
    BroadcastReceiver mCustomReceiver = null;	// ブロードキャストレシーバはnullで初期化.
    BluetoothAdapter mBluetoothAdapter = null;	// nullで初期化.
    public static final int REQUEST_CODE_BLUETOOTH_ENABLE = 1;	// REQUEST_CODE_BLUETOOTH_ENABLEを1で初期化.
    
    // アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextに自身をセット.
        mContext = this;	// mContextにthisを格納.
        
        // リストビューの取得とアイテム選択ハンドラのセット.
        mListView1 = (ListView)findViewById(R.id.listview1);	// mListView1を取得.
        mListView1.setOnItemClickListener(this);	// thisをセット.
        
        // カスタムアダプタの生成とセット..
        mBluetoothDeviceList = new ArrayList<BluetoothDevice>();	// mBluetoothDeviceListを生成.
        mCustomAdapter = new CustomAdapter(this, R.layout.list_item, mBluetoothDeviceList);	// CustomAdapterの生成.
        mListView1.setAdapter(mCustomAdapter);	// mListView1.setAdapterでmCustomAdapterをセット.
        
        // カスタムレシーバ生成.
        mCustomReceiver = new CustomReceiver(this);	// CustomReceiverを生成.(thisを渡す.)
        
        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// thisをセット.
        
    }
    
    // クリック時
    @Override
    public void onClick(View v) {
    	
        // TODO Auto-generated method stub
        // BluetoothAdapterの取得.
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();	// mBluetoothAdapterの取得.
        if (mBluetoothAdapter != null){	// nullでない.
        	
        	// 利用可能でなかったら, Bluetooth設定画面に遷移し, 利用可能なら探索.
			if (!mBluetoothAdapter.isEnabled()){	// 利用可能でない.
				Intent intent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);	// 利用可能リクエスト.
				startActivityForResult(intent, REQUEST_CODE_BLUETOOTH_ENABLE);	// startActivityForResultでintent発行, REQUEST_CODE_BLUETOOTH_ENABLEを渡す.
			}
			else{	// 利用可能.
				
				// インテントフィルターをカスタムレシーバに登録.
				IntentFilter filter = new IntentFilter();	// filterの生成.
				filter.addAction(BluetoothAdapter.ACTION_DISCOVERY_STARTED);	// 開始
				filter.addAction(BluetoothDevice.ACTION_FOUND);	// 発見
				filter.addAction(BluetoothAdapter.ACTION_DISCOVERY_FINISHED);	// 終了
				registerReceiver(mCustomReceiver, filter);	// mCustomReceiverにfilterを登録.
				
				// 探索.
				mBluetoothAdapter.startDiscovery();	// mBluetoothAdapter.startDiscoveryで探索開始.
				
			}
			
		}
		
    }

	// Bluetooth許可ダイアログから返ってきた時.
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent intent){
		
		// リクエストがBluetooth許可の場合.
		if (requestCode == REQUEST_CODE_BLUETOOTH_ENABLE){
			if (resultCode == Activity.RESULT_OK){	// ユーザが許可を押した時.
				
				// インテントフィルターをカスタムレシーバに登録.
				IntentFilter filter = new IntentFilter();	// filterの生成.
				filter.addAction(BluetoothAdapter.ACTION_DISCOVERY_STARTED);	// 開始
				filter.addAction(BluetoothDevice.ACTION_FOUND);	// 発見
				filter.addAction(BluetoothAdapter.ACTION_DISCOVERY_FINISHED);	// 終了
				registerReceiver(mCustomReceiver, filter);	// mCustomReceiverにfilterを登録.
				
				// 探索.
				mBluetoothAdapter.startDiscovery();	// mBluetoothAdapter.startDiscoveryで探索開始.
				
			}
		}
		
	}
	
	// アイテムが選択された時.
	@Override
	public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
		
		// デバイスの取得.
		BluetoothDevice bluetoothDevice = mBluetoothDeviceList.get(position);	// mBluetoothDeviceList.getでbluetoothDeviceを取得.
		
		// SPPのUUID準備.
		UUID uuid = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");	// SPPのUUIDはこれ.
		
		// Bluetoothソケットの作成.
		try {
			BluetoothSocket soc = bluetoothDevice.createRfcommSocketToServiceRecord(uuid);	// socを作成.
			soc.close();	// soc.closeで閉じる.
			Toast.makeText(mContext, "soc create and close.", Toast.LENGTH_LONG).show();	// "soc create and close."と表示.
		}
		catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			Toast.makeText(mContext, "e = " + e.getMessage(), Toast.LENGTH_LONG).show();	// 例外メッセージ表示.
		}
		
	}
	
}