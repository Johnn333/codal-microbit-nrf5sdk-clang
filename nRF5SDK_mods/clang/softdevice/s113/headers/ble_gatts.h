// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/ble_gatts.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
  @addtogroup BLE_GATTS Generic Attribute Profile (GATT) Server
  @{
  @brief  Definitions and prototypes for the GATTS interface.
 */

// Include the source file, so we keep upto date
#include "../../../../../nRF5SDK/components/softdevice/s113/headers/ble_gatts.h"

#ifdef __clang__

#ifndef _CLANG_BLE_GATTS_H_
#define _CLANG_BLE_GATTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../clang_svc_macro.h"

static inline uint32_t
sd_ble_gatts_service_add(uint8_t type, ble_uuid_t const *p_uuid, uint16_t *p_handle) {
   _SYSCALL3(SD_BLE_GATTS_SERVICE_ADD, type, p_uuid, p_handle);
}

static inline uint32_t
sd_ble_gatts_include_add(uint16_t service_handle, uint16_t inc_srvc_handle, uint16_t *p_include_handle) {
   _SYSCALL3(SD_BLE_GATTS_INCLUDE_ADD, service_handle, inc_srvc_handle, p_include_handle);
}

static inline uint32_t
sd_ble_gatts_characteristic_add(uint16_t service_handle, ble_gatts_char_md_t const *p_char_md, ble_gatts_attr_t const *p_attr_char_value, ble_gatts_char_handles_t *p_handles) {
   _SYSCALL4(SD_BLE_GATTS_CHARACTERISTIC_ADD, service_handle, p_char_md, p_attr_char_value, p_handles);
}

static inline uint32_t
sd_ble_gatts_descriptor_add(uint16_t char_handle, ble_gatts_attr_t const *p_attr, uint16_t *p_handle) {
   _SYSCALL3(SD_BLE_GATTS_DESCRIPTOR_ADD, char_handle, p_attr, p_handle);
}

static inline uint32_t
sd_ble_gatts_value_set(uint16_t conn_handle, uint16_t handle, ble_gatts_value_t *p_value) {
   _SYSCALL3(SD_BLE_GATTS_VALUE_SET, conn_handle, handle, p_value);
}

static inline uint32_t
sd_ble_gatts_value_get(uint16_t conn_handle, uint16_t handle, ble_gatts_value_t *p_value) {
   _SYSCALL3(SD_BLE_GATTS_VALUE_GET, conn_handle, handle, p_value);
}

static inline uint32_t
sd_ble_gatts_hvx(uint16_t conn_handle, ble_gatts_hvx_params_t const *p_hvx_params) {
   _SYSCALL2(SD_BLE_GATTS_HVX, conn_handle, p_hvx_params);
}

static inline uint32_t
sd_ble_gatts_service_changed(uint16_t conn_handle, uint16_t start_handle, uint16_t end_handle) {
   _SYSCALL3(SD_BLE_GATTS_SERVICE_CHANGED, conn_handle, start_handle, end_handle);
}

static inline uint32_t
sd_ble_gatts_rw_authorize_reply(uint16_t conn_handle, ble_gatts_rw_authorize_reply_params_t const *p_rw_authorize_reply_params) {
   _SYSCALL2(SD_BLE_GATTS_RW_AUTHORIZE_REPLY, conn_handle, p_rw_authorize_reply_params);
}

static inline uint32_t
sd_ble_gatts_sys_attr_set(uint16_t conn_handle, uint8_t const *p_sys_attr_data, uint16_t len, uint32_t flags) {
   _SYSCALL4(SD_BLE_GATTS_SYS_ATTR_SET, conn_handle, p_sys_attr_data, len, flags);
}

static inline uint32_t
sd_ble_gatts_sys_attr_get(uint16_t conn_handle, uint8_t *p_sys_attr_data, uint16_t *p_len, uint32_t flags) {
   _SYSCALL4(SD_BLE_GATTS_SYS_ATTR_GET, conn_handle, p_sys_attr_data, p_len, flags);
}

static inline uint32_t
sd_ble_gatts_initial_user_handle_get(uint16_t *p_handle) {
   _SYSCALL1(SD_BLE_GATTS_INITIAL_USER_HANDLE_GET, p_handle);
}

static inline uint32_t
sd_ble_gatts_attr_get(uint16_t handle, ble_uuid_t * p_uuid, ble_gatts_attr_md_t * p_md) {
   _SYSCALL3(SD_BLE_GATTS_ATTR_GET, handle, p_uuid, p_md);
}

static inline uint32_t
sd_ble_gatts_exchange_mtu_reply(uint16_t conn_handle, uint16_t server_rx_mtu) {
   _SYSCALL2(SD_BLE_GATTS_EXCHANGE_MTU_REPLY, conn_handle, server_rx_mtu);
}


#ifdef __cplusplus
}
#endif

#endif // _CLANG_BLE_GATTS_H_

#endif // __clang__

