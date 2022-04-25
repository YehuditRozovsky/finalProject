#pragma once
#include "baseMessage.h"
#include <stdlib.h>
#include "statusMessage.h"
#include "discoverMessage.h"
#include "camera.h"
#include <thread>
using namespace std;
class simulator
{
protected:
	baseMessage* buffer[10];
	camera** cameraArray;
public:
	statusMessage* createStatusMessage();
	discoverMessage* createDiscoverMessage();
	void generateAndSendMessage();
	simulator();
	void cameraRun();
};

