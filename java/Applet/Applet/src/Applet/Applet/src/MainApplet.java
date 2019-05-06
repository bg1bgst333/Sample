// パッケージ・クラスのインポート
import java.applet.Applet;	// Appletクラス(java.appletパッケージ)
import java.awt.Graphics;	// Graphicsクラス(java.awtパッケージ)

// メインアプレットクラス
public class MainApplet extends Applet {	// MainAppletの定義

	// 描画
	public void paint(Graphics g){

		// 線の描画.
		g.drawLine(100, 100, 200, 200);	// g.drawLineで(100, 100)-(200, 200)の直線を描画.

	}

}