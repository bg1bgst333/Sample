#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータにユーザー名がある.
my $username = $q->param('username');
if ($username){

  # パスワード取得.
  my $password = $q->param('password');
  if ($username eq 'taro' && $password eq 'testpass'){

    # セッション作成..
    my $session = CGI::Session->new(undef, $q); # new(dsn, query)で復元.

    # パラメータ設定.
    $session->param('username', $username);

    # ヘッダーにクッキーをセット.
    my $cookie = $q->cookie(CGISESSID => $session->id);
    print $q->header(-location => 'main.cgi', -cookie => $cookie);
    exit;

  }
  else{

    # 失敗
    print $q->header();
    print "login failed!";
    exit;

  }

}

# フォーム表示
print $q->header();
print <<'HTML';
<form method="post">
username: <input type="text" name="username"><br>
password: <input type="password" name="password"><br>
<input type="submit" value="submit">
</form>
HTML

