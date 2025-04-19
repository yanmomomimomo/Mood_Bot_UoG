#include "LCD_class.hpp"

LCD_class::LCD_class(uint16_t Hight, uint16_t Width, uint8_t Scan_dir)
    :   chip_(chip0), Scan_dir_(Scan_dir)
{
    // GPIO init
    line_cs_ = gpiod_chip_get_line(chip_, LCD_CS_Pin);
    if (!line_cs_) { perror("get_line_cs"); }

    line_rst_ = gpiod_chip_get_line(chip_, LCD_RST_Pin);
    if (!line_rst_) { perror("get_line_rst"); }

    line_dc_ = gpiod_chip_get_line(chip_, LCD_DC_Pin);
    if (!line_dc_) { perror("get_line_dc"); }

    line_bl_ = gpiod_chip_get_line(chip_, LCD_BL_Pin);
    if (!line_bl_) { perror("get_line_bl"); }
    
    if (!line_cs_ || !line_dc_ || !line_bl_ || !line_rst_){
        return;
    }

    if (gpiod_line_is_requested(line_cs_)) {
        gpiod_line_release(line_cs_); // 强行释放旧的
    }
    if (gpiod_line_is_requested(line_bl_)) {
        gpiod_line_release(line_bl_); // 强行释放旧的
    }
    if (gpiod_line_is_requested(line_rst_)) {
        gpiod_line_release(line_rst_); // 强行释放旧的
    }
    if (gpiod_line_is_requested(line_dc_)) {
        gpiod_line_release(line_dc_); // 强行释放旧的
    }

    if (gpiod_line_request_output(line_cs_, LCD_CON_CS, 1) < 0) {
        perror("Request CS failed");
    }
    if (gpiod_line_request_output(line_rst_, LCD_CON_RST, 1) < 0) {
        perror("Request RST failed");
    }
    if (gpiod_line_request_output(line_dc_, LCD_CON_DC, 1) < 0) {
        perror("Request DC failed");
    }
    if (gpiod_line_request_output(line_bl_, LCD_CON_BL, 1) < 0) {
        perror("Request BL failed");
    }

    gpiod_line_set_value(line_bl_, 1);
    gpiod_line_set_value(line_cs_, 1);

    // SPI init
    SPI0_Init();

    // LCD init
    LCD_1IN47_Init(Scan_dir_, *this);
    if (Scan_dir_ == HORIZONTAL)
	{
		Hight_ = Width;
		Width_ = Hight;
	}
	else
	{
		Hight_ = Hight;
		Width_ = Width;		
	}
    LCD_SetWindows(0, 0, Hight_, Width_, Scan_dir_, *this);
    LCD_BLSet(1);
}

LCD_class::~LCD_class(){
    gpiod_line_set_value(line_bl_, 0);
    gpiod_line_set_value(line_cs_, 0);
    gpiod_line_set_value(line_rst_, 0);
    gpiod_line_set_value(line_dc_, 0);

    gpiod_line_release(line_bl_);
    gpiod_line_release(line_cs_);
    gpiod_line_release(line_rst_);
    gpiod_line_release(line_dc_);

    DEV_Exit();
}

struct gpiod_line* LCD_class:: Getline(uint8_t i){
    switch (i)
    {
    case 1:
        /* code */
        return line_cs_;
    case 2:
        return line_dc_;
    case 3:
        return line_rst_;
    case 4:
        return line_bl_;
    }
    return nullptr;
}

void LCD_class::LCD_CSSet(uint8_t value){
    Digital_Write(line_cs_, value);
}

void LCD_class::LCD_BLSet(uint8_t value){
    Digital_Write(line_bl_, value);
}

void LCD_class::LCD_RSTSet(uint8_t value){
    Digital_Write(line_rst_, value);
}

void LCD_class::LCD_DCSet(uint8_t value){
    Digital_Write(line_dc_, value);
}

void LCD_class::LCD_SendCommand(uint8_t Reg)
{
    // // LCD_DC_0;
    // Digital_Write(line_dc_, 0);
	// // LCD_1IN47_CS_0;
	// SPI_WriteByte(Reg);
	// // LCD_1IN47_CS_1;
    // printf("SendCommand: 0x%02X\n", Reg); // ✅ 确认运行到此处
    LCD_CSSet(0);       // 选中屏幕
    LCD_DCSet(0);       // 命令模式
    SPI_WriteByte(Reg); // 发命令
    LCD_CSSet(1);       // 释放屏幕
}

void LCD_class::LCD_SendData_8Bit(uint8_t Data)
{
	// // LCD_DC_1;
    // Digital_Write(line_dc_, 1);
	// // LCD_1IN47_CS_0;
	// SPI_WriteByte(Data);
	// // LCD_1IN47_CS_1;
    LCD_CSSet(0);
    LCD_DCSet(1);       // 数据模式
    SPI_WriteByte(Data);
    LCD_CSSet(1);
}

void LCD_class::LCD_SendData_16Bit(uint16_t Data)
{
	// // LCD_DC_1;
    // Digital_Write(line_dc_, 1);
	// // LCD_1IN47_CS_0;
	// SPI_WriteByte(Data >> 8);
	// SPI_WriteByte(Data);
	// // LCD_1IN47_CS_1;
    // printf("Sending pixel data: %04X\n", Data);
    LCD_CSSet(0);
    LCD_DCSet(1);
    SPI_WriteByte(Data & 0xFF);
    SPI_WriteByte(Data >> 8);
    LCD_CSSet(1);
}

void LCD_class::LCD_Clear(uint16_t Color)
{
	uint16_t j;
	uint16_t Image[LCD_1IN47_WIDTH * LCD_1IN47_HEIGHT];

	Color = ((Color << 8) & 0xff00) | (Color >> 8);
	for (j = 0; j < LCD_1IN47_HEIGHT * LCD_1IN47_WIDTH; j++)
	{
		Image[j] = Color;
	}

	LCD_SetWindows(0, 0, Hight_, Width_, Scan_dir_, *this);
	Digital_Write(line_dc_, 1);
	for (j = 0; j < Width_; j++)
	{
		SPI_Write_nByte((uint8_t *)&Image[j * Hight_], Hight_ * 2);
	}
}

void LCD_class::LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
    // uint16_t x_real = x;

    // // 设置列地址
    // LCD_SendCommand(0x2A);
    // LCD_SendData_8Bit(x_real >> 8);
    // LCD_SendData_8Bit(x_real & 0xFF);
    // LCD_SendData_8Bit(x_real >> 8);
    // LCD_SendData_8Bit(x_real & 0xFF);

    // // 设置行地址
    // LCD_SendCommand(0x2B);
    // LCD_SendData_8Bit(y >> 8);
    // LCD_SendData_8Bit(y & 0xFF);
    // LCD_SendData_8Bit(y >> 8);
    // LCD_SendData_8Bit(y & 0xFF);

    // // 写入像素
    // LCD_SetWindows(x, y, x+1, y+1, Scan_dir_, *this);
    // LCD_SendCommand(0x2C);
    // LCD_SendData_16Bit(color);
    LCD_SetWindows(x, y, x+1, y+1, Scan_dir_, *this);  // 设置地址（已加偏移）
    LCD_SendCommand(0x2C);
    LCD_SendData_16Bit(color);                         // 写入一个像素
}

void LCD_class::Test_FillScreen(uint16_t color)
{
    int total_pixels = Hight_ * Width_;
    int buffer_len = total_pixels * 2;  // 每个像素两个字节（RGB565）

    std::vector<uint8_t> buffer(buffer_len);

    uint8_t high = color >> 8;
    uint8_t low  = color & 0xFF;

    // 填充缓冲区（高位在前）
    for (int i = 0; i < buffer_len; i += 2) {
        buffer[i] = high;
        buffer[i + 1] = low;
    }

    LCD_SetWindows(0, 0, Hight_, Width_, Scan_dir_, *this);
    LCD_SendCommand(0x2C);

    LCD_CSSet(0);
    LCD_DCSet(1);  // 数据模式

    SPI_Write_nByte(buffer.data(), buffer_len);

    LCD_CSSet(1);
}

void LCD_class::LCD_DisplayImage(const uint16_t image[172 * 320]) {
    LCD_SetWindows(0, 0, Hight_, Width_, Scan_dir_, *this);
    LCD_SendCommand(0x2C);

    LCD_CSSet(0);
    LCD_DCSet(1);  // 数据模式

    // 模拟和 LCD_Clear 一样的列优先方式
    for (uint16_t x = 0; x < Width_; x++) {
        std::vector<uint8_t> column(Hight_ * 2);
        for (uint16_t y = 0; y < Hight_; y++) {
            uint16_t color = image[y * Width_ + x];  // 注意 y 行 x 列访问
            column[y * 2]     = color >> 8;          // 高位在前
            column[y * 2 + 1] = color & 0xFF;
        }
        SPI_Write_nByte(column.data(), column.size());
    }

    LCD_CSSet(1);
}

