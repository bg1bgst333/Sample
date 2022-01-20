// httpモジュール参照の取得
const http = require('http'); // requireで'http'モジュールの参照をconstのfsに格納.

// 簡易Webサーバの作成
var server = http.createServer((req, res) => { // http.createServerで簡易Webサーバを作成し, serverに格納.(その結果に対する処理はラムダ式で書く.)

  // HTTPレスポンスヘッダの書き込み.
  res.writeHead(200, {'Content-Type': 'text/plain'}); // HTTPステータスコードは200, Content-Typeはtext/plainであることをres.writeHeadで書き込む.

  // HTTPレスポンスボディの最後に'ABCDE'を書き込む.
  res.end('ABCDE\n'); // res.endで'ABCDE'と改行を書き込んで終わる.

})

// serverの中身を見てみる.
console.log(server); // console.logでserverをそのまま出力.

// リッスン.
server.listen(3000, () => console.log('Local Server Listen')); // ポート番号3000でリッスン, 'Local Server Listen'と出力.
