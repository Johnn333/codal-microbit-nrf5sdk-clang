// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/nrf_sdm.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
  @defgroup nrf_sdm_api SoftDevice Manager API
  @{

  @brief APIs for SoftDevice management.

*/

// Include the source file, so we keep upto date
#include "../../../../../nRF5SDK/components/softdevice/s113/headers/nrf_sdm.h"

#ifdef __clang__

#ifndef _CLANG_NRF_SDM_H_
#define _CLANG_NRF_SDM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../clang_svc_macro.h"

static inline uint32_t
sd_softdevice_enable(nrf_clock_lf_cfg_t const * p_clock_lf_cfg, nrf_fault_handler_t fault_handler) {
   _SYSCALL2(SD_SOFTDEVICE_ENABLE, p_clock_lf_cfg, fault_handler);
}

static inline uint32_t
sd_softdevice_disable(void) {
   _SYSCALL0(SD_SOFTDEVICE_DISABLE);
}

static inline uint32_t
sd_softdevice_is_enabled(uint8_t * p_softdevice_enabled) {
   _SYSCALL1(SD_SOFTDEVICE_IS_ENABLED, p_softdevice_enabled);
}

static inline uint32_t
sd_softdevice_vector_table_base_set(uint32_t address) {
   _SYSCALL1(SD_SOFTDEVICE_VECTOR_TABLE_BASE_SET, address);
}


#ifdef __cplusplus
}
#endif

#endif // _CLANG_NRF_SDM_H_

#endif // __clang__

