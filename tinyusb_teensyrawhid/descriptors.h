#ifndef TOD_HID_DESCRIPTORS_H
#define TOD_HID_DESCRIPTORS_H

#define MODE_STR "TEENSY"
#define MODE_INFO "Responds to IN/OUT reports w/ no ReportIDs"
#define MYVID 0x16C0
#define MYPID 0x0486
#define RAWHID_TXRX_SIZE   64
#define RAWHID_USAGE_PAGE  0xFFAB
#define RAWHID_USAGE       0x0200
#define LSB(n) ((n) & 255)
#define MSB(n) (((n) >> 8) & 255)
#define HID_DESC HID_DESC_TEENSY_RAWHID( RAWHID_TXRX_SIZE )


#define HID_DESC_TEENSY_RAWHID(report_size,...) \
    0x06, LSB(RAWHID_USAGE_PAGE), MSB(RAWHID_USAGE_PAGE), \
    0x0A, LSB(RAWHID_USAGE), MSB(RAWHID_USAGE), \
    0xA1, 0x01,                     /* Collection 0x01 */ \
    0x75, 0x08,                     /* report size = 8 bits */ \
    0x15, 0x00,                     /* logical minimum = 0 */ \
    0x26, 0xFF, 0x00,               /* logical maximum = 255  */ \
    0x95, report_size,              /* report count */ \
    0x09, 0x01,                     /* usage */ \
    0x81, 0x02,                     /* Input (array) */ \
    0x95, report_size,              /* report count */ \
    0x09, 0x02,                     /* usage */ \
    0x91, 0x02,                     /* Output (array) */ \
    0xC0                            /* end collection */ \


#endif // TOD_HID_DESCRIPTORS_H
