import java.util.function.Consumer;

// テストクラス
public class TestClass {
	// フィールド
	Consumer<Integer> s = null;
	// メソッド
	public void method1(Consumer<Integer> s){
		this.s = s;	// メンバにセット.
	}
	public void run(int i){
		s.accept(i);	// s.acceptに引数を渡す.
	}
}