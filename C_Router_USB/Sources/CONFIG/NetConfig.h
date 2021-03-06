#ifndef GPS_NWK_DEF_H
#define GPS_NWK_DEF_H

#include "BRTOS.h"

/// Define network support
#define NETWORK_ENABLE                      1

// Tipos de n�s na rede
#define   PAN_COORDINATOR                   0
#define   ROUTER                            1
#define   INSTALLER                         2

// Escolhe o tipo de n� na rede
#define   DEVICE_TYPE                       ROUTER

// DEPRECATED!!! - Keep disabled
// Reactive up route - 1 = on, 0 = off
#define USE_REACTIVE_UP_ROUTE               0

// Prioridade das tarefas de rede
#define RF_EventHandlerPriority     (INT8U)31
#define GPSNET_Mutex_Priority       (INT8U)28

#define MAC_HandlerPriority         (INT8U)22
#define NWK_HandlerPriority         (INT8U)23
#define APP1_Priority               (INT8U)26
#define APP2_Priority               (INT8U)25
#define APP3_Priority               (INT8U)24

// APPs signals 
#define SIGNAL_APP1                 App1_event
#define SIGNAL_APP2                 App2_event
#define SIGNAL_APP255               App255_event


// GPSNET Tasks Stacks
#if ((DEVICE_TYPE == PAN_COORDINATOR) || (DEVICE_TYPE == INSTALLER))
#define GPSNET_RF_Event_StackSize    (384)
#define GPSNET_MAC_StackSize         (384)
#define GPSNET_NWK_StackSize         (1280)
#else
#define GPSNET_RF_Event_StackSize    (288)
#define GPSNET_MAC_StackSize         (288)
#define GPSNET_NWK_StackSize         (1088)
#endif

// Init of the GPS Network tasks (used in the mutex)
#define GPSNET_TASKS_INIT 2

// Number of GPS Network tasks (used in the mutex)
#define GPSNET_TASKS      5

#define BRTOS_MUTEX       0
#define EMULATED_MUTEX    1
#define NWK_MUTEX_TYPE    EMULATED_MUTEX


/// RF Buffer Size
#define RFBufferSize      (INT16U)768


/// Memory locations for network address and configurations
#if (DEVICE_TYPE == PAN_COORDINATOR)
  #define LAT_MEM_ADDRESS    0x0001FC00
  #define LON_MEM_ADDRESS    0x0001FC04
  #define MAC16_MEM_ADDRESS
  #define MAC64_MEM_ADDRESS  0x00001FF0
  #define PANID_MEM_ADDRESS
  #define PANID_INIT_VALUE   0x4742
  #define MAC16_INIT_VALUE   0x0000
  #define ROUTC_INIT_VALUE   0x01
#else 
  #define LAT_MEM_ADDRESS    0x000021C0
  #define LON_MEM_ADDRESS    0x000021C4
  #define MAC16_MEM_ADDRESS  0x000021C8
  #define MAC64_MEM_ADDRESS  0x00001FF0
  #define PANID_MEM_ADDRESS  0x000021CC
  #define PANID_INIT_VALUE   0xFFFF
  #define MAC16_INIT_VALUE   0xFFFF
  #define ROUTC_INIT_VALUE   0x00
#endif

//IEEE EUI - globally unique number
#define EUI_7 0x0F
#define EUI_6 0x01
#define EUI_5 0x02
#define EUI_4 0x03
#define EUI_3 0x04
#define EUI_2 0x05
#define EUI_1 0x06
#define EUI_0 0x07

/// Configuration for tests only
#define GPSNET_TEST_POSITION

#ifdef GPSNET_TEST_POSITION

  
  #define TEST_POSITION_X       (71200)
  #define TEST_POSITION_Y       (6710000) 
   
  #define TEST_LAT_GPS_DEG      0x00
  #define TEST_LAT_GPS_MIN      0x01
  #define TEST_LAT_GPS_SEC      0x16
  #define TEST_LAT_GPS_DECSEC   0x20               

  #define TEST_LONG_GPS_DEG     0x00            
  #define TEST_LONG_GPS_MIN     0x66
  #define TEST_LONG_GPS_SEC     0x62
  #define TEST_LONG_GPS_DECSEC  0xF0 

/*

  #define TEST_POSITION_X       (20600)
  #define TEST_POSITION_Y       (5700)
 
  #define TEST_LAT_GPS_DEG      0x00
  #define TEST_LAT_GPS_MIN      0x00
  #define TEST_LAT_GPS_SEC      0x50
  #define TEST_LAT_GPS_DECSEC   0x78               

  #define TEST_LONG_GPS_DEG     0x00            
  #define TEST_LONG_GPS_MIN     0x00
  #define TEST_LONG_GPS_SEC     0x16
  #define TEST_LONG_GPS_DECSEC  0x44
  */
#endif

#define NUM_ALLOWED_CHANNELS 1



#endif


