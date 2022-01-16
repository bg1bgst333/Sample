#!/usr/bin/python

d = {'key1': 'value1', 'key2': 'value2', 'key3': 'value3'}

print d['key1']
print d['key2']
print d['key3']

d['key2'] = 'BBB'

print '-----'
print d['key1']
print d['key2']
print d['key3']

d['key1'] = 'AAA'

print '-----'
print d['key1']
print d['key2']
print d['key3']

d['key3'] = 'CCC'

print '-----'
print d['key1']
print d['key2']
print d['key3']
