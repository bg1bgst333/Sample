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

		// filterで絞込みだけ.
		Object[] list = bodies.stream().filter(x -> x.getHeight() >= 170).toArray();	// getHeightが170以上.
		for (Object s : list){	// listの分繰り返す.
			Body b = (Body)s;	// Bodyにキャスト.
			System.out.println(b.getName() + ", " + b.getAge() + ", " + b.getHeight() + ", " + b.getWeight());	// 各要素を出力.
		}

	}

}