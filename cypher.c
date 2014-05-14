/*
(cypher.c)
Nathan BeDell (cerbeus@msn.com)
11/10/2013

This program, along with two shell scripts (encrypt.sh and decrypt.sh) comprise the OTPtool
utility I wrote to make it easy to use one time pads for encryption. 

This program takes the names of three files as command line arguments:
	* Message/data to be encrypted/decrypted
	* Key to encrypt/decrypt data
	* A file to output the encrypted/decrypted data to.

Note that because I am using Xor, the same algorithm is used to encrypt the data and decrypt the data.
Specifically, (^ is xor):
	((key ^ message) ^ key) == message

----Sample usage----

To encrypt:
	./cypher message.txt key encrypted.txt

to decrypt:
	./cypher encrypted.txt key decrypted txt 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char** argv){

	// Open files
	FILE *outputFile;
	outputFile=fopen(argv[3], "w"); // Output

	FILE *inputFile;
	inputFile=fopen(argv[1], "r"); // Input (cyphertext or key)

	FILE *keyFile;
	keyFile=fopen(argv[2], "r"); // Key

	// Calculate the size of the input file
	struct stat st;
	stat(argv[1], &st);
	int inputSize = st.st_size;

	// Calculate the size of the key
	struct stat st2; 
	stat(argv[2], &st2);
	int keySize = st2.st_size;

	char message[inputSize]; // C-string to hold encrypted/decrypted data

	if(inputSize != keySize){ // Check to make sure the size of the input files is the same
		puts("Sorry, the key needs to be the same size as the file you want to encrypt.");
		return 1;
	}

	// Encrypt data
	for(int i = 0; i < inputSize; i++){
		message[i] = fgetc(inputFile) ^ fgetc(keyFile);
	}

	// Output encrypted data
	for(int i = 0; i < inputSize; i++){
		fputc(message[i],outputFile);
	}

	fclose(outputFile);
	fclose(inputFile);
	fclose(keyFile);

	return 0;

}
