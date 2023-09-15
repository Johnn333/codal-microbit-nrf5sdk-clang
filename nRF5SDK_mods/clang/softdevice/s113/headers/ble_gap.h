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

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../clang_svc_macro.h"

static inline uint32_t
sd_ble_gap_addr_set(ble_gap_addr_t const *p_addr) {
   _SYSCALL1(SD_BLE_GAP_ADDR_SET, p_addr);
}

static inline uint32_t
sd_ble_gap_addr_get(ble_gap_addr_t *p_addr) {
   _SYSCALL1(SD_BLE_GAP_ADDR_GET, p_addr);
}

static inline uint32_t
sd_ble_gap_adv_addr_get(uint8_t adv_handle, ble_gap_addr_t *p_addr) {
   _SYSCALL2(SD_BLE_GAP_ADV_ADDR_GET, adv_handle, p_addr);
}

static inline uint32_t
sd_ble_gap_whitelist_set(ble_gap_addr_t const * const * pp_wl_addrs, uint8_t len) {
   _SYSCALL2(SD_BLE_GAP_WHITELIST_SET, pp_wl_addrs, len);
}

static inline uint32_t
sd_ble_gap_device_identities_set(ble_gap_id_key_t const * const * pp_id_keys, ble_gap_irk_t const * const * pp_local_irks, uint8_t len) {
   _SYSCALL3(SD_BLE_GAP_DEVICE_IDENTITIES_SET, pp_id_keys, pp_local_irks, len);
}

static inline uint32_t
sd_ble_gap_privacy_set(ble_gap_privacy_params_t const *p_privacy_params) {
   _SYSCALL1(SD_BLE_GAP_PRIVACY_SET, p_privacy_params);
}

static inline uint32_t
sd_ble_gap_privacy_get(ble_gap_privacy_params_t *p_privacy_params) {
   _SYSCALL1(SD_BLE_GAP_PRIVACY_GET, p_privacy_params);
}

static inline uint32_t
sd_ble_gap_adv_set_configure(uint8_t *p_adv_handle, ble_gap_adv_data_t const *p_adv_data, ble_gap_adv_params_t const *p_adv_params) {
   _SYSCALL3(SD_BLE_GAP_ADV_SET_CONFIGURE, p_adv_handle, p_adv_data, p_adv_params);
}

static inline uint32_t
sd_ble_gap_adv_start(uint8_t adv_handle, uint8_t conn_cfg_tag) {
   _SYSCALL2(SD_BLE_GAP_ADV_START, adv_handle, conn_cfg_tag);
}

static inline uint32_t
sd_ble_gap_adv_stop(uint8_t adv_handle) {
   _SYSCALL1(SD_BLE_GAP_ADV_STOP, adv_handle);
}

static inline uint32_t
sd_ble_gap_conn_param_update(uint16_t conn_handle, ble_gap_conn_params_t const *p_conn_params) {
   _SYSCALL2(SD_BLE_GAP_CONN_PARAM_UPDATE, conn_handle, p_conn_params);
}

static inline uint32_t
sd_ble_gap_disconnect(uint16_t conn_handle, uint8_t hci_status_code) {
   _SYSCALL2(SD_BLE_GAP_DISCONNECT, conn_handle, hci_status_code);
}

static inline uint32_t
sd_ble_gap_tx_power_set(uint8_t role, uint16_t handle, int8_t tx_power) {
   _SYSCALL3(SD_BLE_GAP_TX_POWER_SET, role, handle, tx_power);
}

static inline uint32_t
sd_ble_gap_appearance_set(uint16_t appearance) {
   _SYSCALL1(SD_BLE_GAP_APPEARANCE_SET, appearance);
}

static inline uint32_t
sd_ble_gap_appearance_get(uint16_t *p_appearance) {
   _SYSCALL1(SD_BLE_GAP_APPEARANCE_GET, p_appearance);
}

static inline uint32_t
sd_ble_gap_ppcp_set(ble_gap_conn_params_t const *p_conn_params) {
   _SYSCALL1(SD_BLE_GAP_PPCP_SET, p_conn_params);
}

static inline uint32_t
sd_ble_gap_ppcp_get(ble_gap_conn_params_t *p_conn_params) {
   _SYSCALL1(SD_BLE_GAP_PPCP_GET, p_conn_params);
}

static inline uint32_t
sd_ble_gap_device_name_set(ble_gap_conn_sec_mode_t const *p_write_perm, uint8_t const *p_dev_name, uint16_t len) {
   _SYSCALL3(SD_BLE_GAP_DEVICE_NAME_SET, p_write_perm, p_dev_name, len);
}

static inline uint32_t
sd_ble_gap_device_name_get(uint8_t *p_dev_name, uint16_t *p_len) {
   _SYSCALL2(SD_BLE_GAP_DEVICE_NAME_GET, p_dev_name, p_len);
}

static inline uint32_t
sd_ble_gap_authenticate(uint16_t conn_handle, ble_gap_sec_params_t const *p_sec_params) {
   _SYSCALL2(SD_BLE_GAP_AUTHENTICATE, conn_handle, p_sec_params);
}

static inline uint32_t
sd_ble_gap_sec_params_reply(uint16_t conn_handle, uint8_t sec_status, ble_gap_sec_params_t const *p_sec_params, ble_gap_sec_keyset_t const *p_sec_keyset) {
   _SYSCALL4(SD_BLE_GAP_SEC_PARAMS_REPLY, conn_handle, sec_status, p_sec_params, p_sec_keyset);
}

static inline uint32_t
sd_ble_gap_auth_key_reply(uint16_t conn_handle, uint8_t key_type, uint8_t const *p_key) {
   _SYSCALL3(SD_BLE_GAP_AUTH_KEY_REPLY, conn_handle, key_type, p_key);
}

static inline uint32_t
sd_ble_gap_lesc_dhkey_reply(uint16_t conn_handle, ble_gap_lesc_dhkey_t const *p_dhkey) {
   _SYSCALL2(SD_BLE_GAP_LESC_DHKEY_REPLY, conn_handle, p_dhkey);
}

static inline uint32_t
sd_ble_gap_keypress_notify(uint16_t conn_handle, uint8_t kp_not) {
   _SYSCALL2(SD_BLE_GAP_KEYPRESS_NOTIFY, conn_handle, kp_not);
}

static inline uint32_t
sd_ble_gap_lesc_oob_data_get(uint16_t conn_handle, ble_gap_lesc_p256_pk_t const *p_pk_own, ble_gap_lesc_oob_data_t *p_oobd_own) {
   _SYSCALL3(SD_BLE_GAP_LESC_OOB_DATA_GET, conn_handle, p_pk_own, p_oobd_own);
}

static inline uint32_t
sd_ble_gap_lesc_oob_data_set(uint16_t conn_handle, ble_gap_lesc_oob_data_t const *p_oobd_own, ble_gap_lesc_oob_data_t const *p_oobd_peer) {
   _SYSCALL3(SD_BLE_GAP_LESC_OOB_DATA_SET, conn_handle, p_oobd_own, p_oobd_peer);
}

static inline uint32_t
sd_ble_gap_sec_info_reply(uint16_t conn_handle, ble_gap_enc_info_t const *p_enc_info, ble_gap_irk_t const *p_id_info, ble_gap_sign_info_t const *p_sign_info) {
   _SYSCALL4(SD_BLE_GAP_SEC_INFO_REPLY, conn_handle, p_enc_info, p_id_info, p_sign_info);
}

static inline uint32_t
sd_ble_gap_conn_sec_get(uint16_t conn_handle, ble_gap_conn_sec_t *p_conn_sec) {
   _SYSCALL2(SD_BLE_GAP_CONN_SEC_GET, conn_handle, p_conn_sec);
}

static inline uint32_t
sd_ble_gap_rssi_start(uint16_t conn_handle, uint8_t threshold_dbm, uint8_t skip_count) {
   _SYSCALL3(SD_BLE_GAP_RSSI_START, conn_handle, threshold_dbm, skip_count);
}

static inline uint32_t
sd_ble_gap_rssi_stop(uint16_t conn_handle) {
   _SYSCALL1(SD_BLE_GAP_RSSI_STOP, conn_handle);
}

static inline uint32_t
sd_ble_gap_rssi_get(uint16_t conn_handle, int8_t *p_rssi, uint8_t *p_ch_index) {
   _SYSCALL3(SD_BLE_GAP_RSSI_GET, conn_handle, p_rssi, p_ch_index);
}

static inline uint32_t
sd_ble_gap_phy_update(uint16_t conn_handle, ble_gap_phys_t const *p_gap_phys) {
   _SYSCALL2(SD_BLE_GAP_PHY_UPDATE, conn_handle, p_gap_phys);
}

static inline uint32_t
sd_ble_gap_data_length_update(uint16_t conn_handle, ble_gap_data_length_params_t const *p_dl_params, ble_gap_data_length_limitation_t *p_dl_limitation) {
   _SYSCALL3(SD_BLE_GAP_DATA_LENGTH_UPDATE, conn_handle, p_dl_params, p_dl_limitation);
}

static inline uint32_t
sd_ble_gap_next_conn_evt_counter_get(uint16_t conn_handle, uint16_t * p_counter) {
   _SYSCALL2(SD_BLE_GAP_NEXT_CONN_EVT_COUNTER_GET, conn_handle, p_counter);
}

static inline uint32_t
sd_ble_gap_conn_evt_trigger_start(uint16_t conn_handle, ble_gap_conn_event_trigger_t const * p_params) {
   _SYSCALL2(SD_BLE_GAP_CONN_EVT_TRIGGER_START, conn_handle, p_params);
}

static inline uint32_t
sd_ble_gap_conn_evt_trigger_stop(uint16_t conn_handle) {
   _SYSCALL1(SD_BLE_GAP_CONN_EVT_TRIGGER_STOP, conn_handle);
}

#ifdef __cplusplus
}
#endif

#endif // _CLANG_BLE_GAP_H_

#endif // __clang__

