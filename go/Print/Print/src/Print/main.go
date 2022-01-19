// パッケージ宣言
package main	// mainパッケージ(main関数はmainパッケージじゃないとbuildできないっぽい.)

// モジュールのインポート
import "fmt"	// fmt

// main関数
func main(){	// funcの後ろに関数名main.
	fmt.Print("ABCDE\n")	// 改行されないので"\n"付ける.
	fmt.Print("abc", "def", "\n")	// カンマで区切って複数出力.
	fmt.Print("a = ", 1, ", b = ", 2, "\n")	// 型が違っても並べて出力.
}
