#include "Sound.h"

void arrowKeySound() {}
void enterKeySound() {
	PlaySound(TEXT("confirm-38513.wav"), NULL, SND_FILENAME);
}
void winSound() {
	PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME);
}
void gameOverSound() {
	PlaySound(TEXT("game-over-38511.wav"), NULL, SND_FILENAME);
}
void rightPairSound() {
	PlaySound(TEXT("sound-fx-mario-coin_D_major.wav"), NULL, SND_FILENAME);
}
void wrongPairSound() {
	PlaySound(TEXT("8 bit uh oh sound.wav"), NULL, SND_FILENAME);
}	