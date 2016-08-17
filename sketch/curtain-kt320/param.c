/*
 *  Copyright (c) 2015 - 2025 MaiKe Labs
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/
#include "user_config.h"

struct dooya_saved_param {
	int status;
	int position;
};

LOCAL struct dooya_saved_param dooya_param;

int param_get_status(void)
{
	return dooya_param.status;
}

int param_get_position(void)
{
	return dooya_param.position;
}

void param_set_status(int st)
{
	dooya_param.status = st;
}

void param_set_position(int pos)
{
	dooya_param.position = pos;
}

void ICACHE_FLASH_ATTR param_save(void)
{
	spi_flash_erase_sector(PARAM_START_SEC + 0);
	spi_flash_write((PARAM_START_SEC + 0) * SPI_FLASH_SEC_SIZE,
			(uint32 *) & dooya_param,
			sizeof(struct dooya_saved_param));
}

void ICACHE_FLASH_ATTR param_init()
{
	spi_flash_read((PARAM_START_SEC + 0) * SPI_FLASH_SEC_SIZE,
		       (uint32 *) & dooya_param,
		       sizeof(struct dooya_saved_param));

	// init data of spi flash
	if (dooya_param.status == 0xff) {
		INFO("Invalid status value, reset to 0!\n");
		dooya_param.status = 0;
	}
	if (dooya_param.position == 0xff) {
		INFO("Invalid position value, reset to 0!\n");
		dooya_param.position = 0;
	}

	INFO("Saved Status is: %d\n", param_get_status());
	INFO("Saved Position is: %d\n", param_get_position());
}
