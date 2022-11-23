/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 100
CAN can1(PB_8, PB_9, 500000);

unsigned int txID = 1337;
CANMessage txMsg;
CANMessage rxMsg;
void printMessage(CANMessage msg);

int main() {

  while (true) {
   
    if (can1.read(rxMsg)) {
      printMessage(rxMsg);
    }
    thread_sleep_for(WAIT_TIME_MS);
  }
}

void printMessage(CANMessage msg) {
  printf("Message received with id %X and length %d with data:", msg.id,
         msg.len);
  for (int i = 0; i < msg.len; i++) {
    printf(" %X", msg.data[i]);
  }
  printf("\n");
}
