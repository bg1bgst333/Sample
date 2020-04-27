import java.util.HashSet;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// HashSetにアイテムを追加.
		HashSet hashSet = new HashSet();	// hashSetを生成.
		hashSet.add("abc");
		hashSet.add(10.10f);
		hashSet.add(1);

		// hashSetの中身を出力.
		for (Object e : hashSet){
			System.out.println(e);
		}

		// HashSet<String>にアイテムを追加.
		HashSet<String> strHashSet = new HashSet<String>();	// strHashSetを生成.
		strHashSet.add("aaa");
		strHashSet.add("bbb");
		strHashSet.add("ccc");

		// strHashSetの中身を出力.
		for (String s : strHashSet){
			System.out.println(s);
		}

	}

}