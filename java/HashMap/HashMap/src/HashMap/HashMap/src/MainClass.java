import java.util.HashMap;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// HashMapにアイテムを追加する.
		HashMap hashMap = new HashMap();	// hashMapを生成.
		hashMap.put("hoge", 123);	// hashMap.putで"hoge"をキー, 123を値として追加.
		hashMap.put("foo", 456);	// hashMap.putで"foo"をキー, 456を値として追加.
		hashMap.put("bar", 789);	// hashMap.putで"bar"をキー, 789を値として追加.

		// hashMapからアイテムを取り出す.
		int hoge = (int)hashMap.get("hoge");	// hashMap.getで"hoge"をキーとする値を取得.
		int foo = (int)hashMap.get("foo");	// hashMap.getで"foo"をキーとする値を取得.
		int bar = (int)hashMap.get("bar");	// hashMap.getで"bar"をキーとする値を取得.

		// 取得したアイテムの出力.
		System.out.println(hoge);	// hogeの出力.
		System.out.println(foo);	// fooの出力.
		System.out.println(bar);	// barの出力.

		// HashMap<String, Integer>にアイテムを追加する.(ジェネリクス版)
		HashMap<String, Integer> strintMap = new HashMap<String, Integer>();	// strintMapを生成.(intじゃなくてIntegerじゃないとダメ.)
		strintMap.put("AAA", 1);	// 1を追加.
		strintMap.put("BBB", 2);	// 2を追加.
		strintMap.put("CCC", 3);	// 3を追加.

		// キーを出力.
		for (String key : strintMap.keySet()){	// strintMap.keySet()からkeyを取り出す.
			System.out.println(key);	// keyを出力.
		}

		// 値を出力.
		for (Integer val : strintMap.values()){	// strintMao.values()からvalを取り出す.
			System.out.println(val);	// valを出力.
		}

	}

}