
/** 硬件IO定义 */

#define TFT_BL 7 
#define TFT_RST 20 //25

#define TFT_CS 21
#define TFT_SCK 22
#define TFT_MOSI 3 //23
#define TFT_DC 19 //24

#define TFT_SPI_INST spi0
#define TFT_SPI_BAUD 40000000

/**屏幕属性定义 */
#define SCR_W 240
#define SCR_H 240
#define SCR_R 0
#define SCR_COL_OFFSET 0
#define SCR_ROW_OFFSET 0

/**其他常量定义 */
#define LV_BUF_SIZE SCR_W * 24


/** 121 * 67 */

#define KEY_U 10
#define KEY_D 11
#define KEY_L 12
#define KEY_R 13
#define KEY_M 14
