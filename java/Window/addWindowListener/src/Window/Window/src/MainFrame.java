// パッケージ・クラスのインポート
import java.awt.Frame;	// Frameクラス(java.awtパッケージ)
import java.awt.event.WindowEvent;	// WindowEventクラス(java.awt.eventパッケージ)
import java.awt.event.WindowListener;	// WindowListenerインターフェース(java.awt.eventパッケージ)

// メインフレームクラス
public class MainFrame extends Frame implements WindowListener{	// MainFrameの定義

	// コンストラクタ
	public MainFrame(){	// コンストラクタMainFrameの定義

		// デフォルトのサイズをセット.
		setSize(640, 480);	// setSizeでデフォルトサイズを(640, 480)にセット.
		addWindowListener(this);	// addWindowListenerで自身(this)をセット.

	}

	@Override
	public void windowOpened(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ

	}

	@Override
	public void windowClosing(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ
		// ウィンドウリソースの開放
		e.getWindow().dispose();	// e.getWindowでWindowが取得できるので, そのWindowをdisposeで破棄する.
	}

	@Override
	public void windowClosed(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ
		// アプリケーションの終了
		System.exit(0);	// System.exit(0)でアプリケーションを終了.
	}

	@Override
	public void windowIconified(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ

	}

	@Override
	public void windowDeiconified(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ

	}

	@Override
	public void windowActivated(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ

	}

	@Override
	public void windowDeactivated(WindowEvent e) {
		// TODO 自動生成されたメソッド・スタブ

	}

}