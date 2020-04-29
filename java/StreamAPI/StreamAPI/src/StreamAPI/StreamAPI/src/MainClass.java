import java.util.ArrayList;
import java.util.List;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// ボディリストの生成.
		List<Body> bodies = new ArrayList<Body>();	// bodiesを生成.

		// ボディの追加.
		bodies.add(new Body("Taro", 30, 170, 60));		// Taroを追加.
		bodies.add(new Body("Jiro", 28, 160, 68));		// Jiroを追加.
		bodies.add(new Body("Saburo", 25, 180, 70));	// Saburoを追加.
		bodies.add(new Body("Shiro", 19, 156, 50));		// Shiroを追加.
		bodies.add(new Body("Goro", 17, 175, 65));		// Goroを追加.

		// StreamAPIで身長170以上のボディの名前を取得.
		Object[] list = bodies.stream().filter(x -> x.getHeight() >= 170).map(x -> x.getName()).toArray();	// x.getHeightで170以上の要素から, x.getNameで名前を取得し, 配列に変換.
		for (Object s : list){	// listの分繰り返す.
			System.out.println(s);	// sを出力.
		}

	}

}