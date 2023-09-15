// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/ble_gattc.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
  @addtogroup BLE_GATTC Generic Attribute Profile (GATT) Client
  @{
  @brief  Definitions and prototypes for the GATT Client interface.
 */

// Include the source file, so we keep upto date
#include "../../../../../nRF5SDK/components/softdevice/s113/headers/ble_gattc.h"

// Apply patch using macro
#ifdef __clang__

#ifndef _CLANG_BLE_GATTC_H_
#define _CLANG_BLE_GATTC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../clang_svc_macro.h"

static inline uint32_t
sd_ble_gattc_primary_services_discover(uint16_t conn_handle, uint16_t start_handle, ble_uuid_t const *p_srvc_uuid) {
   _SYSCALL3(SD_BLE_GATTC_PRIMARY_SERVICES_DISCOVER, conn_handle, start_handle, p_srvc_uuid);
}

static inline uint32_t
sd_ble_gattc_relationships_discover(uint16_t conn_handle, ble_gattc_handle_range_t const *p_handle_range) {
   _SYSCALL2(SD_BLE_GATTC_RELATIONSHIPS_DISCOVER, conn_handle, p_handle_range);
}

static inline uint32_t
sd_ble_gattc_characteristics_discover(uint16_t conn_handle, ble_gattc_handle_range_t const *p_handle_range) {
   _SYSCALL2(SD_BLE_GATTC_CHARACTERISTICS_DISCOVER, conn_handle, p_handle_range);
}

static inline uint32_t
sd_ble_gattc_descriptors_discover(uint16_t conn_handle, ble_gattc_handle_range_t const *p_handle_range) {
   _SYSCALL2(SD_BLE_GATTC_DESCRIPTORS_DISCOVER, conn_handle, p_handle_range);
}

static inline uint32_t
sd_ble_gattc_char_value_by_uuid_read(uint16_t conn_handle, ble_uuid_t const *p_uuid, ble_gattc_handle_range_t const *p_handle_range) {
   _SYSCALL3(SD_BLE_GATTC_CHAR_VALUE_BY_UUID_READ, conn_handle, p_uuid, p_handle_range);
}

static inline uint32_t
sd_ble_gattc_read(uint16_t conn_handle, uint16_t handle, uint16_t offset) {
   _SYSCALL3(SD_BLE_GATTC_READ, conn_handle, handle, offset);
}

static inline uint32_t
sd_ble_gattc_char_values_read(uint16_t conn_handle, uint16_t const *p_handles, uint16_t handle_count) {
   _SYSCALL3(SD_BLE_GATTC_CHAR_VALUES_READ, conn_handle, p_handles, handle_count);
}

static inline uint32_t
sd_ble_gattc_write(uint16_t conn_handle, ble_gattc_write_params_t const *p_write_params) {
   _SYSCALL2(SD_BLE_GATTC_WRITE, conn_handle, p_write_params);
}

static inline uint32_t
sd_ble_gattc_hv_confirm(uint16_t conn_handle, uint16_t handle) {
   _SYSCALL2(SD_BLE_GATTC_HV_CONFIRM, conn_handle, handle);
}

static inline uint32_t
sd_ble_gattc_attr_info_discover(uint16_t conn_handle, ble_gattc_handle_range_t const * p_handle_range) {
   _SYSCALL2(SD_BLE_GATTC_ATTR_INFO_DISCOVER, conn_handle, p_handle_range);
}

static inline uint32_t
sd_ble_gattc_exchange_mtu_request(uint16_t conn_handle, uint16_t client_rx_mtu) {
   _SYSCALL2(SD_BLE_GATTC_EXCHANGE_MTU_REQUEST, conn_handle, client_rx_mtu);
}

#ifdef __cplusplus
}
#endif

#endif // _CLANG_BLE_GATTC_H_

#endif // __clang__

