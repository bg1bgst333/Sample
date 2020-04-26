import java.util.function.Function;

// テストクラス
public class TestClass {
	// フィールド
	Function<Integer, Integer> s = null;
	// メソッド
	public void method1(Function<Integer, Integer> s){
		this.s = s;	// メンバにセット.
	}
	public int run(int i){
		return s.apply(i);	// s.applyに引数を渡して, 値を返す.
	}
}