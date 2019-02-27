// requireでモジュール参照内のConsoleコンストラクタ参照を分割代入で取得.
const {Console} = require('console'); // requireで'console'モジュール内の'Console'という要素(これがコンストラクタ)の参照を分割代入でconstのConsoleに格納.
const fs = require('fs'); // requireで'fs'モジュール参照をconstのfsに格納.
const outputStream = fs.createWriteStream('./output.log'); // fs.createWriteStreamで'output.log'への書き込みストリームを作成.
var customConsole = new Console(outputStream); // newのあとに取得したConsoleコンストラクタを置き, 引数にはoutputStreamを指定してオブジェクトを生成, varのcustomConsoleに格納.
customConsole.log("DDD"); // customConsole.logで'output.log'に"DDD"を出力.
