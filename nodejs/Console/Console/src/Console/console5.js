// require参照からnewで生成.
const fs = require('fs'); // requireで'fs'モジュール参照をconstのfsに格納.
const outputStream = fs.createWriteStream('./output2.log'); // fs.createWriteStreamで'output2.log'への書き込みストリームを作成.
var customConsole = new require('console').Console(outputStream); // requireのあとにConsoleコンストラクタを置いてnewで生成.
customConsole.log("EEE"); // customConsole.logで'output2.log'に"EEE"を出力.
