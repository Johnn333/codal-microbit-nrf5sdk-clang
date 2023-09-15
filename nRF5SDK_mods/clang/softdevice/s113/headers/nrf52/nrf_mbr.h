// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/nrf52/nrf_mbr.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
  @defgroup nrf_mbr_api Master Boot Record API
  @{

  @brief APIs for updating SoftDevice and BootLoader

*/

// Include the source file, so we keep upto date
#include "../../../../../../nRF5SDK/components/softdevice/s113/headers/nrf52/nrf_mbr.h"

#ifdef __clang__

#ifndef _CLANG_NRF_MBR_H_
#define _CLANG_NRF_MBR_H_

#include "../../../../clang_svc_macro.h"

#endif // _CLANG_NRF_MBR_H_

#endif // __clang__