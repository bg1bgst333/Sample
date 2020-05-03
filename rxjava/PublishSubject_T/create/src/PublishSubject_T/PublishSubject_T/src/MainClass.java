import rx.subjects.PublishSubject;

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// PublishSubjectの生成.
		PublishSubject<String> subject = PublishSubject.create();	// subjectの作成.
		subject.subscribe(s -> System.out.println(s));	// sを出力するラムダ式をセットして登録.
		subject.onNext("A");	// "A"を発行.
		subject.onNext("B");	// "B"を発行.
		subject.onNext("C");	// "C"を発行.
		subject.onCompleted();	// 完了通知.

	}

}