#include "simulator.h"
using namespace std;
#include <iostream>
statusMessage* simulator::createStatusMessage()
{
	static int id = 1;
	id++;
	statusMessage* sm = new statusMessage(id, 1, rand() % 3 + 1);
	return sm;
}

discoverMessage* simulator::createDiscoverMessage()
{
	static int id = 100;
	id++;
	discoverMessage* dm = new discoverMessage(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	return dm;
}

void simulator::generateAndSendMessage()
{
	for (int i = 0; i < 10; i++)
	{
		(rand() % 2 + 1 == 1) ? buffer[i] = createStatusMessage() : buffer[i] = createDiscoverMessage();
		buffer[i]->print();
	}
	for (int i = 0; i < 10; i++)
	{
		buffer[i]->parseBack();
		buffer[i]->parseMessage();
		buffer[i]->print();
		buffer[i]->~baseMessage();
	}
}

simulator::simulator()
{
	char ch;
	cameraArray = (camera**)malloc(sizeof(camera) * 3);
	for (int i = 0; i < 3; i++) {
		cameraArray[i] = new camera();
    }
	cameraRun();
	cout << "for stop press 1";
	cin >> ch;
	if (ch == '1') {
		for (int i = 0; i < 3; i++)
		{
			cameraArray[i]->stop();
		}
	}
}

void simulator::cameraRun()
{
	thread *threads = (thread*)malloc(sizeof(thread*)*3);
	for (int i = 0; i < 3; i++)
	{
		threads[i]=thread(&camera::run, cameraArray[i],i);
	}

}
