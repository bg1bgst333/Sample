import rx.Observable;

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブザーバブルの生成.
		Observable<Integer> observable = Observable.range(1, 10).filter(x -> x % 2 == 0);	// 1から始まる10個の範囲を指定し, 偶数に絞る.

		// 登録.
		observable.subscribe(x -> System.out.println(x), e -> new Exception(e), () -> System.out.println("Completed!"));	// subscribeでxを出力するようなアクションを登録.(エラー通知と完了通知も登録.)

	}

}