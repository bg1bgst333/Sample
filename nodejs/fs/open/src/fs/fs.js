// fsモジュール参照の取得
const fs = require('fs'); // requireで'fs'モジュールの参照をconstのfsに格納.

// 'test.txt'を開く.
fs.open('test.txt', 'r', (err, fd) => { // fs.openで'test.txt'を読み込み専用で開く.(その結果に対する処理はラムダ式で書く.)

  // エラーがあったら, 例外処理.
  if (err){ // errがtrueの場合.

    // "fs.open error!"と出力.
    console.log("fs.open error!"); // console.logで"fs.open error!"を出力.

    // 例外処理.
    throw err;	// throwでerrを投げる.

  }

  // 成功なら"fs.open success!".
  console.log("fs.open success!"); // console.logで"fs.open success!"を出力.

  // ファイルを閉じる.
  fs.close(fd, (err) => { // fs.closeでfdを閉じる.(その結果に対する処理はラムダ式で書く.)

    // エラーがあったら, 例外処理.
    if (err) throw err; // errがtrueなら, throwでerrを投げる.

  });

});
