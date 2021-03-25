#include "app.h"
/* servo configuration structure
initialized in appInit.c */

extern CfgServo_t servoConfg;

extern CfgStepperL6470_t stepperConfg[2];

int main()
{
	PFEnStatus_t status;
	DevId_t devId[2]={0};
	PFEnBoolean_t readyStat;
	DevId_t devId2=0;
	appInit();
	servoOpen(&devId2, &servoConfg, 1);
	stepper_SmartlynxOpen(devId,stepperConfg, 2);
	
		do
		{
			status =stepperIsDeviceReady(devId[0],&readyStat);
			if(status != enStatusSuccess)
				DEBUG_WRITE("\r\nDevice status read failed");
			}while( !readyStat );	
		pfDelayMilliSec(2000);	
		status = servoMove(devId2, 0);
		pfDelayMilliSec(2000);	
		
		while(1)
		{
		/* stepperMove(1, 0, 755, 1000.0);	
		pfDelayMilliSec(2000);				
		stepperMove(0, 1, 257, 800.0);
		pfDelayMilliSec(2000);
		status = servoMove(devId2, 110);	 
		}
		stepperMove(1, 0, 755, 1000.0);	
		pfDelayMilliSec(2000);				
		stepperMove(0, 1, 257, 800.0);
		pfDelayMilliSec(2000);
		status = servoMove(devId2, 110); */
		stepperMove(1, 0, 257, 1000.0);	
		pfDelayMilliSec(2000);				
		status = servoMove(devId2, 110);
		pfDelayMilliSec(2000);
		status = servoMove(devId2, 0);
		/* stepperMove(0, 1, 257, 800.0);
		pfDelayMilliSec(2000);  */
		}
}