// グローバルインスタンスからnewで生成.
const fs = require('fs'); // requireで'fs'モジュール参照をconstのfsに格納.
const outputStream = fs.createWriteStream('./output3.log'); // fs.createWriteStreamで'output3.log'への書き込みストリームを作成.
var customConsole = new console.Console(outputStream); // グローバルインスタンスconsoleのあとにConsoleコンストラクタを置いてnewで生成.
customConsole.log("FFF"); // customConsole.logで'output3.log'に"FFF"を出力.
