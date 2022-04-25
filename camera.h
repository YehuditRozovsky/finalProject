#pragma once
#include "discoverMessage.h"
#include "statusMessage.h"
#include "buffer.h"
class camera
{
	char cameraId;
	baseMessage ** bufferArray;
	buffer buffer;
	bool isActive;
public:
	void generate();
	void sendToBuffer();
	statusMessage* createStatusMessage();
	discoverMessage* createDiscoverMessage();
	void run();
	void stop();
};

