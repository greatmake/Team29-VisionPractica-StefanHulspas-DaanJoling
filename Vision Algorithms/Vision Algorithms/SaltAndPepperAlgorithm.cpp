#include "stdafx.h"
#include "SaltAndPepperAlgorithm.h"


SaltAndPepperAlgorithm::SaltAndPepperAlgorithm(int percentage) : Algorithm("salt&pepper_")
{
	if (percentage >= 0 && percentage <= 100) this->percentage = percentage;
}


SaltAndPepperAlgorithm::~SaltAndPepperAlgorithm()
{
}
/* the salt and pepper algorithm will randomly spawn white or black pixels.
the percentage is picked in the gui
the algorithm will override an pixel and make it black or white*/

void SaltAndPepperAlgorithm::doAlgorithm(Image& img) {
	srand(time(NULL));
	unsigned char * rawData = img.getRawData();
	int bpp = img.getBPP();
	int height = img.getHeight();
	int width = img.getWidth();
	int pitch = img.getPitch();
	double random = 0;
	unsigned int x, y;
	for (y = 0; y < height; y++) {
		for (x = 0; x < pitch; x += bpp) {
			random = (double)rand() / (double)RAND_MAX; 
			if (random < (double)percentage / (double)100 / 2) {
				rawData[y * pitch + x + RED] = 0;
				rawData[y * pitch + x + GREEN] = 0;
				rawData[y * pitch + x + BLUE] = 0;
			}
			else if (random < (double)percentage / (double)100) {
				rawData[y * pitch + x + RED] = 255;
				rawData[y * pitch + x + GREEN] = 255;
				rawData[y * pitch + x + BLUE] = 255;
			}
		}
	}
}
