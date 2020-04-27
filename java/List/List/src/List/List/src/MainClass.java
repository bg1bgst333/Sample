import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// ListインターフェースにArrayListのインスタンスを入れる.
		List aryList = new ArrayList();
		aryList.add(1);
		aryList.add(1.2f);
		aryList.add("A");

		// 出力.
		showList(aryList);	// showListでaryListを出力.

		// ListインターフェースにLinkedListのインスタンスを入れる.
		List lnkList = new LinkedList();
		lnkList.add(2);
		lnkList.add(2.4f);
		lnkList.add("B");

		// 出力.
		showList(lnkList);	// showListでlnkListを出力.

		// List<String>インターフェースにArrayList<String>のインスタンスを入れる.
		List<String> strList1 = new ArrayList<String>();
		strList1.add("a");
		strList1.add("b");
		strList1.add("c");

		// 出力.
		showStrList(strList1);	// showStrListでstrList1を出力.

		// List<String>インターフェースにLinkedList<String>のインスタンスを入れる.
		List<String> strList2 = new LinkedList<String>();
		strList2.add("A");
		strList2.add("B");
		strList2.add("C");

		// 出力.
		showStrList(strList2);	// showStrListでstrList2を出力.

	}

	// Listを取り出して出力するメソッド.
	public static void showList(List list){
		for (Iterator i = list.iterator(); i.hasNext(); ){
			System.out.println(i.next());
		}
	}

	// List<String>を取り出して出力するメソッド.
	public static void showStrList(List<String> strList){
		for (Iterator<String> i = strList.iterator(); i.hasNext(); ){
			System.out.println(i.next());
		}
	}

}