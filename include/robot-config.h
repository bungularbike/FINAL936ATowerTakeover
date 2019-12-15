using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Bleft;
extern motor Fleft;
extern motor Bright;
extern motor Fright;
extern motor Tray;
extern motor Lift;
extern motor ITLeft;
extern motor ITRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );