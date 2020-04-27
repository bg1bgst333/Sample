import java.util.TreeSet;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// TreeSetにアイテムを追加.
		TreeSet treeSet = new TreeSet();	// treeSetを生成.
		treeSet.add(2);
		treeSet.add(10);
		treeSet.add(1);

		// treeSetの中身を出力.
		for (Object e : treeSet){
			System.out.println(e);
		}

		// TreeSet<String>にアイテムを追加.
		TreeSet<String> strTreeSet = new TreeSet<String>();	// strTreeSetを生成.
		strTreeSet.add("aaa");
		strTreeSet.add("bbb");
		strTreeSet.add("ccc");

		// strTreeSetの中身を出力.
		for (String s : strTreeSet){
			System.out.println(s);
		}

	}

}