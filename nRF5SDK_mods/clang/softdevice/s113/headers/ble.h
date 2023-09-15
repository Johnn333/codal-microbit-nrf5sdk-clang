// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/ble.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
  @addtogroup BLE_COMMON BLE SoftDevice Common
  @{
  @defgroup ble_api Events, type definitions and API calls
  @{

  @brief Module independent events, type definitions and API calls for the BLE SoftDevice.

 */

// Include the source file, so we keep upto date
#include "../../../../../nRF5SDK/components/softdevice/s113/headers/ble.h"

#ifdef __clang__

#ifndef _CLANG_BLE_H_
#define _CLANG_BLE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../clang_svc_macro.h"

static inline uint32_t
sd_ble_enable(uint32_t * p_app_ram_base) {
   _SYSCALL1(SD_BLE_ENABLE, p_app_ram_base);
}

static inline uint32_t
sd_ble_cfg_set(uint32_t cfg_id, ble_cfg_t const * p_cfg, uint32_t app_ram_base) {
   _SYSCALL3(SD_BLE_CFG_SET, cfg_id, p_cfg, app_ram_base);
}

static inline uint32_t
sd_ble_evt_get(uint8_t *p_dest, uint16_t *p_len) {
   _SYSCALL2(SD_BLE_EVT_GET, p_dest, p_len);
}

static inline uint32_t
sd_ble_uuid_vs_add(ble_uuid128_t const *p_vs_uuid, uint8_t *p_uuid_type) {
   _SYSCALL2(SD_BLE_UUID_VS_ADD, p_vs_uuid, p_uuid_type);
}

static inline uint32_t
sd_ble_uuid_vs_remove(uint8_t *p_uuid_type) {
   _SYSCALL1(SD_BLE_UUID_VS_REMOVE, p_uuid_type);
}

static inline uint32_t
sd_ble_uuid_decode(uint8_t uuid_le_len, uint8_t const *p_uuid_le, ble_uuid_t *p_uuid) {
   _SYSCALL3(SD_BLE_UUID_DECODE, uuid_le_len, p_uuid_le, p_uuid);
}

static inline uint32_t
sd_ble_uuid_encode(ble_uuid_t const *p_uuid, uint8_t *p_uuid_le_len, uint8_t *p_uuid_le) {
   _SYSCALL3(SD_BLE_UUID_ENCODE, p_uuid, p_uuid_le_len, p_uuid_le);
}

static inline uint32_t
sd_ble_version_get(ble_version_t *p_version) {
   _SYSCALL1(SD_BLE_VERSION_GET, p_version);
}

static inline uint32_t
sd_ble_user_mem_reply(uint16_t conn_handle, ble_user_mem_block_t const *p_block) {
   _SYSCALL2(SD_BLE_USER_MEM_REPLY, conn_handle, p_block);
}

static inline uint32_t
sd_ble_opt_set(uint32_t opt_id, ble_opt_t const *p_opt) {
   _SYSCALL2(SD_BLE_OPT_SET, opt_id, p_opt);
}

static inline uint32_t
sd_ble_opt_get(uint32_t opt_id, ble_opt_t *p_opt) {
   _SYSCALL2(SD_BLE_OPT_GET, opt_id, p_opt);
}


#ifdef __cplusplus
}
#endif

#endif // _CLANG_BLE_H_

#endif // __clang__

