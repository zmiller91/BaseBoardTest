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
#include <stdio.h>
#include "mcc_generated_files/system/config_bits.h"

void task(void) {
    log_debug("Hello from the application!");
    lora_enable();
    LED_Toggle();
}

int main(void) {
    return run(task);   
}