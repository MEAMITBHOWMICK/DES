# DES
The Implementation Of CBC(Cipher Block Chaining) Mode Of Operation Using DES(Data  Encryption Standard) As The Underlying Pseudorandom Function

This files contain the c code of the CBC mode of encryption using DES as the underlying PRF. Code structure is as follows : 
1. I first took any text file named "message.txt". Without loss of generality I assumed this file contains 8*X byte of data, where X is the number of byte. If there is file where number of byte is not a multiple of eight, I can check the number of byte of that file using the command " ls -l filename" and can append zeros to make the byte value multiple of eight.
2. On the encryption side I first run the Key-generation program named "Des_Keygen.c" which took a master key of 56 bit as random input and generate 16 round key of 48 bit each following the key-schedule algorithm of DES and write all the key in text file named "DesRoundKey.txt". Then I run the program for the CBC mode of encryption  named "DesCBCEnc.c"  which took 8 byte data from the text file named "message.txt" at a time, encrypt them using DES as the underling PRF and wrote the ciphertxt in another file named "ciphertext.txt",  until all data of the file read.
3. On the Decryption end I first run the Key-generation program named "Des_Keygen.c" which took a master key of 56 bit as random input and generate 16 round key of 48 bit each following the key schedule algorithm of DES in reverse order and write all the key in text file named "DesRoundKey.txt". Then I run CBC mode of decryption which took 8 byte data from the file named "ciphertext.txt" at a time, decrypt them using inverse DES as the underling PRF and write the obtained decrypted data in another file named "message1.txt", until all data of the ciphertext file read.


To run the Encryption operation run the commands on terminal: /Des_Keygen && ./DesCBCEnc 
To run the Decryption operation run the commands on terminal: /Des_Keygen && ./DesCBCDec 
