#include "usartMTSP.h"

//           ?????? ?????? ????????? ???????
//----------------------------------------------------
#define START_BYTE_INDEX                             0
#define SLAVE_ADD_INDEX                              1
#define MESSAGE_LENGTH_INDEX                         2
#define COMMAND_NUMBER_INDEX                         3
//----------------------------------------------------

class MTSP
{
	public:
		MTSP(int baudRate, uint8_t startByte, uint8_t address);
		
		
	private:
		void ParseMessage(uint8_t dataByte);
		void SendAnswer();
};