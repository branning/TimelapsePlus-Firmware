#define LIGHT_TRIGGER_MODE_ANY 0xFF
#define LIGHT_TRIGGER_MODE_RISE 0x01
#define LIGHT_TRIGGER_MODE_FALL 0x02

volatile char firmwareUpdated(char key, char first);
volatile char firstSetup(char key, char first);
volatile char timerRevert(char key, char first);
volatile char timerSaveCurrent(char key, char first);
volatile char timerSaveDefault(char key, char first);
volatile char timerStatus(char key, char first);
volatile char timerStatusRemote(char key, char first);
void displayTimerStatus(uint8_t remote_system);
volatile char timerRemoteStart(char key, char first);
volatile char menuBack(char key, char first);
volatile char factoryReset(char key, char first);
volatile char timerStop(char key, char first);
volatile char runHandler(char key, char first);
volatile char lightMeter(char key, char first);
volatile char batteryStatus(char key, char first);
volatile char memoryFree(char key, char first);
volatile char IRremote(char key, char first);
volatile char sysInfo(char key, char first);
volatile char sysStatus(char key, char first);
volatile char cableRelease(char key, char first);
volatile char cableReleaseRemote(char key, char first);
volatile char shutterTest(char key, char first);
volatile char autoConfigureCameraTiming(char key, char first);
volatile char lcd_white(char key, char first);
volatile char lcd_red(char key, char first);
volatile char btConnect(char key, char first);
volatile char usbPlug(char key, char first);
volatile char shutter_saveAs(char key, char first);
volatile char shutter_load(char key, char first);
volatile char shutter_delete(char key, char first);
volatile char shutter_rename(char key, char first);
volatile char lightningTrigger(char key, char first);
volatile char motionTrigger(char key, char first);
volatile char bramp_monitor(char key, char first);
volatile char videoRemote(char key, char first);
volatile char videoRemoteBT(char key, char first);
volatile char system_name(char key, char first);
volatile char focusStack(char key, char first);
volatile char lightTrigger(char key, char first);
volatile char backToMain(char key, char first);
volatile char timerToGuided(char key, char first);
volatile char timerToAuto(char key, char first);
volatile char flattenKeyframes(char key, char first);
volatile char gotoStart(char key, char first);

void int_to_str(uint16_t n, char buf[6]);
void updateConditions();
