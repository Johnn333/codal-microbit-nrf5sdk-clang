// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/ble_gap.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
  @addtogroup BLE_GAP Generic Access Profile (GAP)
  @{
  @brief Definitions and prototypes for the GAP interface.
 */

// Include the source file, so we keep upto date
#include "../../../../../nRF5SDK/components/softdevice/s113/headers/ble_gap.h"

// Apply patch using macro
#ifdef __clang__

#ifndef _CLANG_BLE_GAP_H_
#define _CLANG_BLE_GAP_H_

#include "../../../clang_svc_macro.h"

#endif // _CLANG_BLE_GAP_H_
#endif // __clang__

