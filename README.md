PHP IDNA Extension
==================
Libidn has been ported to the PHP programming language. This page contain notes to work on this library. A complete documentation is pending.

Overview
--------
This extension provides a PHP implementation of the Internationalized Domain Name Applications (IDNA) standard. The extension offers two new functions:
```html
<?php
echo idna_toASCII('xärg.örg');
echo idna_toUnicode('xn--xrg-9ka.xn--rg-eka');
?>
```

Installation
============

Installing with pecl
--------------------
Install libidn for Debian/Ubuntu
```html
apt-get install libidn11-dev
```
or for CentOS/RHEL
```html
yum install libidn-devel
```
Execute command `pecl install idna`

Make sure you have `extension=idna.so` in your `php.ini`

Installing from sources
-----------------------
Install libidn for Debian/Ubuntu
```html
apt-get install libidn11-dev
```
or for CentOS/RHEL
```html
yum install libidn-devel
```
Download idna source package

Unpack idna source package

Go to idna folder and type `phpize && ./configure && make && make install`

Make sure you have `extension=idna.so` in your `php.ini`

Compiling IDNA into PHP
-----------------------
Install libidn for Debian/Ubuntu
```html
apt-get install libidn11-dev
```
or for CentOS/RHEL
```html
yum install libidn-devel
```
Download idna source package

Unpack idna source package to `$PHP_SOURCE_DIR/ext/idna`

In php source root directory run commands: `rm configure && ./buildconf --force`

Configure PHP with command `./configure --with-idna`

Run `make && make install`
