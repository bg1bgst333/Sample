// パッケージ・クラスのインポート
import java.awt.Frame;	// Frameクラス(java.awtパッケージ)
import java.awt.Graphics;	// Graphicsクラス(java.awtパッケージ)

// メインフレームクラス
public class MainFrame extends Frame {	// MainFrameの定義

	// コンストラクタ
	public MainFrame(){

		// デフォルトのサイズをセット.
		setSize(640, 480);	// setSizeで(640, 480)にセット.

		// カスタムアダプタをセット.
		addWindowListener(new CustomAdapter());	// addWindowListenerでCustomAdapterのインスタンスをセット.

	}

	// 描画
	public void paint(Graphics g){

		// 線の描画.
		g.drawLine(100, 100, 200, 200);	// g.drawLineで(100, 100)-(200, 200)の直線を描画.

	}

}