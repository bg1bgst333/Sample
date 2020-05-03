import rx.subjects.PublishSubject;

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// PublishSubjectの生成.
		PublishSubject<Integer> subject = PublishSubject.create();	// subjectの作成.
		subject.subscribe(x -> System.out.println(x));	// xを出力するラムダ式をセットして登録.
		subject.onNext(1);	// 1を発行.
		subject.onNext(2);	// 2を発行.
		subject.onNext(3);	// 3を発行.
		subject.onCompleted();	// 完了通知.

	}

}