// パッケージ・クラスのインポート
import java.awt.event.WindowEvent;		// WindowEventクラス(java.awt.eventパッケージ)
import java.awt.event.WindowListener;	// WindowListenerインタフェース(java.awt.eventパッケージ)

// メインフレームウィンドウリスナークラス
public class MainFrameWindowListener implements WindowListener {	// MainFrameWindowListenerの定義

	// ウィンドウがアクティブ状態になった時.
	public void windowActivated(WindowEvent e){	// windowActivatedの定義

	}

	// ウィンドウが閉じられた時.
	public void windowClosed(WindowEvent e){	// windowClosedの定義

		// アプリケーションの終了
		System.exit(0);	// System.exit(0)でアプリケーションを終了.

	}

	// ウィンドウが閉じられている時.
	public void windowClosing(WindowEvent e){	// windowClosingの定義

		// ウィンドウリソースの開放
		e.getWindow().dispose();	// e.getWindowでWindowが取得できるので, そのWindowをdisposeで破棄する.

	}

	// ウィンドウが非アクティブ状態になった時.
	public void windowDeactivated(WindowEvent e){	// windowDeactivatedの定義

	}

	// ウィンドウが最小化状態から通常状態になった時.
	public void windowDeiconified(WindowEvent e){	// windowDeiconifiedの定義

	}

	// ウィンドウが通常状態から最小化状態になった時.
	public void windowIconified(WindowEvent e){	// windowIconifiedの定義

	}

	// ウィンドウが開いたとき.
	public void windowOpened(WindowEvent e){	// windowOpenedの定義

	}

}
