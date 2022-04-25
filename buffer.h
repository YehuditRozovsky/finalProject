#pragma once
class buffer
{
	char ** buffer;
public:
	 void addToBuffer(char *);
	 char** getBuffer();
	 void cleanBuffer(); 
};

