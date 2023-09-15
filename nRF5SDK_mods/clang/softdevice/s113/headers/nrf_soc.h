// Taken from https://github.com/microbit-foundation/codal-microbit-nrf5sdk/blob/ef4662e13875a7b03e7296d7ac24a2b4d231f323/nRF5SDK/components/softdevice/s113/headers/nrf_soc.h
// This patch applied https://github.com/eblot/nrf5-llvm/blob/a76179789fe3df6c9e44e2acd93c6b7ed4bfe330/nrfsvc.py, using clang_svc_macro.h to append more code to the end.

/**
 * @defgroup nrf_soc_api SoC Library API
 * @{
 *
 * @brief APIs for the SoC library.
 *
 */

// Include the source file, so we keep upto date
#include "../../../../../nRF5SDK/components/softdevice/s113/headers/nrf_soc.h"

#ifdef __clang__

#ifndef _CLANG_NRF_SOC_H_
#define _CLANG_NRF_SOC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../clang_svc_macro.h"

static inline uint32_t
sd_mutex_new(nrf_mutex_t * p_mutex) {
   _SYSCALL1(SD_MUTEX_NEW, p_mutex);
}

static inline uint32_t
sd_mutex_acquire(nrf_mutex_t * p_mutex) {
   _SYSCALL1(SD_MUTEX_ACQUIRE, p_mutex);
}

static inline uint32_t
sd_mutex_release(nrf_mutex_t * p_mutex) {
   _SYSCALL1(SD_MUTEX_RELEASE, p_mutex);
}

static inline uint32_t
sd_rand_application_pool_capacity_get(uint8_t * p_pool_capacity) {
   _SYSCALL1(SD_RAND_APPLICATION_POOL_CAPACITY_GET, p_pool_capacity);
}

static inline uint32_t
sd_rand_application_bytes_available_get(uint8_t * p_bytes_available) {
   _SYSCALL1(SD_RAND_APPLICATION_BYTES_AVAILABLE_GET, p_bytes_available);
}

static inline uint32_t
sd_rand_application_vector_get(uint8_t * p_buff, uint8_t length) {
   _SYSCALL2(SD_RAND_APPLICATION_VECTOR_GET, p_buff, length);
}

static inline uint32_t
sd_power_reset_reason_get(uint32_t * p_reset_reason) {
   _SYSCALL1(SD_POWER_RESET_REASON_GET, p_reset_reason);
}

static inline uint32_t
sd_power_reset_reason_clr(uint32_t reset_reason_clr_msk) {
   _SYSCALL1(SD_POWER_RESET_REASON_CLR, reset_reason_clr_msk);
}

static inline uint32_t
sd_power_mode_set(uint8_t power_mode) {
   _SYSCALL1(SD_POWER_MODE_SET, power_mode);
}

static inline uint32_t
sd_power_system_off(void) {
   _SYSCALL0(SD_POWER_SYSTEM_OFF);
}

static inline uint32_t
sd_power_pof_enable(uint8_t pof_enable) {
   _SYSCALL1(SD_POWER_POF_ENABLE, pof_enable);
}

static inline uint32_t
sd_power_usbpwrrdy_enable(uint8_t usbpwrrdy_enable) {
   _SYSCALL1(SD_POWER_USBPWRRDY_ENABLE, usbpwrrdy_enable);
}

static inline uint32_t
sd_power_usbdetected_enable(uint8_t usbdetected_enable) {
   _SYSCALL1(SD_POWER_USBDETECTED_ENABLE, usbdetected_enable);
}

static inline uint32_t
sd_power_usbremoved_enable(uint8_t usbremoved_enable) {
   _SYSCALL1(SD_POWER_USBREMOVED_ENABLE, usbremoved_enable);
}

static inline uint32_t
sd_power_usbregstatus_get(uint32_t * usbregstatus) {
   _SYSCALL1(SD_POWER_USBREGSTATUS_GET, usbregstatus);
}

static inline uint32_t
sd_power_pof_threshold_set(uint8_t threshold) {
   _SYSCALL1(SD_POWER_POF_THRESHOLD_SET, threshold);
}

static inline uint32_t
sd_power_ram_power_set(uint8_t index, uint32_t ram_powerset) {
   _SYSCALL2(SD_POWER_RAM_POWER_SET, index, ram_powerset);
}

static inline uint32_t
sd_power_ram_power_clr(uint8_t index, uint32_t ram_powerclr) {
   _SYSCALL2(SD_POWER_RAM_POWER_CLR, index, ram_powerclr);
}

static inline uint32_t
sd_power_ram_power_get(uint8_t index, uint32_t * p_ram_power) {
   _SYSCALL2(SD_POWER_RAM_POWER_GET, index, p_ram_power);
}

static inline uint32_t
sd_power_gpregret_set(uint32_t gpregret_id, uint32_t gpregret_msk) {
   _SYSCALL2(SD_POWER_GPREGRET_SET, gpregret_id, gpregret_msk);
}

static inline uint32_t
sd_power_gpregret_clr(uint32_t gpregret_id, uint32_t gpregret_msk) {
   _SYSCALL2(SD_POWER_GPREGRET_CLR, gpregret_id, gpregret_msk);
}

static inline uint32_t
sd_power_gpregret_get(uint32_t gpregret_id, uint32_t *p_gpregret) {
   _SYSCALL2(SD_POWER_GPREGRET_GET, gpregret_id, p_gpregret);
}

static inline uint32_t
sd_power_dcdc_mode_set(uint8_t dcdc_mode) {
   _SYSCALL1(SD_POWER_DCDC_MODE_SET, dcdc_mode);
}

static inline uint32_t
sd_clock_hfclk_request(void) {
   _SYSCALL0(SD_CLOCK_HFCLK_REQUEST);
}

static inline uint32_t
sd_clock_hfclk_release(void) {
   _SYSCALL0(SD_CLOCK_HFCLK_RELEASE);
}

static inline uint32_t
sd_clock_hfclk_is_running(uint32_t * p_is_running) {
   _SYSCALL1(SD_CLOCK_HFCLK_IS_RUNNING, p_is_running);
}

static inline uint32_t
sd_app_evt_wait(void) {
   _SYSCALL0(SD_APP_EVT_WAIT);
}

static inline uint32_t
sd_ppi_channel_enable_get(uint32_t * p_channel_enable) {
   _SYSCALL1(SD_PPI_CHANNEL_ENABLE_GET, p_channel_enable);
}

static inline uint32_t
sd_ppi_channel_enable_set(uint32_t channel_enable_set_msk) {
   _SYSCALL1(SD_PPI_CHANNEL_ENABLE_SET, channel_enable_set_msk);
}

static inline uint32_t
sd_ppi_channel_enable_clr(uint32_t channel_enable_clr_msk) {
   _SYSCALL1(SD_PPI_CHANNEL_ENABLE_CLR, channel_enable_clr_msk);
}

static inline uint32_t
sd_ppi_channel_assign(uint8_t channel_num, const volatile void * evt_endpoint, const volatile void * task_endpoint) {
   _SYSCALL3(SD_PPI_CHANNEL_ASSIGN, channel_num, evt_endpoint, task_endpoint);
}

static inline uint32_t
sd_ppi_group_task_enable(uint8_t group_num) {
   _SYSCALL1(SD_PPI_GROUP_TASK_ENABLE, group_num);
}

static inline uint32_t
sd_ppi_group_task_disable(uint8_t group_num) {
   _SYSCALL1(SD_PPI_GROUP_TASK_DISABLE, group_num);
}

static inline uint32_t
sd_ppi_group_assign(uint8_t group_num, uint32_t channel_msk) {
   _SYSCALL2(SD_PPI_GROUP_ASSIGN, group_num, channel_msk);
}

static inline uint32_t
sd_ppi_group_get(uint8_t group_num, uint32_t * p_channel_msk) {
   _SYSCALL2(SD_PPI_GROUP_GET, group_num, p_channel_msk);
}

static inline uint32_t
sd_radio_notification_cfg_set(uint8_t type, uint8_t distance) {
   _SYSCALL2(SD_RADIO_NOTIFICATION_CFG_SET, type, distance);
}

static inline uint32_t
sd_ecb_block_encrypt(nrf_ecb_hal_data_t * p_ecb_data) {
   _SYSCALL1(SD_ECB_BLOCK_ENCRYPT, p_ecb_data);
}

static inline uint32_t
sd_ecb_blocks_encrypt(uint8_t block_count, nrf_ecb_hal_data_block_t * p_data_blocks) {
   _SYSCALL2(SD_ECB_BLOCKS_ENCRYPT, block_count, p_data_blocks);
}

static inline uint32_t
sd_evt_get(uint32_t * p_evt_id) {
   _SYSCALL1(SD_EVT_GET, p_evt_id);
}

static inline uint32_t
sd_temp_get(int32_t * p_temp) {
   _SYSCALL1(SD_TEMP_GET, p_temp);
}

static inline uint32_t
sd_flash_write(uint32_t * p_dst, uint32_t const * p_src, uint32_t size) {
   _SYSCALL3(SD_FLASH_WRITE, p_dst, p_src, size);
}

static inline uint32_t
sd_flash_page_erase(uint32_t page_number) {
   _SYSCALL1(SD_FLASH_PAGE_ERASE, page_number);
}

static inline uint32_t
sd_flash_protect(uint32_t block_cfg0, uint32_t block_cfg1, uint32_t block_cfg2, uint32_t block_cfg3) {
   _SYSCALL4(SD_FLASH_PROTECT, block_cfg0, block_cfg1, block_cfg2, block_cfg3);
}

static inline uint32_t
sd_radio_session_open(nrf_radio_signal_callback_t p_radio_signal_callback) {
   _SYSCALL1(SD_RADIO_SESSION_OPEN, p_radio_signal_callback);
}

static inline uint32_t
sd_radio_session_close(void) {
   _SYSCALL0(SD_RADIO_SESSION_CLOSE);
}

static inline uint32_t
sd_radio_request(nrf_radio_request_t const * p_request) {
   _SYSCALL1(SD_RADIO_REQUEST, p_request);
}

static inline uint32_t
sd_protected_register_write(volatile uint32_t * p_register, uint32_t value) {
   _SYSCALL2(SD_PROTECTED_REGISTER_WRITE, p_register, value);
}


#ifdef __cplusplus
}
#endif

#endif // _CLANG_NRF_SOC_H_

#endif // __clang__

