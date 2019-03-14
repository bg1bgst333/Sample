// C++ネイティブ拡張を参照.
var nativeExt = require('./build/Release/native_ext.node'); // 'native_ext.node'の参照をnativeExtに格納.

// 取得した"ABC"を出力.
console.log(nativeExt.get_abc()); // nativeExt.get_abcで取得した"ABC"をconsole.logで出力.

