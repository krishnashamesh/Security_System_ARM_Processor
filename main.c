#include"macros.h"
#include<ulk.h>
int main(void) PROGRAM_ENTRY;
extern int ulk_fpga_dip_switch();
extern void ulk_proc_keypad_init (void);
extern int ulk_proc_keypad_getkey(void);
int usr_check(char a);
int usr_hex();
int usr_dip();
int usr_cmp();
int get_pix();
void lockdown();
#define X_OFFSET 0
#define Y_OFFSET 0
#define GLCD_BASE_ADDRESS 0x80500000
#define ULK_GLCD_WIDTH 320
#define ULK_GLCD_HEIGHT 240
struct PIXEL
{
	unsigned int x;
unsigned int y;
};

extern struct PIXEL pixel;
extern struct PIXEL ulk_proc_touch_spi_enable(void);
extern void ulk_proc_touch_spi_disable(void);
extern struct PIXEL ulk_proc_touch_spi_poll(void);
extern int ulk_fpga_dip_switch();
void shifttbl();
void shifttbm();
void shifttbr();
void shiftbtl();
void shiftbtm();
void shiftbtr();
void shiftrlt();
void shiftrlm();
void shiftrlb();
void shiftlrt();
void shiftlrm();
void shiftlrb();
void transpose(int k,int l);
int rubix();
void rubix_print();
void reini(int sel);
void init();
int main001();
int compare();
    struct phases
    {
       uint32 a[3][3];
    }face[6];

    uint32 ff[3][3]={ {0xffffff,0xffffff,0xffffff},//white
             {0xffffff,0xffffff,0xffffff},
           {0xffffff,0xffffff,0xffffff}};

    uint32 bf[3][3]={ {0xff0000,0xff0000,0xff0000},//red
                   {0xff0000,0xff0000,0xff0000},
                   {0xff0000,0xff0000,0xff0000}
    };
    uint32 rf[3][3]={ {0xff,0xff,0xff},//blue
                   {0xff,0xff,0xff},
                   {0xff,0xff,0xff}
    };
    uint32 lf[3][3]={ {0xff00,0xff00,0xff00},//green
                   {0xff00,0xff00,0xff00},
                   {0xff00,0xff00,0xff00}
    };
    uint32 tf[3][3]={ {0xffff00,0xffff00,0xffff00},//yellow
                   {0xffff00,0xffff00,0xffff00},
                   {0xffff00,0xffff00,0xffff00}
    };
    uint32 bef[3][3]={ {0x000111,0x000111,0x000111},//black
                   {0x000111,0x000111,0x000111},
                   {0x000111,0x000111,0x000111}
    };
    uint32 a1[12],a2[12],a3[12],b1[12],b2[12],b3[12];
    uint32 b[3][3],c[3][3]={ {0xffff00,0xffff00,0xffff00},//yellow
                             {0xffff00,0xffff00,0xffff00},
                             {0xffff00,0xffff00,0xffff00}};

char key_red_value [6][6] =
	{
		{'1', '2', '3', '\\', '/', '<'},
		{'4', '5', '6', '(', ')', '\0'},
		{'7', '8', '9', '+', '-', '\0'},
		{'*', '0', '#', '/', '\0', '\0'},
		{ '\0', '\0', '\0', '\0', '\n', '$'},
		{ '\0', '\0', '\0', '=', '\0', ' ',},
	};
	char key_blue_value [6][6] =
	{
		{'A', 'B', 'C', 'D', 'E', '\b'},
		{'F', 'G', 'H', 'I', 'J', '\0'},
		{'K', 'L', 'M', 'N', 'O', '\0'},
		{'P', 'Q', 'R', 'S', '\0','\0'},
		{'T', 'U', 'V', '\0','\n','$'},
		{'W', 'X', 'Y', 'Z', '\0', ' ',},
	};


	char h[4]={'0','0','0','0'};

	int main()
	{
		 main001();
		 return 0;
	}
int main001()
{
        usr_dip();
		usr_hex();
		rubix();
return 0;
}


int usr_dip()
{
uint16 i,t=1;


	ulk_fpga_clcd_init();
	ulk_fpga_clcd_display_on();

	ulk_fpga_clcd_display_string((uint8*)"Enter  pattern \n");
    while(t<4)
	{
		ulk_proc_delay(ULK_SEC(5));

		i=ulk_fpga_dip_switch();
		if(i==0x003)
		{
		ulk_fpga_clcd_display_string((uint8*)"Password Verified..!!");
		goto x;
		}
		else
             {
			
      ulk_fpga_clcd_display_string((uint8*)"UNAUTHORISED ACCESS");
			ulk_fpga_clcd_display_string((uint8*)"LOCKDOWN.....:);):)");
            lockdown();
             return 0;
              }
		
  }

	x:ulk_fpga_clcd_display_string((uint8*)"Moving to Next Level...");

return 0;
}


int usr_hex()
{
uint32 a;
           uint32 b;
	unsigned int y=0;
   ulk_proc_keypad_init();
unsigned int t=0;
ulk_fpga_clcd_display_string((uint8*)"Enter the Password...");
while(t<4)
{
while(y<=4)
	{
	a = ulk_proc_keypad_getkey();
	ulk_proc_delay(ULK_MSEC(300));

		if(a==18)
		{
		b = ulk_proc_keypad_getkey();
			h[y]=key_blue_value[(b-1)/6][(b-1)%6];
					//h[y+1]=key_red_value[(b-1)/6][(b-1)%6];
					ulk_cpanel_printf("\n %c",h[y]);


		}
		else if(a!=18)
		{
			h[y]=key_red_value[(a-1)/6][(a-1)%6];
					ulk_cpanel_printf("\n %c",h[y]);
		}
		y++;
	}
usr_cmp();
goto r;
}
r:return 0;
}



int usr_cmp()
{
unsigned int e=0;
unsigned int k=0;
char q[4]={'1','2','3','4'};

for(e=0;e<=3;e++)
{
ulk_cpanel_printf("\n %c \t %c",h[e],q[e]);

}

for(e=0;e<=3;e++)
{
if(q[e]!=h[e])
{
	k++;
}

}
if(k!=0)
{
	ulk_fpga_clcd_display_string((uint8*)"UNAUTHORISED ACCESS");
				ulk_fpga_clcd_display_string((uint8*)"LOCKDOWN.....:);):)");

      lockdown();
      return 0;
}
else
{
	ulk_fpga_clcd_display_string((uint8*)"Moving to Rubics");



}
return 0;
}


int rubix()
{
    unsigned int h=0,f=0,r=0;
    unsigned int i,j,k,s;

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                face[0].a[i][j]=ff[i][j];
            }
        }
         for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                face[1].a[i][j]=bf[i][j];
            }
        }
         for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                face[2].a[i][j]=rf[i][j];
            }
        }
         for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                face[3].a[i][j]=lf[i][j];
 
            }
    
        }
         for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                face[4].a[i][j]=tf[i][j];
            }
    
        }
         for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                face[5].a[i][j]=bef[i][j];
 
            }
            }
         rubix_print();


    init();
  
    ulk_proc_touch_spi_enable();
    get_pix();

    return 0;
}

///shift top to bottom left
void shifttbl()
{
	ulk_cpanel_printf("Shift tbl printtt\n");
	unsigned int i,c;
    uint32 a;
    init();
    for(c=0;c<12;c++)
    

    for(i=0;i<3;i++)
    {
        a=a1[11];
        for(c=0;c<11;c++)
        {

           a1[11-c]=a1[10-c];
        }
        a1[0]=a;
    }
  
     ulk_cpanel_printf("Before rein\n");
     transpose(1,3);
     reini(0);

     ulk_cpanel_printf("After Rein\n");



}
//shift top to bottom middle
void shifttbm()
{
	ulk_cpanel_printf("Shift tbm printtt\n");
	unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=a2[11];
        for(c=0;c<11;c++)
        {

           a2[11-c]=a2[10-c];
        }
        a2[0]=a;
    }

    reini(0);
}
///shift top to bottom right
void shifttbr()
{
	ulk_cpanel_printf("Shift tbr printtt\n");
	unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=a3[11];
        for(c=0;c<11;c++)
        {

           a3[11-c]=a3[10-c];
        }
        a3[0]=a;
    }

    transpose(0,2);
    reini(0);

}
///shift bottom to top left
void shiftbtl()
{
	ulk_cpanel_printf("Shift btl printtt\n");
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=a1[0];
        for(c=0;c<11;c++)
        {

           a1[c]=a1[c+1];
        }
        a1[11]=a;
    }

    transpose(0,3);
    reini(0);

}
///shift  bottom to top middle
void shiftbtm()
{
	ulk_cpanel_printf("Shift btm printtt\n");
   unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=a2[0];
        for(c=0;c<11;c++)
        {

           a2[c]=a2[c+1];
        }
        a2[11]=a;
    }
    reini(0);

}
///shift bottom to top right
void shiftbtr()
{
	ulk_cpanel_printf("Shift btr printtt\n");
    unsigned int i,c;
    uint32 a;
    init();
        for(i=0;i<3;i++)
    {
        a=a3[0];
        for(c=0;c<11;c++)
        {

           a3[c]=a3[c+1];
        }
        a3[11]=a;
    }

    transpose(1,2);
    reini(0);

}
///shift rlt1
void shiftrlt()
{
	ulk_cpanel_printf("Shift rlt printtt\n");
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=b1[0];
        for(c=0;c<11;c++)
        {

           b1[c]=b1[c+1];
        }
        b1[11]=a;
    }

    reini(1);
    transpose(1,4);
}
// shiftrlm
void shiftrlm()
{
	ulk_cpanel_printf("Shift rlm printtt\n");
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=b2[0];
        for(c=0;c<11;c++)
        {

           b2[c]=b2[c+1];
        }
        b2[11]=a;
    }

    reini(1);
}
void shiftrlb()
{
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=b3[0];
        for(c=0;c<11;c++)
        {

           b3[c]=b3[c+1];
        }
        b3[11]=a;
    }

    reini(1);
    transpose(0,1);
}
void shiftlrt()
{
	ulk_cpanel_printf("Shift lrt");
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=b1[11];
        for(c=0;c<11;c++)
        {

           b1[11-c]=b1[10-c];
        }
        b1[0]=a;
    }

    reini(1);
    transpose(0,4);
}
void shiftlrm()
{
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=b2[11];
        for(c=0;c<11;c++)
        {

           b2[11-c]=b2[10-c];
        }
        b2[0]=a;
    }

    reini(1);
    
}
void shiftlrb()
{
    unsigned int i,c;
    uint32 a;
    init();
    for(i=0;i<3;i++)
    {
        a=b3[11];
        for(c=0;c<11;c++)
        {

           b3[11-c]=b3[10-c];
        }
        b3[0]=a;
    }

    reini(1);
    transpose(1,1);
}
void transpose(int k,int l)
///where k is the way to transpose and  l is the face value
{
    unsigned int i,j,e;
    //struct phases face[6];

     if(k==0)
     {
         for(i=0;i<3;i++)
         {
             for(j=0;j<3;j++)
             {
                 e=2-i;
               b[i][j]=face[l].a[j][e];
             }
         }

         for(i=0;i<3;i++)
         {
             for(j=0;j<3;j++)
             {
              face[l].a[i][j]= b[i][j];
             }
         }
     }
     else
     {
        for(i=0;i<3;i++)
         {
             for(j=0;j<3;j++)
             {

               e=2-i;
               b[j][e]=face[l].a[i][j];


             }
         }

         for(i=0;i<3;i++)
         {
             for(j=0;j<3;j++)
             {
              face[l].a[i][j]= b[i][j];
             }
         }
     }
}
/// reninitionalization top to bottom or viceversa arrays
void reini(int k)
{
    unsigned int i,j;
if(k==0)
{
   for(i=0;i<3;i++)
 {
    face[0].a[i][0]=a1[i];

    face[0].a[i][1]=a2[i];

    face[0].a[i][2]=a3[i];

}
   j=3;
for(i=0;i<3;i++)
{
    face[1].a[i][0]=a1[j];
    face[1].a[i][1]=a2[j];
    face[1].a[i][2]=a3[j];
    j++;
}
j=6;
for(i=2;j!=9;i--)
{
    face[5].a[i][2]=a1[j];
    face[5].a[i][1]=a2[j];
    face[5].a[i][0]=a3[j];
    j++;
}
for(i=0,j=9;i<3;i++,j++)
{
    face[4].a[i][0]=a1[j];
    face[4].a[i][1]=a2[j];
    face[4].a[i][2]=a3[j];
}
}
else
{
 for(i=0;i<3;i++)
{
    face[0].a[0][i]=b1[i];
    face[0].a[1][i]=b2[i];
    face[0].a[2][i]=b3[i];
}
for(i=0,j=3;i<3;i++,j++)
{
    face[2].a[0][i]=b1[j];
    face[2].a[1][i]=b2[j];
    face[2].a[2][i]=b3[j];
}
for(i=0,j=6;i<3;i++,j++)
{
    face[5].a[0][i]=b1[j];
    face[5].a[1][i]=b2[j];
    face[5].a[2][i]=b3[j];

}
for(i=0,j=9;i<3;i++,j++)
{
    face[3].a[0][i]=b1[j];
    face[3].a[1][i]=b2[j];
    face[3].a[2][i]=b3[j];
}
}
rubix_print();
}

void init()
{
    unsigned int i,j;

  for(i=0;i<3;i++)
 {
	a1[i]=face[0].a[i][0];
    b1[i]=face[0].a[0][i];
    a2[i]=face[0].a[i][1];
    b2[i]=face[0].a[1][i];
    a3[i]=face[0].a[i][2];
    b3[i]=face[0].a[2][i];
}
j=3;
for(i=0;i<3;i++)
{
    a1[j]=face[1].a[i][0];
    a2[j]=face[1].a[i][1];
    a3[j]=face[1].a[i][2];
j++;
}
j=6;
for(i=2;j!=9;i--)
{
    a1[j]=face[5].a[i][2];
    a2[j]=face[5].a[i][1];
    a3[j]=face[5].a[i][0];
j++;
}
j=9;

for(i=0;i<3;i++)
{
    a1[j]=face[4].a[i][0];
    a2[j]=face[4].a[i][1];
    a3[j]=face[4].a[i][2];
j++;
}
j=3;

for(i=0;i<3;i++)
{
    b1[j]=face[2].a[0][i];
    b2[j]=face[2].a[1][i];
    b3[j]=face[2].a[2][i];
j++;
}
j=6;

for(i=0;i<3;i++)
{
    b1[j]=face[5].a[0][i];
    b2[j]=face[5].a[1][i];
    b3[j]=face[5].a[2][i];
j++;
}
j=9;
for(i=0;i<3;i++)
{
    b1[j]=face[3].a[0][i];
    b2[j]=face[3].a[1][i];
    b3[j]=face[3].a[2][i];
j++;
}

}

 void rubix_print()
       {
       	unsigned int i,j,offset;
       	vuint32 *glcd_ptr;
       	glcd_ptr=(vuint32 *)GLCD_BASE_ADDRESS;
       	i=0;j=0;
       	while(i<ULK_GLCD_HEIGHT)
       	{
              offset=i * ULK_GLCD_WIDTH+j;

              if(j<ULK_GLCD_WIDTH/3)
              {
       		if(i<ULK_GLCD_HEIGHT/3)
       			*(glcd_ptr+offset)=face[0].a[0][0];
       		else if(i<(2*ULK_GLCD_HEIGHT)/3)
       			*(glcd_ptr+offset)=face[0].a[0][1];
       		else
       			*(glcd_ptr+offset)=face[0].a[0][2];

              }
              else if(j<(2*ULK_GLCD_WIDTH)/3)
              {
       		if(i<ULK_GLCD_HEIGHT/3)
       			*(glcd_ptr+offset)=face[0].a[1][0];
       		else if(i<(2*ULK_GLCD_HEIGHT)/3)
       			*(glcd_ptr+offset)=face[0].a[1][1];
       		else
       			*(glcd_ptr+offset)=face[0].a[1][2];

              }

              else
              {
              		if(i<ULK_GLCD_HEIGHT/3)
              			*(glcd_ptr+offset)=face[0].a[2][0];
              		else if(i<(2*ULK_GLCD_HEIGHT)/3)
              			*(glcd_ptr+offset)=face[0].a[2][1];
              		else
              			*(glcd_ptr+offset)=face[0].a[2][2];

                     }

              j++;
       		if(j==ULK_GLCD_WIDTH)
       		{j=0;i++;}
       	}
       }
 int get_pix()
  {
      uint16 i;
      unsigned int r=0;
      ulk_fpga_clcd_display_string((uint8*)"Solve to get the pattern ");
      while(i!=0x3fe)
      {
      pixel= ulk_proc_touch_spi_poll();

      while(pixel.x!=0 && pixel.y!=0)
      {

 	i=ulk_fpga_dip_switch();

     	if(i==0x35f)
      		       {
      			shifttbl();
      			r++;
      			break;
      		        }
      		else if(i==0x36f)
      		        {
      			shifttbm();
      			r++;
      			break;
      		        }

      		else if(i==(0x377))
      		        {return 0;
      			shifttbr();
      		 	r++;
      			break;
      		        }
      		else if(i==(0x39f))
      	     		{
      			shiftbtl();
      			r++;
      			break;
      	     		}
      		else if(i==(0x3af))
      	     		{
      			shiftbtm();
      			r++;
      			break;
      	     		}
      		else if(i==(0x3b7))
      	     		{
      			shiftbtr();
      			r++;
      			break;
      	     		}
      		else if(i==(0x2df))
      	     		{
      			shiftrlt();
      			r++;
      			break;
      	     		}
      		else if(i==(0x2ef))
      	     		{
      			shiftrlm();
      			r++;
      			break;
      	     		}
      		else if(i==0x2f7 )
      	     		{
      			shiftrlb();
      			r++;
      			break;
      	     		}

      		else if(i==0x1df)
      	     		{
      			shiftlrt();
      			r++;i=ulk_fpga_dip_switch();
      			break;
      	     		}

      		else if(i==(0x1ef))
      	     		{
      			shiftlrm();
      			r++;
      			break;
      	     		}

      		else if(i==(0x1f7))
      		  		{
      		     	shiftlrb();
      		     	r++;
      		     	break;
      		  		}

     	break;
      }
  }

      compare();

  return 0;
  }
 int compare()
 {
	 unsigned int *baseaddress=0x80500000;
	 unsigned int p,i,j,f=0,d=0;
	 do
	 {
	 for(i=0;i<3;i++)
	      {
	       for(j=0;j<3;j++)
	       {
	           if(c[i][j]==face[0].a[i][j])
	           f++;
	       }
	      }
	      if(f==9)
	      {
ulk_fpga_clcd_display_string((uint8*)"Successful Match");
    for(p=0;p<76800;p++)
	{
		*(baseaddress+p)=0x000000;
	}
	       return 0;
	      }
	      else
	      {
	    	 
ulk_fpga_clcd_display_string((uint8*)"UNAUTHORISED ACCESS");
 	    	  			           ulk_fpga_clcd_display_string((uint8*)"LOCKDOWN.....:);):)");

            lockdown();
	    	  d++;

	    	  return 0;

	      }
	 }while((d>0));
	 return 0;

 }

void lockdown()
{
 uint16 i;i=ulk_fpga_dip_switch();
unsigned int j;
unsigned int p;
unsigned int *baseaddress=0x80500000;
  i=ulk_fpga_dip_switch();
  ulk_proc_delay(ULK_SEC(2));

  while(i!=0x001)
{
ulk_fpga_clcd_display_on();
ulk_fpga_clcd_display_string((uint8*)"UNAUTHORISED ACCESS!!!");
ulk_fpga_clcd_display_string((uint8*)"CALL AUTHORISED PERSONNEL");
 for(j=1;j<9;j++)
{
 ulk_proc_led_config(j);
  ulk_proc_led_drive(j,1);
ulk_proc_delay(ULK_SEC(1));
}
for(j=1;j<9;j++)
{
 ulk_proc_led_config(j);
  ulk_proc_led_drive(j,0);
ulk_proc_delay(ULK_SEC(1));
}
for(p=0;p<76800;p++)
	{
		*(baseaddress+p)=0x000000;
	}
ulk_proc_touch_spi_disable();
ulk_fpga_clcd_display_off();
i=ulk_fpga_dip_switch();

}
  main001();

}



