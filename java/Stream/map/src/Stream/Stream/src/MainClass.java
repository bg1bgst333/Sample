import java.util.ArrayList;
import java.util.Collection;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// ボディリストを生成し, Collectionオブジェクトに格納.
		Collection<Body> bodies = new ArrayList<Body>();	// bodiesを生成.

		// ボディの追加.
		bodies.add(new Body("Taro", 30, 170, 60));		// Taroを追加.
		bodies.add(new Body("Jiro", 28, 160, 68));		// Jiroを追加.
		bodies.add(new Body("Saburo", 25, 180, 70));	// Saburoを追加.
		bodies.add(new Body("Shiro", 19, 156, 50));		// Shiroを追加.
		bodies.add(new Body("Goro", 17, 175, 65));		// Goroを追加.

		// filterで絞込みしてmapで年齢を返す.
		Object[] list = bodies.stream().filter(x -> x.getHeight() >= 170).map(x -> x.getAge()).toArray();	// getHeightが170以上のgetAgeを返す.
		for (Object s : list){	// listの分繰り返す.
			System.out.println(s);	// sを出力.
		}

	}

}