// expressモジュール参照の取得
const express = require('express'); // requireで'express'モジュールの参照をconstのexpressに格納.

// appオブジェクト参照の取得
const app = express(); // express自身がトップレベル関数express()への参照であり, express()はappオブジェクトの参照を返す.

// GETリクエストのルーティングを作成する.
app.get('/', (req, res) => res.send('ABCDE')); // '/' => 'ABCDE'.

// ポート番号3000番でリッスン.
app.listen(3000, () => console.log('Listen port number 3000')); // app.listenで3000番でlisten, 'Listen port number 3000'を出力.
