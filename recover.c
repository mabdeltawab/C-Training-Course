#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


    #define Block_Size 512
    #define Jpeg0      0xff
    #define Jpeg1      0xd8
    #define Jpeg2      0xff
    #define Jpeg3      0xe0

int main(void)
{
    typedef uint8_t  BYTE;
    long int address,address_write;
    int count =0;
    BYTE sig[4];
    FILE *card = fopen("card.raw","r");
    if(card == NULL)
    {
        fprintf(stderr,"no such file\n");
        return 1;
    }


    while (count < 1)
    {
            fread(sig, sizeof(char), 4, card);
            address= ftell(card);// to debug
    if((sig[0]==Jpeg0)&&(sig[1]==Jpeg1)&&(sig[2]==Jpeg2)&&((sig[3]&0xf0)==Jpeg3))
    {
        fseek(card, -4, SEEK_CUR); // return to block start
        address= ftell(card);// to debug
        count++;///ToDo   index new file, close current file , free heap
        BYTE * block = malloc(Block_Size);
        FILE* out= fopen("00x.jpeg","w");//check null

        int blockcnt=-1;
        int blockcnt_write = 0;
        do
        {
            blockcnt++;
            fread(block,Block_Size,1,card);
            address= ftell(card);// to debug
            sig[0]=block[0];//memcpy(sig,block,4);
            sig[1]=block[1];
            sig[2]=block[2];
            sig[3]=block[3];

            if(!blockcnt || !((sig[0]==Jpeg0)&&(sig[1]==Jpeg1)&&(sig[2]==Jpeg2)&&((sig[3]&0xf0)==Jpeg3)))
            {
                blockcnt_write++;
                fwrite(block,Block_Size, 1, out);//chk error
                address_write=ftell(out);
            }

                if(blockcnt == 169)
                    address++;

        }
        while(!blockcnt || !((sig[0]==Jpeg0)&&(sig[1]==Jpeg1)&&(sig[2]==Jpeg2)&&((sig[3]&0xf0)==Jpeg3)));



        fclose(out);

        free(block);

    }
    else
    {
        fseek(card, Block_Size-4, SEEK_CUR);
            address= ftell(card);
    }
    }//while(count)
    return 0;
}
