import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// CollectionインターフェースにArrayListのインスタンスを入れる.
		Collection aryCollection = new ArrayList();
		aryCollection.add("aaa");
		aryCollection.add(1.2);
		aryCollection.add(10);

		// 出力.
		showCollection(aryCollection);	// showCollectionでaryCollectionを出力.

		// CollectionインターフェースにHashSetのインスタンスを入れる.
		Collection hashCollection = new HashSet();
		hashCollection.add(100);
		hashCollection.add("abc");
		hashCollection.add(1.5);

		// 出力.
		showCollection(hashCollection);	// showCollectionでhashCollectionを出力.

		// Collection<String>インターフェースにArrayList<String>のインスタンスを入れる.
		Collection<String> strCollection1 = new ArrayList<String>();
		strCollection1.add("BBB");
		strCollection1.add("CCC");
		strCollection1.add("AAA");

		// 出力.
		showStrCollection(strCollection1);	// showStrCollectionでstrCollection1を出力.

		// Collection<String>インターフェースにHashSet<String>のインスタンスを入れる.
		Collection<String> strCollection2 = new HashSet<String>();
		strCollection2.add("CCC");
		strCollection2.add("BBB");
		strCollection2.add("AAA");

		// 出力.
		showStrCollection(strCollection2);	// showStrCollectionでstrCollection2を出力.

	}

	// Collectionを取り出して出力するメソッド.
	public static void showCollection(Collection collection){
		for (Iterator i = collection.iterator(); i.hasNext(); ){
			System.out.println(i.next());
		}
	}

	// Collection<String>を取り出して出力するメソッド.
	public static void showStrCollection(Collection<String> strCollection){
		for (Iterator<String> i = strCollection.iterator(); i.hasNext(); ){
			System.out.println(i.next());
		}
	}

}