// インポート
import rx.Observable;	// オブザーバブル
import rx.Observer;	// オブザーバー

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// String配列
		String[] strArray = {"A", "B", "C"};	// strArrayを定義.

		// オブザーバブルの生成.
		Observable<String> observable = Observable.from(strArray);	// 配列のオブザーバブル.

		// 登録.
		observable.subscribe(new Observer<String>() {

			@Override
			public void onCompleted() {
				// TODO 自動生成されたメソッド・スタブ

			}

			@Override
			public void onError(Throwable arg0) {
				// TODO 自動生成されたメソッド・スタブ

			}

			@Override
			public void onNext(String arg0) {
				// TODO 自動生成されたメソッド・スタブ
				System.out.println("onNext: arg0 = " + arg0);	// arg0を出力.
			}

		});	// 中でメソッドの処理を定義.

	}

}