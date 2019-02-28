// 文字列の出力
console.log("ABCDE"); // "ABCDE"

// 数値の出力
var a = 10; // aを10で初期化.
console.log(a); // "10"

// 数値を指定の書式で出力.
console.log("a = %d", a); // "a = 10"

// 複数の数値を並べて出力.
var b = 20; // bを20で初期化.
console.log(a, b); // "10 20"

// 書式出力のあとに並べて出力.
console.log("a = %d", a, b); // "a = 10 20"

// 3つ並べて出力.
var c = 30; // cを30で初期化.
console.log(a, b, c); // "10 20 30"

// 2つの書式出力のあとに並べて出力.
console.log("a = %d, b = %d", a, b, c); // "a = 10, b = 20 30"
