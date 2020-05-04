import rx.Observable;

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブザーバブルの生成.
		Observable<Integer> observable = Observable.just(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);	// 1から10までのちょうど10個を指定.

		// 登録.
		observable.subscribe(x -> System.out.println(x), e -> new Exception(e), () -> System.out.println("Completed!"));	// subscribeでxを出力するようなアクションを登録.(エラー通知と完了通知も登録.)

	}

}