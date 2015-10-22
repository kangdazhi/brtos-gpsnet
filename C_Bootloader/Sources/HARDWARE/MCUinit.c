/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE PRESERVED ONLY INSIDE INTERRUPT SERVICE ROUTINES
**     OR EXPLICITLY MARKED SECTIONS
**
**     Project   : BRTOS_TWR_LCD
**     Processor : MCF51JM128VLH
**     Version   : Component 01.008, Driver 01.07, CPU db: 3.00.052
**     Datasheet : MCF51JM128RM Rev. 1 1/2008
**     Date/Time : 15/03/2011, 21:37
**     Abstract  :
**         This module contains device initialization code 
**         for selected on-chip peripherals.
**     Contents  :
**         Function "MCU_init" initializes selected peripherals
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################
*/

/* MODULE MCUinit */

#include <MCF51JM128.h>                /* I/O map for MCF51JM128VLH */
#include "MCUinit.h"
#include "NetConfig.h"
#include "BRTOSConfig.h"
#include "AppConfig.h"
#include "BoardConfig.h"

/* pragma to disable "possibly unassigned ISR handler" message generated by compiler on definition of ISR without vector number */
#pragma warn_absolute off

/* User declarations and definitions */
/*   Code, declarations and definitions here will be preserved during code generation */
/* End of user declarations and definitions */

/*
** ===================================================================
**     Method      :  __initialize_hardware (component MCF51JM128_64)
**
**     Description :
**         Initialization code for CPU core and a clock source.
** ===================================================================
*/
void __initialize_hardware(void)
{
  /* ### MCF51JM128_64 "Cpu" init code ... */
  /*  PE initialization code after reset */

#if (DEBUG == 1)
  /* Common initialization of the write once registers */
  /* SOPT1: COPT=0,STOPE=1,WAITE=1 */
  //SOPT1 = 0xB0;
  SOPT1 = 0xB0;
  /* SOPT2: COPCLKS=0,COPW=0,USB_BIGEND=0,CLKOUT_EN=0,CMT_CLK_SEL=0,SPI1FE=1,SPI2FE=1,ACIC=0 */  
  SOPT2 = 0x06;                                      
  /* SPMSC1: LVWF=0,LVWACK=0,LVWIE=0,LVDRE=1,LVDSE=1,LVDE=1,BGBE=0 */
  SPMSC1 = 0x1C;                                      
  /* SPMSC2: LVDV=0,LVWV=0,PPDF=0,PPDACK=0,PPDC=1 */
  SPMSC2 = 0x01;                                      
  /* Initialization of CPU registers */
  asm {
    /* VBR: ADDRESS=0 */
    clr.l d0  
    movec d0,VBR
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,FSD=0 */
    clr.l d0
    movec d0,CPUCR
  }
  /*  System clock initialization */
  /* MCGC2: BDIV=0,RANGE=1,HGO=1,LP=0,EREFS=1,ERCLKEN=0,EREFSTEN=0 */
  MCGC2 = 0x34;                        /* Set MCGC2 register */
  /* MCGC3: DIV32=1 */
  MCGC3 |= (unsigned char)0x10;                      
  /* MCGC1: CLKS=2,RDIV=2,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
  MCGC1 = 0x90;                        /* Set MCGC1 register */
  /* MCGC3: LOLIE=0,PLLS=0,CME=0,DIV32=1,VDIV=8 */
  MCGC3 = 0x18;                        /* Set MCGC3 register */
  /* MCGC4: DMX32=0,DRST_DRS=0 */
  MCGC4 = 0x00;                        /* Set MCGC4 register */
  while(!MCGSC_OSCINIT) {              /* Wait until external reference is stable */
  }
  while(MCGSC_IREFST) {                /* Wait until external reference is selected */
  }
  while((MCGSC & 0x0C) != 0x08) {      /* Wait until external clock is selected as a bus clock reference */
  }
  /* MCGC2: BDIV=0,RANGE=1,HGO=1,LP=1,EREFS=1,ERCLKEN=0,EREFSTEN=0 */
  MCGC2 = 0x3C;                        /* Set MCGC2 register */
  /* MCGC1: CLKS=2,RDIV=3,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
  MCGC1 = 0x98;                        /* Set MCGC1 register */
  /* MCGC3: LOLIE=0,PLLS=0,CME=0,DIV32=0,VDIV=8 */
  MCGC3 = 0x08;                        /* Set MCGC3 register */
  /* MCGC3: LOLIE=0,PLLS=1,CME=0,DIV32=0,VDIV=8 */
  MCGC3 = 0x48;                        /* Set MCGC3 register */
  while(!MCGSC_PLLST) {                /* Wait until PLL is selected */
  }
  /* MCGC2: LP=0 */
  MCGC2 &= (unsigned char)~0x08;                     
  while(!MCGSC_LOCK) {                 /* Wait until PLL is locked */
  }
  /* MCGC1: CLKS=0,RDIV=3,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
  MCGC1 = 0x18;                        /* Set MCGC1 register */
  while((MCGSC & 0x0C) != 0x0C) {      /* Wait until PLL clock is selected as a bus clock reference */
  }
  // Quando ENB = 1, permite voltar de um wait State
  // Ainda, configura a marcara de interrup��o p/ zero
  // ou seja, qq interrup��o pode retirar o processador do modo Wait
  INTC_WCR = 0x80;
#else
/* ### MCF51JM128_64 "Cpu" init code ... */
  /*  PE initialization code after reset */

  /* Common initialization of the write once registers */
  /* SOPT1: COPT=0,STOPE=0,WAITE=1 */
  SOPT1 = 0x10;                                      
  /* SOPT2: COPCLKS=0,COPW=0,USB_BIGEND=1,CLKOUT_EN=0,CMT_CLK_SEL=0,SPI1FE=1,SPI2FE=1,ACIC=0 */
  SOPT2 = 0x06;                                      
  /* SPMSC1: LVWF=0,LVWACK=0,LVWIE=0,LVDRE=1,LVDSE=1,LVDE=1,BGBE=0 */
  SPMSC1 = 0x1C;                                      
  /* SPMSC2: LVDV=0,LVWV=0,PPDF=0,PPDACK=0,PPDC=1 */
  SPMSC2 = 0x01;                                      
  /* Initialization of CPU registers */
  asm {
    /* VBR: ADDRESS=0 */
    clr.l d0
    movec d0,VBR
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,FSD=0 */
    clr.l d0
    movec d0,CPUCR
  }
  /*  System clock initialization */
  if (*(unsigned char*far)0x03FF != 0xFF) { /* Test if the device trim value is stored on the specified address */
    MCGTRM = *(unsigned char*far)0x03FF; /* Initialize MCGTRM register from a non volatile memory */
    MCGSC = *(unsigned char*far)0x03FE; /* Initialize MCGSC register from a non volatile memory */
  }
  /* MCGC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  MCGC2 = 0x00;                        /* Set MCGC2 register */
  /* MCGC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  MCGC1 = 0x06;                        /* Set MCGC1 register */
  /* MCGC3: LOLIE=0,PLLS=0,CME=0,DIV32=0,VDIV=1 */
  MCGC3 = 0x01;                        /* Set MCGC3 register */
  /* MCGC4: DMX32=0,DRST_DRS=2 */
  MCGC4 = 0x02;                        /* Set MCGC4 register */
  while(!MCGSC_LOCK) {                 /* Wait until FLL is locked */
  }
  
    /* INTC_WCR: ENB=1,MASK=0 */
  INTC_WCR = 0x80;   
#endif  
 
}

/*
** ===================================================================
**     Method      :  MCU_init (component MCF51JM128_64)
**
**     Description :
**         Device initialization code for selected peripherals.
** ===================================================================
*/
void MCU_init(void)
{
  /* SCGC1: CMT=1,TPM2=1,TPM1=1,ADC=1,IIC2=1,IIC1=1,SCI2=1,SCI1=1 */
  SCGC1 = 0xFF;                                      
  /* SCGC2: USB=1,FLS=1,IRQ=1,KBI=1,ACMP=1,RTC=1,SPI2=1,SPI1=1 */
  SCGC2 = 0xFF;                                      
  /* SCGC3: RNGA=1 */
  SCGC3 = 0xFF;                                      
} /*MCU_init*/


/*
** ===================================================================
**     Interrupt handler : isr_default
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isr_default(void)
{
  /* Write your interrupt code here ... */

}
/* end of isr_default */



/* Initialization of the CPU registers in FLASH */

/* NVPROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
/*Bootloader + BRTOS code space 12kB*/
//unsigned char NVPROT_INIT @0x0000040D = 0xE7;
const byte NVPROT_INIT @0x0000040D  = 0xFF;    // 0x00000000-0x00000FFF are protected    

/* NVOPT: KEYEN1=0,KEYEN0=1,SEC1=1,SEC0=1 */
unsigned char NVOPT_INIT @0x0000040F = 0x7F;




#ifdef __cplusplus
extern "C" {
#endif
extern void _startup(void);
extern unsigned long far _SP_INIT[];

#ifdef __cplusplus
}
#endif

/* Interrupt vector table */
#ifndef UNASSIGNED_ISR
  #define UNASSIGNED_ISR isr_default   /* unassigned interrupt service routine */
#endif
#define dummy_ISR isr_default          /* unassigned interrupt service routine */

extern void SwitchContext(void);
extern void TickTimer(void);
extern void USB_ISR(void);
extern void Radio_Interrupt(void);

#if (DEBUG == 0)  
  extern void serial_rx(void);
  extern void serial_tx(void);
  extern void serial_erro(void);
#endif

typedef void (* pFun)(void);


void  (* const RAM_vector[])()@0x00002000= {
    (pFun)&dummy_ISR,             // vector_0  INITSP
    (pFun)&dummy_ISR,             // vector_1  INITPC
    (pFun)&dummy_ISR,             // vector_2  Vaccerr
    (pFun)&dummy_ISR,             // vector_3  Vadderr
    (pFun)&dummy_ISR,             // vector_4  Viinstr
    (pFun)&dummy_ISR,             // vector_5  VReserved5
    (pFun)&dummy_ISR,             // vector_6  VReserved6
    (pFun)&dummy_ISR,             // vector_7  VReserved7
    (pFun)&dummy_ISR,             // vector_8  Vprviol
    (pFun)&dummy_ISR,             // vector_9  Vtrace
    (pFun)&dummy_ISR,             // vector_10 Vunilaop
    (pFun)&dummy_ISR,             // vector_11 Vunilfop
    (pFun)&dummy_ISR,             // vector_12 Vdbgi
    (pFun)&dummy_ISR,             // vector_13 VReserved13
    (pFun)&dummy_ISR,             // vector_14 Vferror
    (pFun)&dummy_ISR,             // vector_15 VReserved15
    (pFun)&dummy_ISR,             // vector_16 VReserved16
    (pFun)&dummy_ISR,             // vector_17 VReserved17
    (pFun)&dummy_ISR,             // vector_18 VReserved18
    (pFun)&dummy_ISR,             // vector_19 VReserved19
    (pFun)&dummy_ISR,             // vector_20 VReserved20
    (pFun)&dummy_ISR,             // vector_21 VReserved21
    (pFun)&dummy_ISR,             // vector_22 VReserved22
    (pFun)&dummy_ISR,             // vector_23 VReserved23
    (pFun)&dummy_ISR,             // vector_24 Vspuri           
    (pFun)&dummy_ISR,             // vector_25 VReserved25
    (pFun)&dummy_ISR,             // vector_26 VReserved26
    (pFun)&dummy_ISR,             // vector_27 VReserved27 
    (pFun)&dummy_ISR,             // vector_28 VReserved28
    (pFun)&dummy_ISR,             // vector_29 VReserved29
    (pFun)&dummy_ISR,             // vector_30 VReserved30
    (pFun)&dummy_ISR,             // vector_31 VReserved31
    (pFun)&dummy_ISR,             // vector_32 Vtrap0
    (pFun)&dummy_ISR,             // vector_33 Vtrap1
    (pFun)&dummy_ISR,             // vector_34 Vtrap2 
    (pFun)&dummy_ISR,             // vector_35 Vtrap3
    (pFun)&dummy_ISR,             // vector_36 Vtrap4
    (pFun)&dummy_ISR,             // vector_37 Vtrap5
    (pFun)&dummy_ISR,             // vector_38 Vtrap6
    (pFun)&dummy_ISR,             // vector_39 Vtrap7
    (pFun)&dummy_ISR,             // vector_40 Vtrap8
    (pFun)&dummy_ISR,             // vector_41 Vtrap9 
    (pFun)&dummy_ISR,             // vector_42 Vtrap10
    (pFun)&dummy_ISR,             // vector_43 Vtrap11
    (pFun)&dummy_ISR,             // vector_44 Vtrap12
    (pFun)&dummy_ISR,             // vector_45 Vtrap13 
    (pFun)&SwitchContext,         // vector_46 Vtrap14
    (pFun)&dummy_ISR,             // vector_47 Vtrap15
    (pFun)&dummy_ISR,             // vector_48 VReserved48
    (pFun)&dummy_ISR,             // vector_49 VReserved49
    (pFun)&dummy_ISR,             // vector_50 VReserved50
    (pFun)&dummy_ISR,             // vector_51 VReserved51
    (pFun)&dummy_ISR,             // vector_52 VReserved52
    (pFun)&dummy_ISR,             // vector_53 VReserved53
    (pFun)&dummy_ISR,             // vector_54 VReserved54
    (pFun)&dummy_ISR,             // vector_55 VReserved55
    (pFun)&dummy_ISR,             // vector_56 VReserved56
    (pFun)&dummy_ISR,             // vector_57 VReserved57
    (pFun)&dummy_ISR,             // vector_58 VReserved58
    (pFun)&dummy_ISR,             // vector_59 VReserved59
    (pFun)&dummy_ISR,             // vector_60 VReserved60        
    (pFun)&dummy_ISR,             // vector_61 Vunsinstr
    (pFun)&dummy_ISR,             // vector_62 VReserved62
    (pFun)&dummy_ISR,             // vector_63 VReserved63
    (pFun)&dummy_ISR,             // vector_64 Virq
    (pFun)&dummy_ISR,             // vector_65 Vlvd
    (pFun)&dummy_ISR,             // vector_66 Vlol
    (pFun)&dummy_ISR,             // vector_67 Vspi1
    (pFun)&dummy_ISR,             // vector_68 Vspi2
    (pFun)&USB_ISR,               // vector_69 Vusb
    (pFun)&dummy_ISR,             // vector_70 VReserved70
    (pFun)&dummy_ISR,             // vector_71 Vtpm1ch0
    (pFun)&dummy_ISR,             // vector_72 Vtpm1ch1  
    (pFun)&dummy_ISR,             // vector_73 Vtpm1ch2
    #if (RF_INT_TYPE == RF_INT_TIMER)
      (pFun)&Radio_Interrupt,       // vector_74 Vtpm1ch3
    #else
      (pFun)&dummy_ISR,             // vector_74 Vtpm1ch3
    #endif
    (pFun)&dummy_ISR,             // vector_75 Vtpm1ch4
    (pFun)&dummy_ISR,             // vector_76 Vtpm1ch5
    (pFun)&dummy_ISR,             // vector_77 Vtpm1ovf
    (pFun)&dummy_ISR,             // vector_78 Vtpm2ch0
    (pFun)&dummy_ISR,             // vector_79 Vtpm2ch1
    (pFun)&TickTimer,             // vector_80 Vtpm2ovrf    
#if (DEBUG == 0 && UART==1)          
    (pFun)&serial_erro,           // vector_81 Vsci1err
    (pFun)&serial_rx,             // vector_82 Vsci1rx
    (pFun)&serial_tx,             // vector_83 Vsci1tx
#else
    (pFun)&dummy_ISR,             // vector_81 Vsci1err
    (pFun)&dummy_ISR,             // vector_82 Vsci1rx
    (pFun)&dummy_ISR,             // vector_83 Vsci1tx    
#endif    
#if (DEBUG == 0 && UART==2)    
    (pFun)&serial_erro,           // vector_84 Vsci2err
    (pFun)&serial_rx,             // vector_85 Vsci2rx
    (pFun)&serial_tx,             // vector_86 Vsci2tx
#else
    (pFun)&dummy_ISR,           // vector_84 Vsci2err
    (pFun)&dummy_ISR,             // vector_85 Vsci2rx
    (pFun)&dummy_ISR,             // vector_86 Vsci2tx    
#endif  
    #if (RF_INT_TYPE == RF_INT_KEYB)
      (pFun)&Radio_Interrupt,       // vector_87 Vkeyboard    
    #else
      (pFun)&dummy_ISR,             // vector_87 Vkeyboard
    #endif
    (pFun)&dummy_ISR,             // vector_88 Vadc
    (pFun)&dummy_ISR,             // vector_89 Vacmpx
    (pFun)&dummy_ISR,             // vector_90 Viic1x
    (pFun)&dummy_ISR,             // vector_91 Vrtc
    (pFun)&dummy_ISR,             // vector_92 Viic2x
    (pFun)&dummy_ISR,             // vector_93 Vcmt
    (pFun)&dummy_ISR,             // vector_94 Vcanwu
    (pFun)&dummy_ISR,             // vector_95 Vcanerr
    (pFun)&dummy_ISR,             // vector_96 Vcanrx
    (pFun)&dummy_ISR,             // vector_97 Vcantx
    (pFun)&dummy_ISR,             // vector_98 Vrnga        
    (pFun)&dummy_ISR,             // VReserved99
    (pFun)&dummy_ISR,             // VReserved100
    (pFun)&dummy_ISR,             // VReserved101
    (pFun)&dummy_ISR,             // VReserved102
    (pFun)&dummy_ISR,             // VReserved103    
    (pFun)&dummy_ISR,             // VL7swi
    (pFun)&dummy_ISR,             // VL6swi
    (pFun)&dummy_ISR,             // VL5swi
    (pFun)&dummy_ISR,             // VL4swi
    (pFun)&dummy_ISR,             // VL3swi
    (pFun)&dummy_ISR,             // VL2swi
    (pFun)&dummy_ISR,             // VL1swi
};

void ISR_vtable_reallocation(void);

void ISR_vtable_reallocation(void)
{  
// vector table reallocation into RAM
/**************************************/ 
  dword *pdst,*psrc;
  byte i;   
  
  asm (move.l  #0x00800000,d0);
  asm (movec   d0,vbr);    

  pdst=(dword*)0x00800000;
  psrc=(dword*)&RAM_vector;

  for (i=0;i<110;i++,pdst++,psrc++)
  {
    *pdst=*psrc;
  }
/**************************************/ 
}


void  (* const _UserEntry[])()@0x410=
{
  (void *const)0x4E714EF9,           //asm NOP(0x4E71), asm JMP(0x4EF9)         
  _startup,
}; 

/* Bootloader entry point */
void _Entry(void); 
                                                                /*Address    Lvl Pri */
void (*const vector_0)(void)   @INITSP       = (void(*const )(void))_SP_INIT; /*0x00000000 -   - */
void (*const vector_1)(void)   @INITPC       = _Entry;          /*0x00000004 -   - */
void (*const vector_2)(void)   @Vaccerr      = UNASSIGNED_ISR;  /*0x00000008 -   - */
void (*const vector_3)(void)   @Vadderr      = UNASSIGNED_ISR;  /*0x0000000C -   - */
void (*const vector_4)(void)   @Viinstr      = UNASSIGNED_ISR;  /*0x00000010 -   - */
void (*const vector_5)(void)   @VReserved5   = UNASSIGNED_ISR;  /*0x00000014 -   - */
void (*const vector_6)(void)   @VReserved6   = UNASSIGNED_ISR;  /*0x00000018 -   - */
void (*const vector_7)(void)   @VReserved7   = UNASSIGNED_ISR;  /*0x0000001C -   - */
void (*const vector_8)(void)   @Vprviol      = UNASSIGNED_ISR;  /*0x00000020 -   - */
void (*const vector_9)(void)   @Vtrace       = UNASSIGNED_ISR;  /*0x00000024 -   - */
void (*const vector_10)(void)  @Vunilaop     = UNASSIGNED_ISR;  /*0x00000028 -   - */
void (*const vector_11)(void)  @Vunilfop     = UNASSIGNED_ISR;  /*0x0000002C -   - */
void (*const vector_12)(void)  @Vdbgi        = UNASSIGNED_ISR;  /*0x00000030 -   - */
void (*const vector_13)(void)  @VReserved13  = UNASSIGNED_ISR;  /*0x00000034 -   - */
void (*const vector_14)(void)  @Vferror      = UNASSIGNED_ISR;  /*0x00000038 -   - */
void (*const vector_15)(void)  @VReserved15  = UNASSIGNED_ISR;  /*0x0000003C -   - */
void (*const vector_16)(void)  @VReserved16  = UNASSIGNED_ISR;  /*0x00000040 -   - */
void (*const vector_17)(void)  @VReserved17  = UNASSIGNED_ISR;  /*0x00000044 -   - */
void (*const vector_18)(void)  @VReserved18  = UNASSIGNED_ISR;  /*0x00000048 -   - */
void (*const vector_19)(void)  @VReserved19  = UNASSIGNED_ISR;  /*0x0000004C -   - */
void (*const vector_20)(void)  @VReserved20  = UNASSIGNED_ISR;  /*0x00000050 -   - */
void (*const vector_21)(void)  @VReserved21  = UNASSIGNED_ISR;  /*0x00000054 -   - */
void (*const vector_22)(void)  @VReserved22  = UNASSIGNED_ISR;  /*0x00000058 -   - */
void (*const vector_23)(void)  @VReserved23  = UNASSIGNED_ISR;  /*0x0000005C -   - */
void (*const vector_24)(void)  @Vspuri       = UNASSIGNED_ISR;  /*0x00000060 -   - */
void (*const vector_25)(void)  @VReserved25  = UNASSIGNED_ISR;  /*0x00000064 -   - */
void (*const vector_26)(void)  @VReserved26  = UNASSIGNED_ISR;  /*0x00000068 -   - */
void (*const vector_27)(void)  @VReserved27  = UNASSIGNED_ISR;  /*0x0000006C -   - */
void (*const vector_28)(void)  @VReserved28  = UNASSIGNED_ISR;  /*0x00000070 -   - */
void (*const vector_29)(void)  @VReserved29  = UNASSIGNED_ISR;  /*0x00000074 -   - */
void (*const vector_30)(void)  @VReserved30  = UNASSIGNED_ISR;  /*0x00000078 -   - */
void (*const vector_31)(void)  @VReserved31  = UNASSIGNED_ISR;  /*0x0000007C -   - */
void (*const vector_32)(void)  @Vtrap0       = UNASSIGNED_ISR;  /*0x00000080 -   - */
void (*const vector_33)(void)  @Vtrap1       = UNASSIGNED_ISR;  /*0x00000084 -   - */
void (*const vector_34)(void)  @Vtrap2       = UNASSIGNED_ISR;  /*0x00000088 -   - */
void (*const vector_35)(void)  @Vtrap3       = UNASSIGNED_ISR;  /*0x0000008C -   - */
void (*const vector_36)(void)  @Vtrap4       = UNASSIGNED_ISR;  /*0x00000090 -   - */
void (*const vector_37)(void)  @Vtrap5       = UNASSIGNED_ISR;  /*0x00000094 -   - */
void (*const vector_38)(void)  @Vtrap6       = UNASSIGNED_ISR;  /*0x00000098 -   - */
void (*const vector_39)(void)  @Vtrap7       = UNASSIGNED_ISR;  /*0x0000009C -   - */
void (*const vector_40)(void)  @Vtrap8       = UNASSIGNED_ISR;  /*0x000000A0 -   - */
void (*const vector_41)(void)  @Vtrap9       = UNASSIGNED_ISR;  /*0x000000A4 -   - */
void (*const vector_42)(void)  @Vtrap10      = UNASSIGNED_ISR;  /*0x000000A8 -   - */
void (*const vector_43)(void)  @Vtrap11      = UNASSIGNED_ISR;  /*0x000000AC -   - */
void (*const vector_44)(void)  @Vtrap12      = UNASSIGNED_ISR;  /*0x000000B0 -   - */
void (*const vector_45)(void)  @Vtrap13      = UNASSIGNED_ISR;  /*0x000000B4 -   - */
void (*const vector_46)(void)  @Vtrap14      = SwitchContext;   /*0x000000B8 -   - */
void (*const vector_47)(void)  @Vtrap15      = UNASSIGNED_ISR;  /*0x000000BC -   - */
void (*const vector_48)(void)  @VReserved48  = UNASSIGNED_ISR;  /*0x000000C0 -   - */
void (*const vector_49)(void)  @VReserved49  = UNASSIGNED_ISR;  /*0x000000C4 -   - */
void (*const vector_50)(void)  @VReserved50  = UNASSIGNED_ISR;  /*0x000000C8 -   - */
void (*const vector_51)(void)  @VReserved51  = UNASSIGNED_ISR;  /*0x000000CC -   - */
void (*const vector_52)(void)  @VReserved52  = UNASSIGNED_ISR;  /*0x000000D0 -   - */
void (*const vector_53)(void)  @VReserved53  = UNASSIGNED_ISR;  /*0x000000D4 -   - */
void (*const vector_54)(void)  @VReserved54  = UNASSIGNED_ISR;  /*0x000000D8 -   - */
void (*const vector_55)(void)  @VReserved55  = UNASSIGNED_ISR;  /*0x000000DC -   - */
void (*const vector_56)(void)  @VReserved56  = UNASSIGNED_ISR;  /*0x000000E0 -   - */
void (*const vector_57)(void)  @VReserved57  = UNASSIGNED_ISR;  /*0x000000E4 -   - */
void (*const vector_58)(void)  @VReserved58  = UNASSIGNED_ISR;  /*0x000000E8 -   - */
void (*const vector_59)(void)  @VReserved59  = UNASSIGNED_ISR;  /*0x000000EC -   - */
void (*const vector_60)(void)  @VReserved60  = UNASSIGNED_ISR;  /*0x000000F0 -   - */
void (*const vector_61)(void)  @Vunsinstr    = UNASSIGNED_ISR;  /*0x000000F4 -   - */
void (*const vector_62)(void)  @VReserved62  = UNASSIGNED_ISR;  /*0x000000F8 -   - */
void (*const vector_63)(void)  @VReserved63  = UNASSIGNED_ISR;  /*0x000000FC -   - */
void (*const vector_64)(void)  @Virq         = UNASSIGNED_ISR;  /*0x00000100 -   - */
void (*const vector_65)(void)  @Vlvd         = UNASSIGNED_ISR;  /*0x00000104 -   - */
void (*const vector_66)(void)  @Vlol         = UNASSIGNED_ISR;  /*0x00000108 -   - */
void (*const vector_67)(void)  @Vspi1        = UNASSIGNED_ISR;  /*0x0000010C -   - */
void (*const vector_68)(void)  @Vspi2        = UNASSIGNED_ISR;  /*0x00000110 -   - */
void (*const vector_69)(void)  @Vusb         = USB_ISR;         /*0x00000114 -   - */
void (*const vector_70)(void)  @VReserved70  = UNASSIGNED_ISR;  /*0x00000118 -   - */
void (*const vector_71)(void)  @Vtpm1ch0     = UNASSIGNED_ISR;  /*0x0000011C -   - */
void (*const vector_72)(void)  @Vtpm1ch1     = UNASSIGNED_ISR;  /*0x00000120 -   - */
void (*const vector_73)(void)  @Vtpm1ch2     = UNASSIGNED_ISR;  /*0x00000124 -   - */
#if (RF_INT_TYPE == RF_INT_TIMER)
  void (*const vector_74)(void)  @Vtpm1ch3   = Radio_Interrupt; /*0x00000128 -   - */
#else
  void (*const vector_74)(void)  @Vtpm1ch3   = UNASSIGNED_ISR; /*0x00000128 -   - */
#endif
void (*const vector_75)(void)  @Vtpm1ch4     = UNASSIGNED_ISR;  /*0x0000012C -   - */
void (*const vector_76)(void)  @Vtpm1ch5     = UNASSIGNED_ISR;  /*0x00000130 -   - */
void (*const vector_77)(void)  @Vtpm1ovf     = UNASSIGNED_ISR;  /*0x00000134 -   - */
void (*const vector_78)(void)  @Vtpm2ch0     = UNASSIGNED_ISR;  /*0x00000138 -   - */
void (*const vector_79)(void)  @Vtpm2ch1     = UNASSIGNED_ISR;  /*0x0000013C -   - */
void (*const vector_80)(void)  @Vtpm2ovf     = TickTimer;       /*0x00000140 -   - */
#if (DEBUG == 0 && UART==1) 
void (*const vector_81)(void)  @Vsci1err     = serial_erro;  /*0x00000144 -   - */
void (*const vector_82)(void)  @Vsci1rx      = serial_rx;    /*0x00000148 -   - */
void (*const vector_83)(void)  @Vsci1tx      = serial_tx;    /*0x0000014C -   - */
#else
void (*const vector_81)(void)  @Vsci1err     = UNASSIGNED_ISR;  /*0x00000144 -   - */
void (*const vector_82)(void)  @Vsci1rx      = UNASSIGNED_ISR;    /*0x00000148 -   - */
void (*const vector_83)(void)  @Vsci1tx      = UNASSIGNED_ISR;    /*0x0000014C -   - */
#endif
#if (DEBUG == 0 && UART==2) 
void (*const vector_84)(void)  @Vsci2err     = serial_erro;  /*0x00000150 -   - */
void (*const vector_85)(void)  @Vsci2rx      = serial_rx;    /*0x00000154 -   - */
void (*const vector_86)(void)  @Vsci2tx      = serial_tx;    /*0x00000158 -   - */
#else
void (*const vector_84)(void)  @Vsci2err     = UNASSIGNED_ISR;  /*0x00000150 -   - */
void (*const vector_85)(void)  @Vsci2rx      = UNASSIGNED_ISR;    /*0x00000154 -   - */
void (*const vector_86)(void)  @Vsci2tx      = UNASSIGNED_ISR;    /*0x00000158 -   - */
#endif
#if (RF_INT_TYPE == RF_INT_KEYB)
  void (*const vector_87)(void)  @Vkeyboard  = Radio_Interrupt;  /*0x0000015C -   - */
#else
  void (*const vector_87)(void)  @Vkeyboard  = UNASSIGNED_ISR;  /*0x0000015C -   - */
#endif
void (*const vector_88)(void)  @Vadc         = UNASSIGNED_ISR;  /*0x00000160 -   - */
void (*const vector_89)(void)  @Vacmpx       = UNASSIGNED_ISR;  /*0x00000164 -   - */
void (*const vector_90)(void)  @Viic1x       = UNASSIGNED_ISR;  /*0x00000168 -   - */
void (*const vector_91)(void)  @Vrtc         = UNASSIGNED_ISR;  /*0x0000016C -   - */
void (*const vector_92)(void)  @Viic2x       = UNASSIGNED_ISR;  /*0x00000170 -   - */
void (*const vector_93)(void)  @Vcmt         = UNASSIGNED_ISR;  /*0x00000174 -   - */
void (*const vector_94)(void)  @Vcanwu       = UNASSIGNED_ISR;  /*0x00000178 -   - */
void (*const vector_95)(void)  @Vcanerr      = UNASSIGNED_ISR;  /*0x0000017C -   - */
void (*const vector_96)(void)  @Vcanrx       = UNASSIGNED_ISR;  /*0x00000180 -   - */
void (*const vector_97)(void)  @Vcantx       = UNASSIGNED_ISR;  /*0x00000184 -   - */
void (*const vector_98)(void)  @Vrnga        = UNASSIGNED_ISR;  /*0x00000188 -   - */
void (*const vector_99)(void)  @VReserved99  = UNASSIGNED_ISR;  /*0x0000018C -   - */
void (*const vector_100)(void) @VReserved100 = UNASSIGNED_ISR;  /*0x00000190 -   - */
void (*const vector_101)(void) @VReserved101 = UNASSIGNED_ISR;  /*0x00000194 -   - */
void (*const vector_102)(void) @VReserved102 = UNASSIGNED_ISR;  /*0x00000198 -   - */
void (*const vector_103)(void) @VReserved103 = UNASSIGNED_ISR;  /*0x0000019C -   - */
void (*const vector_104)(void) @VL7swi       = UNASSIGNED_ISR;  /*0x000001A0 -   - */
void (*const vector_105)(void) @VL6swi       = UNASSIGNED_ISR;  /*0x000001A4 -   - */
void (*const vector_106)(void) @VL5swi       = UNASSIGNED_ISR;  /*0x000001A8 -   - */
void (*const vector_107)(void) @VL4swi       = UNASSIGNED_ISR;  /*0x000001AC -   - */
void (*const vector_108)(void) @VL3swi       = UNASSIGNED_ISR;  /*0x000001B0 -   - */
void (*const vector_109)(void) @VL2swi       = UNASSIGNED_ISR;  /*0x000001B4 -   - */
void (*const vector_110)(void) @VL1swi       = UNASSIGNED_ISR;  /*0x000001B8 -   - */




/* END MCUinit */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/