#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

#include "ets_sys.h"
#include "osapi.h"
#include "user_interface.h"
#include "os_type.h"
#include "mem.h"
#include "gpio.h"

#include "driver/key.h"
#include "driver/uart.h"
#include "noduino.h"

#include "app.h"

#include "mjyun.h"
#include "cJSON.h"

#define	DEBUG			1

#ifdef DEBUG
#define INFO( format, ... ) os_printf( format, ## __VA_ARGS__ )
#else
#define INFO( format, ... )
#endif

#define	XKEY_NUM		1

#define XKEY_IO_MUX		PERIPHS_IO_MUX_GPIO5_U
#define XKEY_IO_NUM		5
#define XKEY_IO_FUNC	FUNC_GPIO5

// NOTICE: --- For 1024KB spi flash
// 0xFA000
#define PARAM_START_SEC		0xFA

void xkey_init();

void relay_all_on();
void relay_all_off();
void relay_init();
void relay_set_status(relay_status_t *st);
void relay_get_status(relay_status_t *st);

void led_init();
void wifi_led_enable();
void wifi_led_disable();

#endif
