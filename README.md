OneTimeCrypt
============

Nathan BeDell (cerbeus@msn.com)
11/10/2013


Background
==========
This is a simple program that I wrote to help with encrypting and decrypting files using the One Time Pad (or OTP) method,
proven by Claude Shannon to be an unbreakable method of encryption provided that the key used is completely random and only
used once.
I read about this method of encryption and was fascinated by it. The problem was, I couldn't find any software online that 
made it easy to use this method of encryption, so I decided to make my own utility. This utility works for both plaintext
and binary files.

How to use 
==========
In it's current form, this program is intended to run on x86 GNU/Linux distributions. It should also run in Windows under a cygwin 
environment.

Mac/other users should be able to compile the binary from the included c source file.

Provided are two shell scripts to make generating random keys, encrypting files, and decrypting files easy, 
encrypt.sh prompts the user for input and output file names, generates a key, and encrypts the file specified,
decrypt.sh prompts the user for input and output file names and decrypts the file specified.

Alternatively, you could use the cypher binary by itself, it takes three command line arguments:
	1) File name of the message to encrypt
	2) File name of the key to use
	3) File name of the outputted encrypted (or decrypted) file.

Note: the first two arguments are interchangeable, since I am using the same function (xor), to encrypt as to decrypt.

Licensing 
=========
This program is free and open source software, licensed under the BSD license, please see LICENSE for more information.