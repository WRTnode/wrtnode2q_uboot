#ifndef _NET_HTTPD_H__
#define _NET_HTTPD_H__


#undef CONFIG_LOADADDR
#define CONFIG_LOADADDR						0x80800000
#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES		(320 * 1024)
#define milisecdelay(_x)					udelay((_x) * 1000)

/*
 * Web Failsafe configuration
 */
#define WEBFAILSAFE_UPLOAD_RAM_ADDRESS				CONFIG_LOADADDR

// U-Boot partition size and offset
#define WEBFAILSAFE_UPLOAD_UBOOT_ADDRESS			CFG_FLASH_BASE
#define WEBFAILSAFE_UPLOAD_UBOOT_SIZE_IN_BYTES			(192 * 1024)

#define WEBFAILSAFE_UPLOAD_ART_SIZE_IN_BYTES			(64 * 1024)
#define WEBFAILSAFE_UPLOAD_ART_ADDRESS				WEBFAILSAFE_UPLOAD_UBOOT_ADDRESS + 0x40000

#define WEBFAILSAFE_UPLOAD_KERNEL_ADDRESS			WEBFAILSAFE_UPLOAD_UBOOT_ADDRESS + 0x50000

// progress state info
#define WEBFAILSAFE_PROGRESS_START			0
#define WEBFAILSAFE_PROGRESS_TIMEOUT			1
#define WEBFAILSAFE_PROGRESS_UPLOAD_READY		2
#define WEBFAILSAFE_PROGRESS_UPGRADE_READY		3
#define WEBFAILSAFE_PROGRESS_UPGRADE_FAILED		4

// update type
#define WEBFAILSAFE_UPGRADE_TYPE_FIRMWARE		0
#define WEBFAILSAFE_UPGRADE_TYPE_UBOOT			1
#define WEBFAILSAFE_UPGRADE_TYPE_ART			2

void HttpdStart(void);
void HttpdHandler(void);

/* board specific implementation */
extern int do_http_upgrade(const ulong size, const int upgrade_type);
extern int do_http_progress(const int state);
extern void all_led_on(void);
extern void all_led_off(void);

#endif
