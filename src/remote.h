#define REMOTE_VERSION 20121130

#define REMOTE_STATUS 1
#define REMOTE_PROGRAM 2
#define REMOTE_START 3
#define REMOTE_STOP 4
#define REMOTE_BATTERY 5
#define REMOTE_BULB_START 6
#define REMOTE_BULB_END 7
#define REMOTE_CAPTURE 8

#define REMOTE_FIRMWARE 11
#define REMOTE_BT_FW_VERSION 12
#define REMOTE_PROTOCOL_VERSION 13
#define REMOTE_CAMERA_FPS 14
#define REMOTE_CAMERA_MAKE 15

#define REMOTE_TYPE_SEND 0
#define REMOTE_TYPE_REQUEST 1
#define REMOTE_TYPE_SET 2
#define REMOTE_TYPE_NOTIFY_SET 3
#define REMOTE_TYPE_NOTIFY_UNSET 4

class Remote
{
public:
    Remote(void);
    uint8_t request(uint8_t id);
    uint8_t set(uint8_t id);
    uint8_t send(uint8_t id, uint8_t type);
    void event(void);

    uint8_t connected;
    uint8_t running;
    uint8_t battery;

    uint8_t notifyBattery;
    uint8_t notifyCameraFPS;
    uint8_t notifyCameraMake;

    timer_status status;
    program current;

private:
	volatile uint8_t requestActive;
};