// パッケージ・クラスのインポート
import java.awt.Button;	// Buttonクラス(java.awtパッケージ)
import java.awt.Frame;	// Frameクラス(java.awtパッケージ)
import java.awt.event.WindowAdapter;	// WindowAdapterクラス(java.awt.eventパッケージ)
import java.awt.event.WindowEvent;		// WindowEventクラス(java.awt.eventパッケージ)

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// フレームの生成
		Frame frame = new Frame();	// Frameオブジェクトを生成し, frameに格納.

		// サイズのセット.
		frame.setSize(640, 480);	// setSizeでサイズを(640, 480)にセット.

		// デフォルトのレイアウトを無効にする.
		frame.setLayout(null);	// frameにセットされている既定のレイアウトをsetLayout(null)で無効にする.

		// ボタンの生成
		Button button = new Button("button");	// "button"と表示するButtonオブジェクトを生成し, インスタンスをbuttonに格納.

		// ボタンの位置とサイズをセット.
		button.setBounds(200, 200, 120, 80);	// button.setBoundsでボタンの位置を(200, 200), サイズを(120, 80)にセット.

		// フレームにボタンを配置.
		frame.add(button);	// frame.addでbuttonを追加.

		// 表示状態のセット.
		frame.setVisible(true);	// setVisibleで表示状態をtrueにセット.

		// ウィンドウリスナーのセット.
		frame.addWindowListener(new WindowAdapter(){	// WindowAdapterを継承した匿名クラスとしてアダプタを定義し, 引数としてaddWindowListenerに渡す.

			// windowClosedとwindowClosingのみオーバーライド. それ以外はWindowAdapterに既定の動作が定義されている.
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

		});

	}

}