import rx.Observable;

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// Integer配列の初期化.
		Integer[] array = {1, 2, 3, 4, 5};	// 1から5までの配列array.

		// オブザーバブルの生成.
		Observable<Integer> observable = Observable.from(array);	// Observable.fromで配列から発行する値を決定.

		// 登録.
		observable.subscribe(x -> System.out.println(x), e -> new Exception(e), () -> System.out.println("Completed!"));	// subscribeでxを出力するようなアクションを登録.(エラー通知と完了通知も登録.)

	}

}