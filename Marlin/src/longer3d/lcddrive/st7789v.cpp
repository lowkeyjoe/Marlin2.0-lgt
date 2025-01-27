#include "lcdio.h"

#if ENABLED(LGT_LCD_TFT)
#include "st7789v.h"

void ST7789V_Init(void) {
//   TOUCH_LCD_IO_Init();

  /* Sleep In Command */
  LCD_IO_WriteReg(ST7789V_SLEEP_IN);
  /* Wait for 10ms */
  LCD_Delay(10);

  /* SW Reset Command */
  LCD_IO_WriteReg(ST7789V_SWRESET);
  /* Wait for 200ms */
  LCD_Delay(200);

  /* Sleep Out Command */
  LCD_IO_WriteReg(ST7789V_SLEEP_OUT);
  /* Wait for 120ms */
  LCD_Delay(120);

  /* Normal display for Driver Down side */
  LCD_IO_WriteReg(ST7789V_NORMAL_DISPLAY);
  LCD_IO_WriteData(0xA0);
  //LCD_IO_WriteData(0xA0);

  /* Color mode 16bits/pixel */
  LCD_IO_WriteReg(ST7789V_COLOR_MODE);
  LCD_IO_WriteData(0x55);

  /* Set Column address CASET */
  LCD_IO_WriteReg(ST7789V_CASET);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0x01);
  LCD_IO_WriteData(0x3F);
  /* Set Row address RASET */
  LCD_IO_WriteReg(ST7789V_RASET);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0xEF);

  /* PORCH control setting */
  LCD_IO_WriteReg(ST7789V_PORCH_CTRL);
  LCD_IO_WriteData(0x0C);
  LCD_IO_WriteData(0x0C);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0x33);
  LCD_IO_WriteData(0x33);

  /* GATE control setting */
  LCD_IO_WriteReg(ST7789V_GATE_CTRL);
  LCD_IO_WriteData(0x35);

  /* VCOM setting */
  LCD_IO_WriteReg(ST7789V_VCOM_SET);
  LCD_IO_WriteData(0x1F);

  /* LCM Control setting */
  LCD_IO_WriteReg(ST7789V_LCM_CTRL);
  LCD_IO_WriteData(0x2C);

  /* VDV and VRH Command Enable */
  LCD_IO_WriteReg(ST7789V_VDV_VRH_EN);
  LCD_IO_WriteData(0x01);
  LCD_IO_WriteData(0xC3);

  /* VDV Set */
  LCD_IO_WriteReg(ST7789V_VDV_SET);
  LCD_IO_WriteData(0x20);

  /* Frame Rate Control in normal mode */
  LCD_IO_WriteReg(ST7789V_FR_CTRL);
  LCD_IO_WriteData(0x0F);

  /* Power Control */
  LCD_IO_WriteReg(ST7789V_POWER_CTRL);

  //Values to be spyed on the LA.
  //LCD_IO_WriteData(0xA4);
  //LCD_IO_WriteData(0xA1);

  /* Display ON command */
  ST7789V_DisplayOn();
}

void ST7789V_DisplayOn(void) {
  /* Display ON command */
  LCD_IO_WriteReg(ST7789V_DISPLAY_ON);

  /* Sleep Out command */
  LCD_IO_WriteReg(ST7789V_SLEEP_OUT);
}

void ST7789V_WriteRam() {
  LCD_IO_WriteReg(ST7789V_WRITE_RAM);
}

void ST7789V_SetCursor(uint16_t Xpos, uint16_t Ypos) {
  /* CASET: Comumn Addrses Set */
  LCD_IO_WriteReg(ST7789V_CASET);
  LCD_IO_WriteData((Xpos >> 8) & 0xFF);
  LCD_IO_WriteData(Xpos & 0xFF);
  LCD_IO_WriteData(0x01);
  LCD_IO_WriteData(0x3F);

  /* RASET: Row Addrses Set */
  LCD_IO_WriteReg(ST7789V_RASET);
  LCD_IO_WriteData((Ypos >> 8) & 0xFF);
  LCD_IO_WriteData(Ypos & 0xFF);
  LCD_IO_WriteData(0x00);
  LCD_IO_WriteData(0xEF);

  LCD_IO_WriteReg(ST7789V_WRITE_RAM);
}

void ST7789V_SetWindow(uint16_t Xmin, uint16_t Ymin, uint16_t Xmax, uint16_t Ymax) {
  /* CASET: Comumn Addrses Set */
  LCD_IO_WriteReg(ST7789V_CASET);
  LCD_IO_WriteData((Xmin >> 8) & 0xFF);
  LCD_IO_WriteData(Xmin & 0xFF);
  LCD_IO_WriteData((Xmax >> 8) & 0xFF);
  LCD_IO_WriteData(Xmax & 0xFF);

  /* RASET: Row Addrses Set */
  LCD_IO_WriteReg(ST7789V_RASET);
  LCD_IO_WriteData((Ymin >> 8) & 0xFF);
  LCD_IO_WriteData(Ymin & 0xFF);
  LCD_IO_WriteData((Ymax >> 8) & 0xFF);
  LCD_IO_WriteData(Ymax & 0xFF);

  LCD_IO_WriteReg(ST7789V_WRITE_RAM);
}

#endif
