// require参照からコンストラクタ呼び出し.
const fs = require('fs'); // requireで'fs'モジュール参照をconstのfsに格納.
const outputStream = fs.createWriteStream('./output4.log'); // fs.createWriteStreamで'output4.log'への書き込みストリームを作成.
var customConsole = require('console').Console(outputStream); // require('console')のあとにConsoleコンストラクタを呼び出す.
customConsole.log("GGG"); // customConsole.logで'output4.log'に"GGG"を出力.
