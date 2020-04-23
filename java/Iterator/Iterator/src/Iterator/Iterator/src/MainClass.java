import java.util.ArrayList;
import java.util.Iterator;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// for文でArrayList<String>を出力.
		ArrayList<String> strArrayList = new ArrayList<String>();	// ArrayList<String>のstrArrayList.
		strArrayList.add("ABC");	// "ABC"を追加.
		strArrayList.add("DEF");	// "DEF"を追加.
		strArrayList.add("GHI");	// "GHI"を追加.

		// イテレータの取得.
		for (Iterator<String> iterator = strArrayList.iterator(); iterator.hasNext(); ){	// iteratorが最後に到達するまで続ける.
			System.out.println(iterator.next());	// iterator.nextを出力.
		}

	}

}