/*
 *	stts751.h - Digital temperature sensor STTS751 control library
 *
 */
 
#ifndef	_STTS751_H_ 
#define	_STTS751_H_

class STTS751 {
  public:
	void begin(void);
	int getTemperature(void);
};

#endif // _STTS_751_h_
