/*
  93C46.h - Library for the 93C46 EEPROM chip in 64x16 mode
  Created by Joey Haas, Juli 7, 2018
  Released under the GNU General Public License v3.0
*/
#ifndef _93C46_h
#define _93C46_h

#include "Arduino.h"

#define EEPROM_93C46_MODE_8BIT 0
#define EEPROM_93C46_MODE_16BIT 1

class eeprom_93C46 {
  public:
  	eeprom_93C46(int pCS, int pSK, int pDI, int pDO);
    void set_mode(bool longMode);
  	void ew_disable();
  	void ew_enable();
  	bool is_ew_enabled();
  	void erase_all();
  	void write_all(word value);
  	void write(byte addr, word value);
  	void erase(byte addr);
    word read(byte addr);
  private:
  	void send_bits(word value, int len);
  	void wait();
  	int _pCS;
  	int _pSK;
  	int _pDI;
  	int _pDO;
  	bool _ew;
    bool _mode;
};

#endif
