import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Iterator;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// while文でArrayList<String>を出力.
		ArrayList<String> strArrayList = new ArrayList<String>();	// ArrayList<String>のstrArrayList.
		strArrayList.add("ABC");	// "ABC"を追加.
		strArrayList.add("DEF");	// "DEF"を追加.
		strArrayList.add("GHI");	// "GHI"を追加.

		// イテレータの取得.
		AbstractList absList = strArrayList;	// absListに格納.
		Iterator<String> iterator = absList.iterator();	// iteratorを取得.
		while (iterator.hasNext()){	// 次があれば.
			System.out.println(iterator.next());	// 次を出力.
		}

	}

}