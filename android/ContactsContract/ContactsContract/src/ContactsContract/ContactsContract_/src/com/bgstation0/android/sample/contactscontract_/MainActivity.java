package com.bgstation0.android.sample.contactscontract_;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.ContentResolver;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ContentResolverで連絡先を取得し, ListViewに追加して表示.
        ContentResolver contentResolver = getContentResolver();	// getContentResolverでcontentResolverを取得.
        List<ListItem> listitems = new ArrayList<ListItem>();	// listitemsを生成.
        Cursor c = contentResolver.query(ContactsContract.Contacts.CONTENT_URI, null, null, null, null);	// contentResolver.queryで連絡先にアクセス.
        if (c.moveToFirst()){	// 最初なら.
        	for (int i = 0; i < c.getCount(); i++){	// c.getCountの数, 繰り返す.
        		
        		// IDの取得.
        		String id = c.getString(c.getColumnIndex(ContactsContract.Contacts._ID));	// IDを取得.
        		
        		// 表示名の取得.
        		String name = c.getString(c.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME));	// 表示名を取得.
        		
        		// 電話番号リストの取得.
        		String phoneNumberList = "";	// 電話番号リストphoneNumberListを""で初期化.
        		Cursor phoneCursor = contentResolver.query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI, null, ContactsContract.CommonDataKinds.Phone.CONTACT_ID + "=" + id, null, null);	// IDから電話番号をひく.
        		if (phoneCursor.moveToFirst()){	// 最初なら.
        			for (int j = 0; j < phoneCursor.getCount(); j++){	// phoneCursor.getCountの数, 繰り返す.
        				phoneNumberList = phoneNumberList + phoneCursor.getString(phoneCursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER));
        				phoneNumberList = phoneNumberList + ";";	// 複数の場合も考えて";"で区切る.
        				phoneCursor.moveToNext();	// moveToNextで次へ.
        			}
        		}
        		phoneCursor.close();	// 閉じる.
        		
        		// メールアドレスリストの取得.
        		String emailAddressList = "";	// メールアドレスリストemailAddressListを""で初期化.
        		Cursor emailCursor = contentResolver.query(ContactsContract.CommonDataKinds.Email.CONTENT_URI, null, ContactsContract.CommonDataKinds.Email.CONTACT_ID + "=" + id, null, null);	// IDからメールアドレスをひく.
        		if (emailCursor.moveToNext()){	// 最初なら.
        			for (int k = 0; k < emailCursor.getCount(); k++){	// emailCursor.getCountの数, 繰り返す.
        				emailAddressList = emailAddressList + emailCursor.getString(emailCursor.getColumnIndex(ContactsContract.CommonDataKinds.Email.ADDRESS));
        				emailAddressList = emailAddressList + ";";	// 複数の場合も考えて";"で区切る.
        				emailCursor.moveToNext();	// moveToNextで次へ.
        			}
        		}
        		emailCursor.close();	// 閉じる.
        		
        		// itemの追加.
        		ListItem item = new ListItem();	// itemを生成.
        		item.name = name;	// item.nameにnameを代入.
        		item.phoneNumber = phoneNumberList;	// item.phoneNumberにphoneNumberListを代入.
        		item.emailAddress = emailAddressList;	// item.emailAddressにemailAddressListを代入.
        		listitems.add(item);	// listitems.addでitemを追加.
        		
        		// 次へ.
        		c.moveToNext();	// moveToNextで次へ.
        		
        	}
        }
        c.close();	// 閉じる.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewByIdでlistview1を取得.
        ListItemAdapter adapter = new ListItemAdapter(this, R.layout.list_item, listitems);	// ListItemAdapterコンストラクタにListViewのアイテムテンプレートのlist_itemとリストデータのlistitemsをセット.
        listview1.setAdapter(adapter);	// listview1.setAdapterにadapterをセットして, ListViewとAdapterを紐付ける.      
    }    
}