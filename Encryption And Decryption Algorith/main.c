#include <stdio.h>
#include <stdlib.h>

void Sifrele(FILE *Original, FILE *Encrypted, FILE *Key){

    int encryptionkey, i;
    char realtextholder, encryptedtextholder;

    Original = fopen("orjinal.txt", "r");

    Key = fopen("anahtar.txt", "r");
    fscanf(Key, "%d", &encryptionkey);
    //fread(encryptionkey, sizeof(encryptionkey), 1, Key);

    Encrypted = fopen("sifreli.txt", "w");

    for (i=0 ; i<14 ; i++){

        fread(&realtextholder, sizeof(char), 1, Original);
        encryptedtextholder = realtextholder + encryptionkey;
        fwrite(&encryptedtextholder, sizeof(char), 1, Encrypted);

        printf(" o\t\t\tEncrypting Character %c ---> %c\t\t\t\t    o\n", realtextholder, encryptedtextholder);
        }

    fclose(Original);
    fclose(Key);
    fclose(Encrypted);
}

void SifreCoz (FILE *Encrypted, FILE *NewOriginal,  FILE *Key){

    int encryptionkey, i;
    char passwordreader, realtextholder;

    Encrypted = fopen("sifreli.txt", "r");

    NewOriginal = fopen("yeniorjinal.txt", "w");

    Key = fopen("anahtar.txt", "r");
    fscanf(Key, "%d", &encryptionkey);
    //fread(encryptionkey, sizeof(encryptionkey), 1, Key);


    for (i=0 ; i<14 ; i++){

        fread(&passwordreader, sizeof(char), 1, Encrypted);
        realtextholder = passwordreader - encryptionkey;
        fwrite(&realtextholder, sizeof(char), 1, NewOriginal);
        }

    fclose(NewOriginal);
    fclose(Key);
    fclose(Encrypted);
}

int main()
{

    printf("\n\n**************************************** MSK ****************************************\n\n\n");

    FILE *MyOriginalFile, *MyEncryptedFile, *MyKeyFile, *MyNewOriginalFile;

    Sifrele(MyOriginalFile, MyEncryptedFile, MyKeyFile);
    SifreCoz(MyEncryptedFile, MyNewOriginalFile, MyKeyFile);

    printf(" \n\n\t\tEncryption Finished denemeabcdefgh ---> ijsjrjfghijklm\n");
    printf(" \nEncryption Key is Taken With 'fscanf' if Encryption is Taken With 'fread' Will Be denemeabcdefgh ---> LMVMUMIJKLMNOP\n\n");


    printf("\n\n**************************************** MSK ****************************************\n\n\n");
    return 0;
}
