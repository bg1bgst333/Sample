import java.util.LinkedList;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// LinkedListの末尾にアイテムを追加したり先頭から取り出したり繰り返す.
		LinkedList lnkList = new LinkedList();	// lnkListを生成.
		lnkList.offer(100);		// 100を追加.
		lnkList.offer(0.1f);	// 0.1fを追加.
		int i = (int)lnkList.poll();	// pollでiを取り出す.
		System.out.println(i);	// iを出力.
		lnkList.offer("abc");	// "abc"を追加.
		float f = (float)lnkList.poll();	// pollでfを取り出す.
		System.out.println(f);	// fを出力.
		String s = (String)lnkList.poll();	// pollでsを取り出す.
		System.out.println(s);	// sを出力.

		// LinkedListの末尾にアイテムを追加したり先頭から取り出したり繰り返す.(ジェネリクス版)
		LinkedList<String> strList = new LinkedList<String>();	// strListを生成.
		strList.offer("AAA");	// "AAA"を追加.
		strList.offer("BBB");	// "BBB"を追加.
		System.out.println(strList.poll());	// pollで取り出した要素を出力.
		strList.offer("CCC");	// "CCC"を追加.
		System.out.println(strList.poll());	// pollで取り出した要素を出力.
		System.out.println(strList.poll());	// pollで取り出した要素を出力.

	}

}