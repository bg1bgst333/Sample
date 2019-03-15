// パッケージ・クラスのインポート
import java.awt.event.WindowAdapter;	// WindowAdapterクラス(java.awt.eventパッケージ)
import java.awt.event.WindowEvent;	// WindowEventクラス(java.awt.eventパッケージ)

// カスタムアダプタクラス
public class CustomAdapter extends WindowAdapter{	// CustomAdapterの定義

	// ウィンドウを閉じる時.
	public void windowClosing(WindowEvent e){

		// ウィンドウリソースの開放
		e.getWindow().dispose();	// e.getWindow().dispose()で破棄.

	}

	// ウィンドウを閉じた時.
	public void windowClosed(WindowEvent e){

		// アプリケーションの終了
		System.exit(0);	// System.exit(0)で終了.

	}

}