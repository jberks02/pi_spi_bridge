#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <spidev_lib++.h>
#include <chrono>
#include <thread>
using namespace std;

spi_config_t spi_config;
uint8_t tx_buffer[32];
uint8_t rx_buffer[32];
uint8_t tr_rx_buff[1];
uint8_t tr_tx_buff[1];

int main(void)
{
    SPI *mySPI = NULL;
    spi_config.mode = 0;
    // spi_config.speed = 100000000;
    spi_config.speed = 1000000;
    // spi_config.speed = 500000;
    spi_config.delay = 0;
    spi_config.bits_per_word = 8;
    
    mySPI = new SPI("/dev/spidev0.0", &spi_config);

    cout << "at if" << "\n";
    
    if (mySPI->begin())
    {
        cout << "under if" << "\n";
        // while(true) {
            memset(tx_buffer, 0, 32);
            memset(rx_buffer, 0, 32);
            sprintf((char *)tx_buffer, "I am pi");
            
            for(int i = 0; i < 32;i++) {

                tr_tx_buff[0] = tx_buffer[i];

                mySPI->xfer(tr_tx_buff, 1, tr_rx_buff, 1);

                rx_buffer[i] = tr_rx_buff[0];

            };
            printf("rx_buffer=%s\n", (char *)rx_buffer);
            for(int i = 0;i < 32; i++) {
                cout << rx_buffer[i];
            }
            cout << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        delete mySPI;
    }
    return 1;
}