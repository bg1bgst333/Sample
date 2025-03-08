#!/usr/bin/perl

# RC4を使う.
use Crypt::RC4;

# キーとデータ.
$key = "secretkey";
$data = "ABCDEFGHIJ";

# 暗号化
my $encrypted = RC4($key, $data);
print "encrypted = $encrypted\n";

# 複合化
my $decrypted = RC4($key, $encrypted);
print "decrypted = $decrypted\n";
