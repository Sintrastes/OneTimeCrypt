#!/bin/bash
#
# Nathan BeDell (cerbeus@msn.com)
# 11/10/2013
#
# This script generates a random key for a OTP using /dev/urandom.
# The first argument to the script is the name of the file you want
# to generate a OTP key for, and the second argument is the file name of 
# the outputted key.
#
# Note: Changing /dev/urandom/ to /dev/random would be more secure, but very slow
# for large files. This is because /dev/random generates higher quality random numbers
# than /dev/urandom.
#

echo "Enter the name of the file you want to encrypt:"
read infile

echo "Enter the name of the key you want to generate:"
read keyfile

echo "Enter the name of the encrypted file you want to generate:"
read outfile

echo "Generating key for OTP (could take awhile for larger files."
dd if=/dev/urandom of=$keyfile bs=1 count=$(wc -c < $infile) && echo "Success!" 

./cypher $infile $keyfile $outfile && echo "Success generating encrypted file!"
