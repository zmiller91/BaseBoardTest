/**
 * A few things to note here: 
 * 
 * 1. This file must contain the config bits from MCC
 * 2. Otherwise this file delegates the configuration to the BaseBoardCore package
 * 
 * In order to link the two, you'll need to:
 * 
 * 1. Right Click "Libraries" and add the BaseBoardCore.x library
 * 2. Go to Properties -> XC8 Compiler -> Include Directories and add the 
 *    BaseBoardCore.x library
 * 
 */


#include "run.h"
#include "log.h"
#include "lora.h"
#include "string_utils.h"
#include <stdio.h>
#include <stdint.h>
#include "mcc_generated_files/system/config_bits.h"




void task(void) {
    
    char addr_txt[6];
    

    char buff1[] = "AT+SEND=";
    char buff2[5];
    uint16_to_str(buff2, 5, 1);
    char buff3[] = "\r\n";

    char out[50];
    char *parts[] = { buff1, buff2, buff3 };
    join_buffers(parts, 3, out, 50);
    log_debug(out);
    
    
    
    LED_EN_SetHigh();
    log_debug("Hello from the application!");
    lora_enable();
    
    int32_t data[] = {12347};
    lora_send(32, data, 1);
    
    LED_EN_SetLow();
    set_sleep_period(FIFTEEN_SECONDS);
}

int main(void) {
    return run(task);   
}