
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes
CONSOLE_ENABLE = yes
EXTRAKEY_ENABLE = yes

WPM_ENABLE = yes

RAW_ENABLE = yes            # Enable RAW HID communication to PC

Link_Time_Optimization = yes # Reduce size of firmware by optimizing at link time
EXTRAFLAGS += -flto

SRC +=  ./glcdfont.c
