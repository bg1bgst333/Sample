import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// SetインターフェースにHashSetのインスタンスを入れる.
		Set hashSet = new HashSet();
		hashSet.add(1.2);
		hashSet.add(10);
		hashSet.add("ABC");

		// 出力.
		showSet(hashSet);	// showSetでhashSetを出力.

		// SetインターフェースにTreeSetのインスタンスを入れる.
		Set treeSet = new TreeSet();
		treeSet.add(20);
		treeSet.add(10);
		treeSet.add(30);

		// 出力.
		showSet(treeSet);	// showSetでtreeSetを出力.

		// Set<String>インターフェースにHashSetのインスタンスを入れる.
		Set<String> strSet1 = new HashSet<String>();
		strSet1.add("bbb");
		strSet1.add("aaa");
		strSet1.add("ccc");

		// 出力.
		showSet(strSet1);	// showSetでstrSet1を出力.

		// Set<String>インターフェースにTreeSetのインスタンスを入れる.
		Set<String> strSet2 = new TreeSet<String>();
		strSet2.add("CCC");
		strSet2.add("AAA");
		strSet2.add("BBB");

		// 出力.
		showSet(strSet2);	// showSetでstrSet2を出力.

	}

	// Setを取り出して出力するメソッド.
	public static void showSet(Set set){
		for (Iterator i = set.iterator(); i.hasNext(); ){
			System.out.println(i.next());
		}
	}

	// Set<String>を取り出して出力するメソッド.
	public static void showStrSet(Set<String> strSet){
		for (Iterator<String> i = strSet.iterator(); i.hasNext(); ){
			System.out.println(i.next());
		}
	}

}