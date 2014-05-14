#!/bin/bash
#
# Nathan BeDell (cerbeus@msn.com)
# 11/10/2013
#
# This script decrypts a file that has been encrypted using a one time pad.
# A file containing the original key used to encrypt the file is required
# to decrypt the one time pad.
#

echo "Enter the name of the file you want to decrypt:"
read encryptedfile

echo "Enter the name of the key to use for the decryption:"
read key

echo "Enter the name of the file you want to output:"
read outputname

./cypher $encryptedfile $key $outputname && echo "Success decrypting file!"
