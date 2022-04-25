#include "buffer.h"
#include <stdlib.h>
#include "baseMessage.h"
void buffer::addToBuffer(char * message) {
	static int sizeOfBuffer=0;
	this->buffer = (char**)realloc(buffer, sizeof(char*));
	this->buffer[sizeOfBuffer++] = message;
}
char** buffer::getBuffer() {
	return this->buffer;
}
void buffer::cleanBuffer() {
	if (this->buffer) {
		for (int i = 0; i < (sizeof(buffer))/sizeof(char*); i++)
		{
			free(this->buffer[i]);

		}
		free(this->buffer);
	}
}
