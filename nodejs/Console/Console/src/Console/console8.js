// グローバルインスタンスからコンストラクタ呼び出し.
const fs = require('fs'); // requireで'fs'モジュール参照をconstのfsに格納.
const outputStream = fs.createWriteStream('./output5.log'); // fs.createWriteStreamで'output5.log'への書き込みストリームを作成.
var customConsole = console.Console(outputStream); // グローバルインスタンスのあとにConsoleコンストラクタを呼び出す.
customConsole.log("HHH"); // customConsole.logで'output5.log'に"HHH"を出力.
