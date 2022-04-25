#include "camera.h"
#include <random>
static int indexBuffer = 0;
static int index = 0;
void camera::generate() {
	for ( int i = 0;  i < 6;  i++)
	{	
		baseMessage* message;
		int type = rand() % 2 + 1;
		if (type == 1) {
			statusMessage* message = createStatusMessage();
		}
		else {
			discoverMessage* message = createDiscoverMessage();
		}
		this->bufferArray = (baseMessage**)realloc(bufferArray, sizeof(message));
		this->bufferArray[index++] = message;
	}
}
statusMessage* camera::createStatusMessage()
{
	static int id = 1;
	id++;
	statusMessage* sm = new statusMessage(id, 1, rand() % 3 + 1);
	return sm;
}
discoverMessage* camera::createDiscoverMessage()
{
	static int id = 100;
	id++;
	discoverMessage* dm = new discoverMessage(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	return dm;
}
void camera::sendToBuffer() {
	for (int i = 0; i <index; i++)
	{
		bufferArray[i]->parseBack();
		buffer.addToBuffer((char *)(bufferArray[i]->getMessageBuffer()));
		free(bufferArray[i]);
	}
	free(bufferArray);
}
void camera::run() {
	while (isActive) {
		for (int i = 0; i < 5; i++)
		{
			generate();
		}
		sendToBuffer();
	}
}
void camera::stop() {
	isActive = false;
}
